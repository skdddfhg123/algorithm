#include "bits/stdc++.h"
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

int top() {
    return dat[pos - 1];
}

void    test() {

}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> S;
  S.push(10);
  S.push(20);
  S.push(30);
  cout << S.size() << '\n';
  if(S.empty()) cout << "S is empty\n";
  else cout << "S is not empty\n";
  S.pop();
  cout << S.top() << '\n';
  S.pop();
  cout << S.top() << '\n';
  S.pop();
  if(S.empty()) cout << "S is empty\n";
  cout << S.top() << '\n';
}
