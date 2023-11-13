#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int check[150];
bool ans[150];

string solution(string input_string) {
    string answer = "";
    // cout << input_string.size();
    for (int i = 0; i < input_string.size(); i++) {
        char cmp = input_string[i];
        if (!check[cmp]) {
            int n = 1;
            while(i + 1 < input_string.size() && input_string[i + 1] == cmp) {
                n++;
                i++;
            }
            check[cmp] = n;
        }
        else if (check[cmp]) {
            int n = 1;
            while (i + 1 < input_string.size() && input_string[i + 1] == cmp) {
                n++;
                i++;
            }
            ans[cmp] = 1;
        }
    }
    bool f = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (ans[i]) {
            answer.append(1, i);
            f = 1;
        }
    }
    if (!f)
        answer.append(1, 'N');

    return answer;
}

int main() {
    cout << solution("zbzbz");
}