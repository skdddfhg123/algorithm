#include <bits/stdc++.h>

using namespace std;

int check[27];
int check2[27];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        fill(check, check + 26, 0);
        fill(check2, check2 + 26, 0);
        string a, b;
        cin >> a >> b;
        int cmp = 0;
        int flag = 0;
        for (int i = 0; i < a.length(); i++)
            check[a[i]- 'a']++;
        for (int i = 0; i < b.length(); i++)
            check2[b[i] - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (check[i] != check2[i]) {
                cout << "Impossible\n";
                flag++;
                break ;
            }
        }
        if (!flag)
            cout << "Possible\n";
    }
}