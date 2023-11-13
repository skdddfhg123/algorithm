#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n) {
        if (n % 3 == 0) {
            answer.append(1, '4');
            n--;
        } else
            answer.append(1, n % 3 + '0');
        n /= 3;
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    // cout << solution(1) << '\n';
    // cout << solution(2) << '\n';
    // cout << solution(3) << '\n';
    // cout << solution(4) << '\n';
    // cout << solution(5) << '\n';
    // cout << solution(6) << '\n';
    cout << solution(7) << '\n';
    cout << solution(8) << '\n';
    cout << solution(9) << '\n';
    cout << solution(10) << '\n';
    cout << solution(11) << '\n';
    // cout << solution(1) << '\n';
    // cout << solution(1) << '\n';

}