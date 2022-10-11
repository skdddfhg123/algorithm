#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, fivecount = 0;
    cin >> n;
    while (n) {
        n /= 5;
        fivecount += n;
    }
    cout << fivecount;
}
