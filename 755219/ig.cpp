#include <iostream>
#include <string>
#include <stack>
#include <ctime>
using namespace std;

int main () {
    stack<string> id;
    stack<string> image;
    stack<string> text;
    stack<string> Time;
    string temp;
    while (true) {
        cout << "你的ID：";
        cin >> temp;
        id.push(temp);
        cout << "你的圖片：";
        cin >> temp;
        image.push(temp);
        cout << "你的內容：";
        cin >> temp;
        text.push(temp);
        time_t now = time(0);
        Time.push(ctime(&now));
        cout << "輸入 0 看貼文，輸入不是零的東西繼續潑文：";
        cin >> temp;
        if (temp == "0") {
            break;
        }
    }
    cout << "--------" << endl;
    while (!id.empty()) {
        cout << "ID：" << id.top() << endl;
        id.pop();
        cout << "圖片" << image.top() << endl;
        image.pop();
        cout << "內容：" << text.top() << endl;
        text.pop();
        cout << "時間：" << Time.top();
        Time.pop();
        cout << "--------" << endl;
    }
}
