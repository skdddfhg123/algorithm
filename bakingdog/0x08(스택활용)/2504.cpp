// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie();
//     string c;
//     stack<char> s;
//     int let = 0;
//     cin >> c;
//     for (int i = 0; i < c.size(); i++) {
//         cout << "let = " << let << " / i = " << i << endl;
//         if (s.empty() && c[i] == ')' || c[i] == ']') {
//             cout << '0';
//             return 0;
//         }
//         if (c[i] == '(' || c[i] == '[')
//             s.push(c[i]);
//         else {
//             int tmp = 0;
//             while(!s.empty()) {
//                 cout << "while i = " << i << endl;
//                 if (s.empty()) {
//                     cout << '0';
//                     return 0;
//                 }
//                 else if (c[i] == '(' || c[i] == '[') {
//                     let += tmp;
//                     continue ;
//                 }
//                 if (c[i] == ')') {
//                     if (s.top() == '(') {
//                         if (tmp)
//                             tmp *= 2;
//                         else
//                             tmp = 2;
//                         cout << "tmp() = " << tmp<< " / i = " << i << endl;
//                         s.pop();
//                     } 
//                     else {
//                         cout << '0';
//                         return 0;
//                     }
//                 }
//                 if (c[i] == ']') {
//                     if (s.top() == '[') {
//                         if (tmp)
//                             tmp *= 3;
//                         else
//                             tmp = 3;
//                         cout << "tmp[] = " << tmp<< " / i = " << i << endl;
//                         s.pop();
//                     } 
//                     else {
//                         cout << '0';
//                         return 0;
//                     }
//                 }
//                 i++;
//             }
//             let += tmp;
//         }
//     }
//     cout << let;
// }


#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  int sum = 0; 
  int num = 1; 

  for(int i = 0; i < str.size(); i++){
    
    if(str[i] == '('){
      num *= 2; 
      s.push(str[i]);
    }
    else if(str[i] == '['){
      num *= 3; 
      s.push(str[i]);
    }
    else if(str[i] == ')'){
      if(s.empty() || s.top() != '('){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '(') sum += num;
      s.pop();
      num /= 2;  
    }
    else{ 
      if(s.empty() || s.top() != '['){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '[') sum += num;
      s.pop();
      num /= 3;
    }
    // cout << "i = " << i << str[i] << " /num = " << num << " /sum =" << sum <<  endl;
  }
  if(s.empty()) cout << sum;
  else cout << 0;
}
