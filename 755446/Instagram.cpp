#include <ctime>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct post{
    string name;
    string image;
    string content;
    int Time;
};

stack<post> posts;

int main() {
    while (true) {
        bool flag = false;
        post newPost = {};
        cout << "你的名子(輸入 0 結束)：";
        cin >> newPost.name;

        if (newPost.name == "0") {
            flag = true;
        }
        if (flag) break;
        cout << "圖片：";
        cin >> newPost.image;
        cin.ignore();
        cout << "內文：";
        getline(cin, newPost.content);
        newPost.Time = time(0);
        posts.push(newPost);
    }
    while (! posts.empty()) {
        //showAPost();
        post showPost = posts.top();
        cout << showPost.name << endl;
        cout << showPost.image << endl;
        cout << showPost.content << endl;
        cout << showPost.Time;
    
        posts.pop();

        cout << endl << "---------" << endl;
    } 
}
