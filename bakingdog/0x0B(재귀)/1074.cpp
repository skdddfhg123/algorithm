#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll pow(int n) {
    ll v = 1;
    while(n--)
        v = v * 2;
    return v;
}

void solv(int N, int x, int y, int z) {
    if (N == 0)
        cout << z;
    else {
        int p = pow(N - 1);
        //1
        if (x < p && y < p) {
            solv(N - 1, x, y, z); 
        }
        //2
        if (x < p && y >= p) {
            solv(N - 1, x, y - p, z + (p * p)); 
        }
        //3
        if (x >= p && y < p) {
            solv(N - 1, x - p, y, z + (p * p * 2)); 
        }
        //4
        if (x >= p && y >= p) {
            solv(N - 1, x - p, y - p, z + (p * p * 3)); 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    solv(N, r, c, 0);
    return 0;
}