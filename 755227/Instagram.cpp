#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
using namespace std;

int main() {
    struct ig {
        string user;
        string photo;
        string article;
        string time;
        string thumb;
        int thumbNum;
        int leaveMessageNum;
    };

    stack<ig> allPost;
    ig newPost = {};
    int thumbNum;
    string thumb;
    stack<string> thumbPeople;

    do {
        cout << "輸入使用者ID(輸入「0」以結束): ";
        cin >> newPost.user;
        if (newPost.user == "0") {
            break;
        }
        
        cout << "輸入圖片地址: ";
        cin >> newPost.photo;

        cout << "輸入文章: ";
        cin >> newPost.article;

        long nowTime = time(0) + 28800;
        newPost.time = ctime(&nowTime);

        do {
            cout << "輸入按讚之使用者ID(以換行隔開)(輸入「0」以結束): ";
            cin >> thumb;

            if (thumb != "0") {
                thumbNum++;
                thumbPeople.push(thumb);
            }
            
        } while (thumb != "0");
        
        newPost.thumbNum = thumbNum;
        thumbNum = 0;

        if (! thumbPeople.empty()) {
            newPost.thumb = thumbPeople.top();
        }

        cout << "輸入留言數量: ";
        cin >> newPost.leaveMessageNum;

        cout << endl;
        allPost.push(newPost);
    } while (true);

    cout << endl;

    while(! allPost.empty()) {
        ig showPost = allPost.top();
        
        cout << "使用者 " << showPost.user << " 發布了貼文" << endl;

        cout << showPost.photo << endl;

        cout << showPost.article << endl;

        cout << "發布於 " << showPost.time << endl;

        if (showPost.thumbNum == 0) {
            cout << "無人按讚" << endl;
        } else if (showPost.thumbNum == 1) {
            cout << showPost.thumb << "按讚" << endl;
        } else if (showPost.thumbNum >= 2) {
            cout << showPost.thumb << "和其他" << showPost.thumbNum - 1 << "人按讚" << endl;
        }

        cout << showPost.leaveMessageNum << "則留言" << endl;
        
        allPost.pop();

        if (! allPost.empty()) {
            cout << "-------------" << endl << endl;
        }
    }
}
