#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
#include <fstream>
using namespace std;

// 紀錄留言用格式
struct to_leave {
    long long leave_id;  // 每則留言的編號
    string people;    // 留言者
    string says;      // 留言本文
    long long time;   // 時間
};

// 記錄貼文用格式
struct toget {
    long long po_id;              // 每篇 po 文自己的編號
    string people;                // 貼文者
    string picture;               // 附圖
    string pic_add;               // 圖片註解
    long long time;               // 貼文時間
    queue<string> great = {};     // 按讚
    queue<to_leave> message = {}; // 紀錄留言
    long long mes_max_id;         // 最後的留言編號
};



void do_hint();                      // 操作提示
void read_old_po(stack<toget>&, long long&); // 讀取曾經貼過的貼文紀錄
void new_po(stack<toget>&, long long&);      // 貼新貼文用
void print_po(stack<toget>);         // 顯示貼文
void count_great(queue<string>);     // 數讚數函式
void leave_message(queue<to_leave>); // 顯示留言函式

long long strNum_2_longNum(string);  // 文字數字轉整數數字
int print_delta_time(long long);     // 顯示時間差

void to_remember(stack<toget>);      // 存檔用
void get_great(queue<string>&, string);  // 讀取按讚函式
void give_take_great(stack<toget>&, long long); // 給予按讚 and 取消按讚函式

void to_leave_message(stack<toget>&, long long); // 留言函式



//人、圖片、圖片說明、時間 (可加按讚，留言 -> 新上舊下)
//0結束

/*
+  按讚
*  留言
-1 結束程式
0 查看貼文
1 儲存文字檔
2 貼新貼文
*/

int main() {
    stack<toget> lines = {}; // 紀錄基本貼文
    long long last_po_id;
    read_old_po(lines, last_po_id); // 讀取舊 PO 文

    string mode = "0"; // 預設讀取模式

    do {
        if (mode == "0") {
            print_po(lines); //開始顯示 PO 文
            cout << "\n";
            do_hint();
            cin >> mode;
        }else if (mode == "1") { // 儲存文字檔
            to_remember(lines);
            mode = "0";

        }else if (mode == "2") {
            new_po(lines, last_po_id); // 開始輸入新 PO 文
            mode = "0";

        } else if (mode[0] == '+') { // 按讚
            give_take_great(lines, strNum_2_longNum(mode)); // 按讚函式
            mode = "0";

        } else if (mode[0] == '*') { // 留言
            to_leave_message(lines, strNum_2_longNum(mode)); // 留言函式
            mode = "0";

        } else {
            mode = "-1";

        }
    } while (mode != "-1");

    system("clear");
    to_remember(lines);
    cout << "儲存完畢!!\n";
    cout << "感謝您，歡迎再次使用 O.-\n";

}



// 操作提示
void do_hint()
{   
    cout << "0. 查看貼文\n";
    cout << "1. 儲存紀錄\n";
    cout << "2. 發新貼文\n";
    cout << "輸入 '+貼文編號' 即可按讚或取消按讚 (eg: +5)\n";
    cout << "輸入 '*貼文編號' 即可留言~~ (eg: *2)\n";
    cout << "輸入 '-1' 結束程式 >.<\n";
    cout << "請選擇服務代碼: ";
}


// 讀取曾經貼過的貼文紀錄 (紀錄, 最後一個貼文編號)
void read_old_po(stack<toget>& lines ,long long& last_id)
{   
    ifstream po_rem;
    po_rem.open("po_remember.txt");
    toget temp; // 暫存個貼文資料
    string the_line; // 暫存每行文字
    last_id = 0;

    while (getline(po_rem, the_line)) {
        if (the_line != "#**") continue; // 識別開頭偵測

        getline(po_rem, the_line);  // the_line 在這裡用來記錄貼文編號
        last_id = strNum_2_longNum(the_line); 
        temp.po_id = last_id;       //存取貼文編號
            
        getline(po_rem, temp.people);
        getline(po_rem, temp.picture);
        getline(po_rem, temp.pic_add);

        getline(po_rem, the_line);      // the_line 在這裡用來記錄時間
        temp.time = strNum_2_longNum(the_line); //存取時間
            
        getline(po_rem, the_line);
        get_great(temp.great, the_line); // 讀取按讚人

        //以下為記錄留言用 >.<
        temp.message = {};
        to_leave the_message; // 紀錄當前處理的留言用
        temp.mes_max_id = 0;  // 紀錄最後的留言編號

        while (getline(po_rem, the_line)) {
            if (the_line == "#--") break; // 識別結尾偵測
            if (the_line != "#++") continue; // 識別開頭偵測
            
            getline(po_rem, the_line); // the_line 在這裡用來記錄留言編號
            the_message.leave_id = strNum_2_longNum(the_line); // 紀錄留言編號
            temp.mes_max_id = the_message.leave_id; // 每次執行刷新留言編號
            
            getline(po_rem, the_message.people); // 留言者
            getline(po_rem, the_message.says);  // 內容

            getline(po_rem, the_line); // the_line 在這裡用來記錄時間
            the_message.time = strNum_2_longNum(the_line); // 存取時間

            temp.message.push(the_message); // 匯入總檔
        }
        // 以上為紀錄留言用 >.<
        
        lines.push(temp);
        
    }

    po_rem.close(); // 結束後記得關閉
}


