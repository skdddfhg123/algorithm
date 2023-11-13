#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> um;
    for (int i = 0; i < name.size(); i++)
        um[name[i]] = yearning[i];
    for (int i = 0; i < photo.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            cnt += um[photo[i][j]];
        }
        answer.push_back(cnt);
    }


    return answer;
}