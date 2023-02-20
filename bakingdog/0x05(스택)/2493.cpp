#include "bits/stdc++.h"

using namespace std;

int N, tmp;

stack<pair<int, int>> s;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    s.push({1000000001, 0});
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        while (s.top().first < tmp) {
            s.pop();
        }
        cout << s.top().second << " ";
        s.push({tmp, i});
    }
}