// 貼新貼文用 (紀錄, 最後一則貼文編號)
void new_po(stack<toget>& lines, long long& last_id)
{   
    system("clear");

    fstream add_po;
    add_po.open("po_remember.txt", ios::app);
    toget temp;

    cin.ignore();
    cout << "請輸入ID (結束 PO 文請打'0'):";
    getline(cin, temp.people);
    while (temp.people != "0") {
        last_id += 1; // 新編號
        add_po << "#**\n" << last_id << '\n'; // po 文編號寫檔
        temp.po_id = last_id;

        add_po << temp.people << "\n"; // 人名寫檔

        cout << "請選擇圖片: ";
        getline(cin, temp.picture);
        add_po << temp.picture << "\n"; // 圖片寫檔

        cout << "請輸入圖片註解: ";
        getline(cin, temp.pic_add);
        add_po << temp.pic_add << "\n"; // 圖片註解寫檔

        temp.time = time(0); // 紀錄時間
        add_po << temp.time << "\n"; // 時間寫檔

        temp.great = {};
        add_po << "\n"; // 按讚預留位置

        temp.message = {};
        add_po << "\n"; // 留言預留位置

        add_po << "#--\n"; // 宣告結束
        
        temp.mes_max_id = 0;
        lines.push(temp);

        cout << "請輸入帳號名稱(停止輸入請打'0'):";
        getline(cin, temp.people); // 結尾重新輸入新值
    }

    add_po.close(); // 結束後記得關閉
}


// 顯示貼文
void print_po(stack<toget> lines) 
{   
    toget temp;
    system("clear");

    int now_time = time(0);
    while (!lines.empty()) {
        temp = lines.top(); // 每筆資料暫存
        cout << "(" << temp.po_id << ")" << endl;
        lines.pop();
        cout << "名稱: " << temp.people << endl;
        cout << "圖片: " << temp.picture << endl;
        cout << "圖片註解: " << temp.pic_add << endl;
        cout << "時間: ";
        print_delta_time(temp.time);

        // 時間可以寫函示

        cout << "\n";
        count_great(temp.great); // 用函式數讚數
        cout << "\n留言:\n";
        leave_message(temp.message); // 用函式顯示留言

        if (!lines.empty()) {
            cout << "========================================" 
                << endl << endl; 
        }
    }
}


// 存檔函式
void to_remember(stack<toget> old_lines)
{   
    stack<toget> lines = {};
    toget temp;

    while (!old_lines.empty()) { // 因為stack讀取資料方式是先入後出，所以在此做一次反轉
        temp = old_lines.top();
        lines.push(temp);
        old_lines.pop();
    }

    fstream to_rem;
    to_rem.open("po_remember.txt", ios::out); // 先清空原檔然後寫入

    while (!lines.empty()) {
        temp = lines.top();
        lines.pop();

        to_rem << "#**\n";
        to_rem << temp.po_id << "\n";
        to_rem << temp.people << "\n";
        to_rem << temp.picture << "\n";
        to_rem << temp.pic_add << "\n";
        to_rem << temp.time << "\n";
        // 按讚
        string the_line;
        the_line = "";
        while (!temp.great.empty()) {
            the_line += (temp.great.front() + ",");
            temp.great.pop();
        }
        to_rem << the_line << '\n'; 

        // 留言
        to_leave the_message;
        while (!temp.message.empty()) {
            the_message = temp.message.front();
            temp.message.pop();

            to_rem << "#++\n";
            to_rem << the_message.leave_id << "\n";
            to_rem << the_message.people << "\n";
            to_rem << the_message.says << "\n";
            to_rem << the_message.time << "\n";
        }

        to_rem << "#--\n"; // 宣告結束
    }
}   


