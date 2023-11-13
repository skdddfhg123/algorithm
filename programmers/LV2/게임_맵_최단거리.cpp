#include<vector>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct st {
    int x;
    int y;
    int n;
};

queue<st > q;
bool vis[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int m = maps.size();
    int n = maps[0].size();
    
    q.push({0, 0, 1});
    vis[0][0] = 1;
    while(!q.empty()) {
        st cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.x;
            int ny = dy[dir] + cur.y;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n &&\
            !vis[nx][ny] && maps[nx][ny]) {
                // cout << nx << ',' << ny << ' ' << cur.n << '\n';
                vis[nx][ny] = 1;
                q.push({nx, ny, cur.n + 1});
                if (nx == m - 1 && ny == n - 1)
                    return cur.n + 1;
            }
        }
        
    }

    return answer;
}

int main() {

    vector<vector<int>> picture = {{1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1}};

    int result = solution(picture);

    cout << "Number of areas: " << result << endl;

    return 0;
}