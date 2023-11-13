#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct st {
    int X;
    int Y;
    int N;
};

queue<st> q;
queue<st> q2;

bool board[101][101];
bool vis[101][101];


int solution(vector<string> maps) {
    int answer = -1;
    pair<int, int> start;
    pair<int, int> lever;
    pair<int, int> end;

    int w = maps.size();
    int h = maps[0].size();
    // cout << w << " / " << h << '\n';
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (maps[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
            if (maps[i][j] == 'L') {
                lever.first = i;
                lever.second = j;
            }
            if (maps[i][j] == 'E') {
                end.first = i;
                end.second = j;
            }
            if (maps[i][j] == 'X')
                board[i][j] = 1;
        }
    }
    q.push({start.first, start.second, 0});
    vis[start.first][start.second] = 1;
    while (!q.empty()) {
        st cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue ;
            if (nx == lever.first && ny == lever.second) {
                q2.push({lever.first,lever.second, cur.N + 1});
                // cout << "N : " << cur.N + 1 << '\n';
                break ;
            }
            if (!vis[nx][ny] && !board[nx][ny]) {
                // cout << "nx : " << nx << "/ny : " << ny << '\n';
                q.push({nx, ny, cur.N + 1});
                vis[nx][ny] = 1;
            }
        }
        if (!q2.empty())
            break ;
    }
    memset(vis, 0, sizeof(vis));
    vis[lever.first][lever.second] = 1;
    while (!q2.empty()) {
        st cur = q2.front();
        q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue ;
            if (nx == end.first && ny == end.second) {
                // cout << "N : " << cur.N + 1 << '\n';
                return  cur.N + 1;
                break ;
            }
            if (!vis[nx][ny] && !board[nx][ny]) {
                q2.push({nx, ny, cur.N + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    
    return answer;
}

int main() {
    vector<string> maps = {
        "LOOOS", "OOOOX", "OOOOO", "OOOOO", "EOOOO", "OOOOO"
    };

    int result = solution(maps);
    cout << "Result: " << result << endl;

    return 0;
}
