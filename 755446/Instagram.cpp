#include <iostream>
#include <stack>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void show_post();
void sign_in();
void sign_up();
void upload();
void like();
void comment();

string account;
string password;
string now_user;
vector<int> like_num;

struct comment_st{
    string name;
    string sentence;
};

int main() {
    while(true) {
        cout << "請選擇功能(看文1/登入2/註冊3/發文4): ";
        int cmd;
        cin >> cmd;
        switch(cmd){
            case 1:
                show_post();
                break;
            case 2:
                sign_in();
                break;
            case 3:
                sign_up();
                break;
            case 4:
                upload();
                break;
        }
    }    
}
void show_post(){
    int cmd;
    ifstream the_post;
    the_post.open("post.txt", ios::in);
    string op;
    while (getline(the_post, op)) {
        cout << op << endl;
    }
    the_post.close();
    cout << "請輸入動作(按讚1/繼續看文2/留言3): ";
    cin >> cmd;
    if (cmd == 1) like();
    if (cmd == 3) comment();
    return;
}
void sign_in(){
    string check;
    bool account_check = false;
    bool password_check = false;
    cout << "____登入模式____\n";
    string account_temp;
    string password_temp;
    string pw;
    ifstream the_user_account;
    the_user_account.open("user_data", ios::in);
    cout << "帳號名(輸入 0 結束): ";
    cin >> account_temp;
    if(account_temp == "0") return;
    while (!the_user_account.eof()) {
        getline(the_user_account, check);
        if(account_temp == check) {
            account_check = true;
            getline(the_user_account, pw);
            break;
        }
        getline(the_user_account, check); 
    }
    if(!account_check) {
        cout << "----查無此帳號----\n";
        return;
    }

    cout << "密碼: ";
    cin >> password_temp;
    if (password_temp == pw) {
        now_user = account_temp;
        cout << "----" << now_user << "登入成功----\n";
    } else {
        cout << "----密碼錯誤----\n";
    }
    return;
}
void sign_up(){
    string ip;
    ofstream user;
    user.open("user_data", ios::out | ios::app);
    cout << "____註冊模式____\n";
    cout << "帳號名(輸入 0 結束): ";
    cin >> ip;
    if (ip == "0") return;
    user << ip << endl;
    cout << "密碼: ";
    cin >> ip;
    user << ip << endl;
    cout << "----註冊成功----\n";
    user.close();
    return;
}
void upload(){
    string ip;
    ofstream post;
    post.open("post.txt", ios::out | ios::app);
    bool flag = false;
    cout << "帳號名(輸入 0 結束): ";
    cin >> ip;
    if (ip == "0") return;
    post << ip << endl;
    cout << "圖片: ";
    cin >> ip;
    post << ip << endl;
    cin.ignore();
    cout << "內文: ";
    getline(cin, ip);
    post << ip << endl;
    post << time(0) << endl;
    post << "----------------------\n";
    post.close();
    return;
}
void like() {
    ofstream like;
    like.open("like.txt", ios::out | ios::app);
    int num;
    cout << "請輸入貼文編號: ";
    cin >> num;
    like_num[num]++;
    return;
}
void comment() {
    cout << "請輸入貼文編號 留言: ";
    return;
}
