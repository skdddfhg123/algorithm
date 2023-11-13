#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), cmp);
    // for (int i = 0; i < targets.size(); i++)
    //     cout << targets[i][0] << ' ' << targets[i][1] << '\n';
    int cmp = targets[0][1];
    for (int i = 0; i < targets.size(); i++) {
        if (targets[i][0] >= cmp) {
            answer += 1;
            cmp = targets[i][1];
        } else
            cmp = min(cmp, targets[i][1]);
    }
    return answer;
}