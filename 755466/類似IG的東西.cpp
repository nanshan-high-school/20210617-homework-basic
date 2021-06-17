#include <iostream>
#include <time.h>
#include <stack>
#include <string>
using namespace std;

int main() {
    string n;
    stack<string> ID;
    stack<string> Web;
    stack<string> Pic;
    stack<string> Time;

    while(true){
        cout << "你的ID(輸入0 結束po文) :";
        cin >> n;
        if (n == "0"){
            cout << "結束po文\n";
            break;
        }
        ID.push(n);
        cout << "輸入網址:";
        cin >> n;
        Web.push(n);
        cout << "輸入內文:";
        cin >> n;
        Pic.push(n);
        time_t now = time(0) + 28800;
        Time.push(ctime(&now));
    }

    cout << "==========\n";
    while(!ID.empty()){
        cout << "ID:" << ID.top();
        ID.pop();
        cout << endl;
        cout << "網址:" << Web.top();
        Web.pop();
        cout << endl;
        cout << "照片:" << Pic.top();
        cout << endl;
        Pic.pop();
        cout << "發文時間:" << Time.top();
        Time.pop();
        cout << "==========\n";
        
    }

}
/*
IG:

ID 
網址
照片
times
*/
