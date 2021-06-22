#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

bool WritePaste();
void PostPaste();
void passedtime(int StopTime);

struct paste {
    string user;
    string picture;
    string content;
    int time;
};

paste post, NewArticle;
stack<paste> article;
int StopPost;


int main() {
    system("clear");
    cout << "!歡迎來到小克車的社群網站!" << endl;
    cout << "接下來是 PO 文階段" << endl;
    cout << "----------------------------" << endl;
    
    bool YNpost = true;

    while (YNpost) { //輸入階段
        YNpost = WritePaste();
    }

    while (! article.empty()) { //輸出階段
        PostPaste();
    }
}


bool WritePaste() {
    cout << "請輸入你的 ID (輸入 0 表示結束)：";
    cin >> NewArticle.user;

    if (NewArticle.user == "0") {
        cout << "---------我是分隔線---------" << endl;
        return false;
    }

    cout << "圖片網址：" << endl;
    cin >> NewArticle.picture;

    cout << "輸入內文：" << endl;
    cin >> NewArticle.content;

    cout << "----------------------------" << endl;

    NewArticle.time = time(NULL);
    article.push(NewArticle);
    return true;
}

void PostPaste() {
    StopPost = time(NULL);
    post = article.top();

    cout << "名稱：";
    cout << post.user << endl;

    cout << "圖片：" << endl;
    cout << post.picture << endl;

    cout << "內文：" << endl;
    cout << post.content << endl;
    passedtime(StopPost);
    cout << "-------------" << endl;

    article.pop();
}

void passedtime(int StopTime) { // po 文時間
    int pass = StopTime - post.time;

    if (pass == 0) {
        cout << "剛剛\n";
    } else if (pass >= 60 && pass < 3600) {
        cout << pass / 60 << "分鐘前\n";
    } else if (pass >= 3600) { // 等等...不會有人跑這個程式花幾個小時吧?.?
        cout << pass / 3600 << "小時前\n";
    } else { // 我就不用寫超過一天的吧OuO
        cout << pass << "秒前\n";
    }
}
