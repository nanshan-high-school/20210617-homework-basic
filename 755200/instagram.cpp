#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

using namespace std;
struct post{
    string username;
    string image;
    string content;
    time_t time;
};

void givenTime(time_t);
bool postSomething_pls();
void showPosts();

stack<post> posts;

int main() {
    bool posting = true;
    string watchpost, logout = "NULL";
    do {
        do {
            posting = postSomething_pls();
        } while (posting);
        do {
            cout << "want to watch posts? (input yes or else) ";
            cin >> watchpost;
            if (! posts.empty() && watchpost == "yes") {
                showPosts();
            }
            else if (posts.empty() && watchpost == "yes") {
                cout << "you have no post to watch, you need to post a post" << endl;
                break;
            }
            else
                break;
        } while (true);
        cout << "want to log out ?? (input yes or else)";
        cin >> logout;
    } while (logout != "yes");
}

bool postSomething_pls(){
    post newpost;
    string input;
    cout << "exit editing or not? (input exit or else)" << endl;
    cin >> input;
    if (input == "exit")
        return false;
    cout << "your ID: ";
    cin >> newpost.username;
    cout << "你的圖片網址：";
    cin >> newpost.image;
    cout << "你的內文：";
    cin >> newpost.content;
    newpost.time = time(0) + 28800;
    posts.push(newpost);
    return true;        
}

void givenTime(time_t t) {
    char tAll[1024];
	strftime(tAll,sizeof(tAll),"%Y %m/%d %R ",localtime(&t));
    puts(tAll);
	string result = "";
	cout << result << endl;
}

void showPosts() {
    stack<post> showpost;
    showpost = posts;
    cout << "........" << endl;
    while (! showpost.empty()) {
        post showPost = showpost.top();
        cout << showPost.username << " post:" << endl;
        cout << showPost.image << endl;
        cout << showPost.content << endl;
        cout << "        ";
        givenTime(showPost.time);
        showpost.pop();
        cout << "........" << endl;
    }
}
// time_t t = time(0) + 28800;
