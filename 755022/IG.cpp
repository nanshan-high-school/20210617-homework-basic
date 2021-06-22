#include <iostream>
#include <ctime>
#include <string>
#include <stack>
using namespace std;
int main () {
    string id, image, text;
    stack<string> vid, vimage, vtext, vtime;
    int sum = 0;

    cout << "輸入您的ID:" << endl;
    cin >> id;
    vid.push(id);
    while(id != "0") {       
        cout << "輸入圖片網址:" << endl;
        cin >> image;
        vimage.push(image);
        cout << "輸入貼文:" << endl;
        cin >> text;
        vtext.push(text);
        sum++;
        time_t t = time(0);
        vtime.push(ctime(&t));
        cout << "輸入您的ID(輸入0結束):" << endl;
        cin >> id;
        vid.push(id);
    }

    vid.pop();

    for(int i = 0; i < sum; i++) {
        cout << "--------" << endl;
        cout << "ID : " << vid.top() << endl;
        vid.pop();
        cout << "圖片 : " << vimage.top() << endl;
        vimage.pop();
        cout << "貼文 : " << vtext.top() << endl;
        vtext.pop();
        cout << "時間：" << vtime.top() << endl;
        vtime.pop();
    }
}
