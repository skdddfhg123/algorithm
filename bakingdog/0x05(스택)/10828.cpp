#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  while(n--){
    string c;
    cin >> c;
    if(c=="push"){
      int t;
      cin >> t;
      S.push(t);
    }
    else if(c=="pop"){
      if(S.empty()) cout << -1 << '\n';
      else{
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if(c=="size")
      cout << S.size() << '\n';
    else if(c=="empty")
      cout << (int)S.empty() << '\n';
    else{
      if(S.empty()) cout << -1 << '\n';
      else cout << S.top() << '\n';
    }
  }
}

// #include "bits/stdc++.h"
// using namespace std;

// const int MX = 1000005;
// int dat[MX];
// int pos = 0;

// void push(int x) {
//     dat[pos++] = x;
// }

// void pop() {
//     if (pos != 0)
//         cout << dat[pos-- - 1] << '\n';
//     else
//         cout << "-1\n";
// }

// void size() {
//     cout << pos << '\n';
// }

// void top() {
//     if (pos == 0)
//         cout << "-1\n";
//     else
//         cout << dat[pos - 1] << '\n';
// }

// void empty() {
//     if (pos == 0)
//         cout << "1\n";
//     else
//         cout << "0\n";
// }

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n, v;
//     string s;
//     cin >> n;
//     while(n--) {
//         cin >> s;
//         if (s == "push") {
//             cin >> v;
//             push(v);
//         }
//         else if (s == "pop")
//             pop();
//         else if (s == "size")
//             size();
//         else if (s == "empty")
//             empty();
//         else if (s == "top")
//             top();
//     }
// }
