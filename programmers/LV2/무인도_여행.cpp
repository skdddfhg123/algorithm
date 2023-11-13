#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[101][101];
bool vis[101][101];

// bfs
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int w = maps.size();
    int h = maps[0].size();

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (maps[i][j] == 'X')
                vis[i][j] = 1;
            else
                board[i][j] = maps[i][j] - '0';
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (board[i][j] && !vis[i][j]) {
                int v = 0;
                vis[i][j] = 1;
                queue<pair<int ,int> > q;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int ,int > cur = q.front();
                    v += board[cur.first][cur.second];
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx >= 0 && ny >= 0 && nx < w && ny < h &&\
                            board[nx][ny] && !vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                answer.push_back(v);
            }
        }
    }

    if (answer.size() > 0)
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);
    return answer;
}

// //dfs
// void dfs(int x, int y, int& area, int w, int h) {
//     area += board[x][y];
//     vis[x][y] = true;

//     for (int dir = 0; dir < 4; dir++) {
//         int nx = x + dx[dir];
//         int ny = y + dy[dir];
//         if (nx >= 0 && ny >= 0 && nx < w && ny < h && board[nx][ny] && !vis[nx][ny]) {
//             dfs(nx, ny, area, w, h);
//         }
//     }
// }

// vector<int> solution(vector<string> maps) {
//     vector<int> answer;
//     int w = maps.size();
//     int h = maps[0].size();

//     for (int i = 0; i < w; i++) {
//         for (int j = 0; j < h; j++) {
//             if (maps[i][j] == 'X')
//                 board[i][j] = 0;
//             else
//                 board[i][j] = maps[i][j] - '0';
//         }
//     }

//     for (int i = 0; i < w; i++) {
//         for (int j = 0; j < h; j++) {
//             if (board[i][j] && !vis[i][j]) {
//                 int area = 0;
//                 dfs(i, j, area, w, h);
//                 answer.push_back(area);
//             }
//         }
//     }

//     if (answer.size() > 0)
//         sort(answer.begin(), answer.end());
//     else
//         answer.push_back(-1);
//     return answer;
// }

int main() {
    vector<string> maps1 = {"X591X", "X1X5X", "X231X", "1XXX1"};
    vector<int> result1 = solution(maps1);

    vector<string> maps2 = {"XXX", "XXX", "XXX"};
    vector<int> result2 = solution(maps2);

    cout << "Test Case 1: ";
    for (int res : result1) {
        cout << res << " ";
    }
    cout << endl;

    cout << "Test Case 2: ";
    for (int res : result2) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}