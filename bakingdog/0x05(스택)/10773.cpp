#include "bits/stdc++.h"

using namespace std;

int K, tmp, ret;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K;
    stack<int> s;
    for (int i = 0; i < K; i++) {
        cin >> tmp;
        if (tmp)
            s.push(tmp);
        else
            s.pop();
    }
    while (!s.empty()) {
        ret += s.top();
        s.pop();
    }
    cout << ret;
}