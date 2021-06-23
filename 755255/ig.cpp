#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

bool type_in();
void display_posts();
struct ig {
        string name;
        string image;
        vector<string> post;
        int time;
};
stack<ig> display;

int main() {
    bool continue_or_not = true;
    do {
        continue_or_not = type_in();
    } while(continue_or_not);
    display_posts();
    return 0;
}

bool type_in() {
    ig type;
    string a_sentence;

    cout << "請輸入你的帳號(若不想po文請打0):";
    cin >> type.name;
    if (type.name == "0") {
        return false;
    }

    cout << "請輸入圖片url:";
    cin >> type.image;

    cout << "請輸入貼文(輸入0結束輸入貼文):";
    do {
        getline(cin,a_sentence);
        if (a_sentence == "0") {
            break;
        }
        type.post.push_back(a_sentence);
    } while(true);

    type.time = time(0);
    
    display.push(type);
    return true;
}
void display_posts() {
    cout << "\n" << "\n";
    while (true) {
        ig display_that = display.top();
        cout << "帳戶:" << display_that.name << "\n";
        cout << "圖片url:" << display_that.name << "\n";
        for (int i = 0; i < display_that.post.size(); i++) {
            cout << display_that.post[i] << "\n";
        }

        int time_caculate;
        time_caculate = time(0) - display_that.time;
        if (time_caculate > 60) {
            time_caculate %= 60;
            cout << time_caculate << "分鐘前";
        } else if (time_caculate > 3600) {
            time_caculate %= 3600;
            cout << time_caculate << "小時前";
        } else if (time_caculate > 86400) {
            time_caculate %= 86400;
            cout << time_caculate << "天前";
        } else {
            cout << time_caculate << "秒前";
        }

        display.pop();

        if (display.empty()) {
            break;
        } else {
            cout << "\n" << "========================="<< "\n";
        }
    }
}
