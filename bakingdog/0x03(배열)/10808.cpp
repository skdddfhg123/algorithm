#include <bits/stdc++.h>

using namespace std;

char arr[26];
int check[26];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    char tmp = 'a';
    for (int i = 0; i < 26; i++)
        arr[i] = tmp++;
    for (int i = 0; i < s.length(); i++)
    {
        char tmp = s[i];
        for (int j = 0; j < 26; j++)
            if (s[i] == arr[j])
                check[j] += 1;
    }
    for (int i = 0; i < 26; i++)
        cout << check[i] << " ";
}

// #include <bits/stdc++.h>

// using namespace std;

// int check[26];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     string s;
//     cin >> s;

//     for (auto c : s)
//         check[c - 'a']++;
//     for (int i = 0; i < 26; i++)
//         cout << check[i] << ' ';
// }
