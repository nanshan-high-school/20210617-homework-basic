#include <iostream>
#include <string>
#include <ctime>
#include <stack>
using namespace std;

struct post {
    string userId;
    string context;
    string imageUrl;
    int time;
};

bool getNewPost();
int timeCalculate();
void printPost();

stack<post> postList;

int main() {
    bool keepOnPosting = true;
    do {
        keepOnPosting = getNewPost();
    } while (keepOnPosting);
    while (!postList.empty()) {
        printPost();
    }
}

bool getNewPost() {
    post newPost = {};

    cout << "輸入您的使用者名稱（輸入 View 以開始瀏覽）：";
    cin >> newPost.userId;
    if (newPost.userId == "View") {
        return false;
    }
    cout << "輸入您的內文（只能有一行）：";
    getline(cin, newPost.context);
    getline(cin, newPost.context);
    cout << "貼上您的圖片（網址）：";
    cin >> newPost.imageUrl;
    newPost.time = time(NULL);

    postList.push(newPost);
    return true;
}
string timeCalculate(int timePosted) {
    int difference = time(0) - timePosted;
    cout << difference << endl;
    if ((time(0) - timePosted) / 60 == 0) {
        return "Moments ago\n";
    }
    if ((time(0) - timePosted) / 3600 == 0) {
        return to_string((time(0) - timePosted) / 60) + " minutes ago\n";
    }
    if ((time(0) - timePosted) / 86400 == 0) {
        return to_string((time(0) - timePosted) / 3600) + " hours ago\n";
    }
    return to_string((time(0) - timePosted) / 86400) + " days ago\n";
}
void printPost() {
    cout << postList.top().userId << endl;
    cout << postList.top().imageUrl << endl;
    cout << postList.top().context << endl;
    cout << timeCalculate(postList.top().time);
    cout << "=============================\n";
    postList.pop();
}
