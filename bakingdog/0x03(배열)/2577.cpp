#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    long long sum;
    cin >> a >> b >> c;
    sum = a * b * c;
    while (sum) {
        arr[sum % 10] += 1;
        sum /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << "\n";
}