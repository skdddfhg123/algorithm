#include <bits/stdc++.h>

using namespace std;

int arr[10] = {};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ret = 1;
    cin >> n;
    while (n) {
        arr[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9)
            continue ;
        ret = max(ret, arr[i]);
    }
    ret = max(ret, (arr[6] + arr[9] + 1) / 2);
    cout << ret;
}

// #include <bits/stdc++.h>

// using namespace std;

// int check[10];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int num;
//     cin >> num;
//     while (num) {
//         short tmp = num % 10;
//         if (tmp == 6 && check[9] < check[6])
//             check[9]++;
//         else if (tmp == 9 && check[9] > check[6])
//             check[6]++;
//         else
//             check[tmp]++;
//         num = num / 10;
//     }
//     int ret = 0;
//     for (int i = 0; i < 10; i++) {
//         ret = max(ret, check[i]);
//     }
//     cout << ret;
// }
