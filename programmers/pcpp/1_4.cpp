#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
bool r_vis[4][4];
bool b_vis[4][4];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

pair<int ,int > red;
pair<int ,int > blue;
pair<int ,int > red_e;
pair<int ,int > blue_e;
pair<int ,int > board;

int answer = 99999;

void solv(int n, int r_x, int r_y, int b_x, int b_y, bool r_fin, bool b_fin) {
    if (r_fin && b_fin) {
        answer = min(answer, n);
        return ;
    }
    // red
    if (!r_fin) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = r_x + dx[dir];
            int ny = r_y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < board.first && ny < board.second && !r_vis[nx][ny]) {
                cout << "red move n:"<< n << "\nnx : " << nx << ",ny : " << ny << '\n';
                r_vis[nx][ny] = 1;
                if (nx == red_e.first && ny == red_e.second) {
                    cout << "!!!!!!!!!! red !!!!!!!!!!!!!\n";
                    solv(n + 1, nx, ny, b_x, b_y, 1, b_fin);
                }
                else
                    solv(n + 1, nx, ny, b_x, b_y, r_fin, b_fin);
                r_vis[nx][ny] = 0;
            }
        }
    }
    // blue
    if (!b_fin) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = b_x + dx[dir];
            int ny = b_y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < board.first && ny < board.second && !b_vis[nx][ny]) {
                cout << "blue move n:"<< n << "\nnx : " << nx << ",ny : " << ny << '\n';
                b_vis[nx][ny] = 1;
                if (nx == blue_e.first && ny == blue_e.second) {
                    cout << "!!!!!!!!!! blue !!!!!!!!!!!!!\n";
                    solv(n + 1, nx, ny, b_x, b_y, r_fin, 1);
                }
                else
                    solv(n + 1, nx, ny, b_x, b_y, r_fin, b_fin);
                b_vis[nx][ny] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    
    board.first = maze.size();
    board.second = maze[0].size();
    for (int i = 0; i < board.first; i++) {
        for (int j = 0; j < board.second; j++) {
            if (maze[i][j] == 1){
                red.first = i;
                red.second = j;
                r_vis[i][j] = 1;
            }
            if (maze[i][j] == 2){
                blue.first = i;
                blue.second = j;
                b_vis[i][j] = 1;
            }
            if (maze[i][j] == 3){
                red_e.first = i;
                red_e.second = j;
            }
            if (maze[i][j] == 4){
                blue_e.first = i;
                blue_e.second = j;
            }
            if (maze[i][j] == 5){
                r_vis[i][j] = 1;
                b_vis[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < board.first; i++) {
        for (int j = 0; j < board.second; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << '\n';
    }

    solv(0, red.first, red.second, blue.first, blue.second, 0, 0);
    if (answer == 99999)
        return 0;
    else
        return answer;
}

int main() {
    vector<vector<int>> maze = {
        {1, 4},
        {0, 0},
        {2, 3}
    };
    int result = solution(maze);
    cout << "결과: " << result << endl;
    return 0;
}