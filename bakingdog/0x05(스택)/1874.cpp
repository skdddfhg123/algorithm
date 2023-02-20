#include "bits/stdc++.h"

using namespace std;

int n, goal, j;
bool ret[1000001];
stack<int> s;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int check = 1;
    for(int i = 0; i < n; i++) {
        cin >> goal;
        while (goal >= check) {
            s.push(check++);
            ret[j++] = 1;
        }
        if (goal != s.top()) {
            cout << "NO";
            return 0;
        }
        s.pop();
        j++;
    }
    for (int i = 0; i < j; i++) {
        if (ret[i])
            cout << "+\n";
        else
            cout << "-\n";
    }
}