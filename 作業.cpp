#include <iostream>
using namespace std;
#include <stack>
#include <time.h>


int main() {
  string http,n,p;
  stack<string> h;
  stack<string> name;
  stack<string> Time;
  stack<string> pi;



   
   do{
     cout << "輸入ID(0即為結束):";
     cin >> n;
     if (n == "0"){
       break;
     }
     
     name.push(n);
     cout << "輸入網址:";
     cin >> http;
     h.push(http);
     cout << "輸入內文:";
     cin >> p ;
     pi.push(p);
     time_t now = time(0) + 28800;
     Time.push(ctime(&now));





   }while (n != "0");
   
   while (! h.empty()){
     cout << "===============" << "\n";
     
     cout << "名字:" << name.top();
     cout << "網址:" << h.top();
     cout << "內文:" << pi.top();
     cout << "時間:" << Time.top();
     
     
     h.pop();
     name.pop();
     pi.pop();
     Time.pop();
   }
}