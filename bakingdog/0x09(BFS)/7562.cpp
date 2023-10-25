#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

struct str{
    int x;
    int y;
    int t;
};

bool vis[301][301];

int num, n, end_x, end_y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    while(num--) {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        queue<str> q;
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        q.push({tmp1, tmp2, 0});
        cin >> end_x >> end_y;
        while(!q.empty()) {
            str cur = q.front();
            if (cur.x == end_x && cur.y == end_y) {
                cout << cur.t << '\n';
                break ;
            }
            q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue ;
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny, cur.t + 1});
                }
            }
        }
    }
}
