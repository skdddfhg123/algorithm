#include <bits/stdc++.h>
using namespace std;

int check1[27];
int check2[27];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        check1[a[i] - 'a']++;
    for (int i = 0; i < b.length(); i++)
        check2[b[i] - 'a']++;
    int ret = 0;
    for (int i =0; i< 26; i++) {
        if (check1[i] != check2[i])
        {
            int l = max(check1[i], check2[i]);
            int s = min(check1[i], check2[i]);
            ret += l - s;
        }
    }
    cout << ret;
}