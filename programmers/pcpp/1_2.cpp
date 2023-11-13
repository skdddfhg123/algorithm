#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[501][501];
int value[250001];
bool vis[250001];

queue<pair<int ,int> > q;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int y = land.size();
    int x = land[0].size();

    int idx = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int cnt = 0;
            if (!board[j][i] && land[j][i] == 1) {
                idx++;
                cnt++;

                board[j][i] = idx;
                q.push({j, i});
                while(!q.empty()) {
                    pair<int ,int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if (nx >= 0 && ny >= 0 && nx < x && ny < y &&\
                        !board[ny][nx] && land[ny][nx] == 1) {
                            board[ny][nx] = idx;
                            cnt++;
                            q.push({ny, nx});
                        }
                    }
                }
                value[idx] = cnt;
            }
        }
    }

    for (int i = 0; i < x; i++) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int j = 0; j < y; j++) {
            if (board[j][i] && !vis[board[j][i]]) {
                vis[board[j][i]] = 1;
                cnt += value[board[j][i]];
                // cout << i << " value : " << value[board[j][i]] << "/idx: " << board[j][i] << '\n';
            }
        }
        answer = max(answer, cnt);
    }

    return answer;
}

int main() {
    // // Test case 1
    // vector<vector<int>> land1 = {
    //     {0, 0, 0, 1, 1, 1, 0, 0},
    //     {0, 0, 0, 0, 1, 1, 0, 0},
    //     {1, 1, 0, 0, 0, 1, 1, 0},
    //     {1, 1, 1, 0, 0, 0, 0, 0},
    //     {1, 1, 1, 0, 0, 0, 1, 1}
    // };
    // int result1 = solution(land1);
    // cout << "Test case 1 result: " << result1 << endl;

    // Test case 2
    vector<vector<int>> land2 = {
        {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1}
    };
    int result2 = solution(land2);
    cout << "Test case 2 result: " << result2 << endl;

    return 0;
}