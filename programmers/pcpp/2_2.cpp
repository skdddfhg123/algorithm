#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int answer;

bool student[11];

void dfs(int n, int t, vector<vector<int>> &ability) {
    if (n == ability[0].size()) {
        answer = max(answer, t);
    }
    else {
        // 학생별로 돌면서
        for (int i = 0; i < ability.size(); i++) {
            int total = t;
            // cout << t << "     \n";
            if (!student[i]) {
                student[i] = 1;
                total += ability[i][n];
                // cout << i << ',' <<  j << ' ' << total << '\n';
                dfs(n + 1, total, ability);
                total -= ability[i][n];
                student[i] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> ability) {
    dfs(0, 0, ability);

    return answer;
}

int main() {
    vector<vector<int>> ability = {{40, 10, 10}, {20, 5, 0}, {30, 30, 30} , {70, 0, 70}, {100, 100, 100}};
    cout << solution(ability) << '\n';
}