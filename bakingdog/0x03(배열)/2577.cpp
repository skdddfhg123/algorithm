#include <bits/stdc++.h>

using namespace std;

int check[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    long long sum = a * b * c;
    while (sum) {
        check[sum % 10]++;
        sum /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << check[i] << "\n";
}
