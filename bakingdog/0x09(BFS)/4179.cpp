#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int R, C;
int fboard[1002][1002];
int board[1002][1002];

pair<int, int> jihoon;
pair<int, int> fire;

queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        fill(board[i], board[i]+C, 0);
        fill(fboard[i], fboard[i]+C, 0);    
    }
    string tmp;
    for (int i = 0; i < R; i++) {
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            if (tmp[j] == '#') {
                fboard[i][j] = -1;
                board[i][j] = -1;
            }
            else if (tmp[j] == 'J') {
                jihoon.X = i;
                jihoon.Y = j;
                board[i][j] = 1;
            }
            else if (tmp[j] == 'F') {
                fire.X = i;
                fire.Y = j;
                fboard[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    
    // fire time
    while(!q.empty()) {
        pair <int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue ;
            if (fboard[nx][ny] == 0 || fboard[nx][ny] > fboard[cur.X][cur.Y] + 1) {
                q.push({nx, ny});
                fboard[nx][ny] = fboard[cur.X][cur.Y] + 1;
            }
        }
    }
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << fboard[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // jihoon time
    q.push({jihoon.X, jihoon.Y});
    while(!q.empty()) {
        pair <int, int> cur = q.front();
        if (cur.X == R - 1 || cur.Y == C -1 || cur.X == 0 || cur.Y == 0) {
            cout << board[cur.X][cur.Y];
            return 0;
        }
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue ;
            if (board[nx][ny] == 0 && (board[cur.X][cur.Y] + 1 < fboard[nx][ny] || fboard[nx][ny] == 0)) {
                if (nx == R - 1 || ny == C -1 || nx == 0 || ny == 0) {
                    cout << board[cur.X][cur.Y] + 1;
                    return 0;
                }
                q.push({nx, ny});
                board[nx][ny] = board[cur.X][cur.Y] + 1;
            }
        }
    }
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << "IMPOSSIBLE";



}