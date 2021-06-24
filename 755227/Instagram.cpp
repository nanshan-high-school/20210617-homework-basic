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
    };

    stack<ig> allPost;
    ig newPost = {};

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

        allPost.push(newPost);
    } while (true);

    cout << endl;

    while(! allPost.empty()) {
        ig showPost = allPost.top();
        
        cout << showPost.user << endl;
        cout << showPost.photo << endl;
        cout << showPost.article << endl;
        cout << showPost.time;
        
        allPost.pop();

        if (! allPost.empty()) {
            cout << "-------------" << endl;
        }
    }
}
