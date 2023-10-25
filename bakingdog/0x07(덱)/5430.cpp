#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    short T;
    cin >> T;
    int l;
    string p, x;
    while (T--) {
        bool    dir = true;
        bool    e_check = 0;
        deque<int> dq;
        cin >> p >> l >> x;
        string tmp = "";
        for (int i = 0; i < x.length(); i++) {
            if (isdigit(x[i]))
                tmp += x[i];
            else {
                if (!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                if (dir == true)
                    dir = false;
                else
                    dir = true;
            } else if (p[i] == 'D') {
                if (dir == true) {
                    if (dq.size() <= 0) {
                        e_check = 1;
                        break ;
                    }
                    else
                        dq.pop_front();
                    
                }
                else {
                    if (dq.size() <= 0) {
                        e_check = 1;
                        break ;
                    }
                    else
                        dq.pop_back();
                    
                }
            }
        }
        if (e_check) {
            cout << "error\n";
            continue ;
        }
        cout << '[' ;
        for (int i = 0; i < dq.size(); i++) {
            if (i == dq.size() - 1) {
                if (dir == true)
                    cout << dq[i];
                else
                    cout << dq[dq.size() - (i + 1)];
            }
            else {
                if (dir == true)
                    cout << dq[i] << ',';
                else
                    cout << dq[dq.size() - (i + 1)] << ',';
            }
        }
        cout << "]\n";
    }
}

// 44m