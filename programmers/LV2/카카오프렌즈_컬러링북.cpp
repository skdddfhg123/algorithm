#include <vector>
#include <bits/stdc++.h>

using namespace std;


int vis[101][101];

queue<pair<int, int> > q;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int num = 0;
    int max_num = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    memset(vis, 0, sizeof(vis));
    vector<int> answer(2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && picture[i][j] != 0) {
                q.push({i, j});
                vis[i][j] = 1;
                int cnt = 0;
                int cmp = picture[i][j];
                num++;
                while(!q.empty()) {
                    // cout << picture[i][j] << '\n';
                    cnt++;
                    pair<int ,int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = dx[dir] + cur.first;
                        int ny = dy[dir] + cur.second;
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n &&\
                        !vis[nx][ny] && picture[nx][ny] == cmp) {
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                            cout << nx << ' ' << ny << ' ' << cmp << cnt <<  '\n';
                        }
                    }
                    
                    max_num = max(max_num, cnt);
                }
            }
        }
    }
    answer[0] = num;
    answer[1] = max_num;
    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};

    vector<int> result = solution(m, n, picture);

    cout << "Number of areas: " << result[0] << endl;
    cout << "Largest area: " << result[1] << endl;

    return 0;
}