// 數讚數函式
void count_great(queue<string> great) 
{
    int num_of_great = size(great);
    string temp;

    if (num_of_great >= 3) {
        for (int i = 0; i < 2; i++) {
            temp = great.front();
            great.pop();
            cout << temp << (i == 0 ? ", " : " ");
        }
        cout << "和其他 " << num_of_great - 2 << " 人說讚" << endl;
    } else if (num_of_great == 2) {
        for (int i = 0; i < 2; i++) {
            temp = great.front();
            great.pop();
            cout << temp << (i == 0 ? " 和 " : " ");
        }
        cout << "說讚" << endl;
    } else if (num_of_great == 1) {
        temp = great.front();
        cout << temp << " 說讚" << endl;
    } else {
        cout << "目前無人說讚 QAQ" << endl;
    }
}

// 顯示留言函式
void leave_message(queue<to_leave> message)
{   
    to_leave temp; // 紀錄留言用
    while (!message.empty()) {
        temp = message.front(); // 紀錄每個留言
        message.pop();
        cout << "    " << "[" << temp.leave_id << "]" << endl;
        cout << "    名稱: " << temp.people << endl;
        cout << "    留言: " << temp.says << endl;
        cout << "    時間: ";
        print_delta_time(temp.time);
    }
}


// 文字數字轉整數數字
long long strNum_2_longNum (string str_num)
{   
    long long total = 0;
    for (auto i : str_num) {
        if (i == '+') continue;
        if (i == '*') continue;
        total *= 10;
        total += (i - '0');
    }
    return total;
}


// 顯示時間差
int print_delta_time(long long then) 
{
    long long delta = time(NULL) - then; // 最初以秒計算
    //顯示方式
    if (delta < 60) {
        cout << " " << delta << " 秒前\n";
        return 0;
    } 
    delta /= 60; // 改為分鐘計算(取整數)
    if (delta < 60) {
        cout << " " << delta << " 分鐘前\n";
        return 0;
    } 
    delta /= 60; // 改為小時計算(取整數)
    if (delta < 24) {
        cout << " " << delta << " 小時前\n";
        return 0;
    } 
    delta /= 24; // 改為天計算(取整數)
    cout << " " << delta << " 天前\n";
    return 0;
} 

// 讀取按讚函式
void get_great(queue<string>& great, string names)
{   
    string temp;
    great = {};
    temp = "";
    for (auto i : names) {
        if (i == ',') {
            great.push(temp);
            temp = "";
        } else {
            temp += i;
        }
    }
}

// 給予按讚 and 取消按讚函式
void give_take_great(stack<toget>& lines, long long id)
{   
    stack<toget> lines_rem = {};
    toget temp;
    string name;

    while (!lines.empty()) {
        temp = lines.top();
        if (temp.po_id != id) {
            lines_rem.push(temp);
            lines.pop();
            continue;
        }
        cin.ignore();
        cout << "請輸入名稱: ";
        getline(cin, name);

        queue<string> old_great = temp.great; 
        queue<string> new_great = {};
        string great_name;
        bool del = false;
        while (!old_great.empty()) { //邊向前推邊偵測是否已經按過讚
            great_name = old_great.front();
            old_great.pop();
            if (name == great_name) { // 如果隊伍中已經有這個名字就取消讚
                del = true;
                continue;
            }
            new_great.push(great_name); 
        }
        if (!del) lines.top().great.push(name); // 這部分是按讚
        else lines.top().great = new_great; // 這部分是取消

        break;
    }

    while (!lines_rem.empty()) {
        temp = lines_rem.top();
        lines.push(temp);
        lines_rem.pop();
    }
}

// 留言函式
void to_leave_message(stack<toget>& lines, long long id) {
    stack<toget> lines_rem = {};
    to_leave the_message; // 用留言 struct 形式記錄
    toget temp;
    while (!lines.empty()) {
        temp = lines.top();
        lines.pop();
        if (temp.po_id != id) {
            lines_rem.push(temp);
            continue;
        }
        cin.ignore();
        temp.mes_max_id += 1; // 最後編號變為原本最後編號的下一個
        the_message.leave_id = temp.mes_max_id; // 編號成新的最後編號

        cout << "請輸入名稱: ";
        getline(cin, the_message.people);
        cout << "請輸入留言: ";
        getline(cin, the_message.says);

        the_message.time = time(NULL); // 記錄當下時間

        temp.message.push(the_message);
        lines_rem.push(temp);
    }

    while (!lines_rem.empty()) {
        temp = lines_rem.top();
        lines.push(temp);
        lines_rem.pop();
    }
}

