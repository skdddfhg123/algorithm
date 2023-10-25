#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int> > q;
vector<int> v;
int n, num = 0;
string board[26];
bool vis[26][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '1' && vis[i][j] == 0) {
                vis[i][j] = 1;
                num++;
                int val = 1;
                q.push({i,j});
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue ;
                        if (!vis[nx][ny] && board[nx][ny] == '1') {
                            q.push({nx,ny});
                            vis[nx][ny] = 1;
                            val++;
                        }
                    }
                }
                v.push_back(val);
            }
        
        }
    }
    cout << num << '\n';
    sort(v.begin(), v.end());
    for (auto a : v) {
        cout << a << '\n'; 
    }    
}