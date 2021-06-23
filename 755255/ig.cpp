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

    cout << "�п�J�A���b��(�Y���Qpo��Х�0):";
    cin >> type.name;
    if (type.name == "0") {
        return false;
    }

    cout << "�п�J�Ϥ�url:";
    cin >> type.image;

    cout << "�п�J�K��(��J0������J�K��):";
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
        cout << "�b��:" << display_that.name << "\n";
        cout << "�Ϥ�url:" << display_that.name << "\n";
        for (int i = 0; i < display_that.post.size(); i++) {
            cout << display_that.post[i] << "\n";
        }

        int time_caculate;
        time_caculate = time(0) - display_that.time;
        if (time_caculate > 60) {
            time_caculate %= 60;
            cout << time_caculate << "�����e";
        } else if (time_caculate > 3600) {
            time_caculate %= 3600;
            cout << time_caculate << "�p�ɫe";
        } else if (time_caculate > 86400) {
            time_caculate %= 86400;
            cout << time_caculate << "�ѫe";
        } else {
            cout << time_caculate << "��e";
        }

        display.pop();

        if (display.empty()) {
            break;
        } else {
            cout << "\n" << "========================="<< "\n";
        }
    }
}
