#include <bits/stdc++.h>

using namespace std;

int find_div(int w, int h) {
    int max_div = 1;
    int range = min(w, h);
    for (int i = 1; i <= range; i++) {
        if (w % i == 0 && h % i == 0) {
            max_div = i;
        }
    }
    return max_div;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w, h;
    int max_div;
    cin >> w >> h;
    max_div = find_div(w, h);
    cout << w * h - (w + h - max_div);
}