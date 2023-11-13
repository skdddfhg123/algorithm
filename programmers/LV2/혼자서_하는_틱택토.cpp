#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int arr[2];

int win_check(vector<string> &board) {
    arr[0] = 0;
    arr[1] = 0;
    int cnt = 0;
    // row, column
    for (int i = 0; i < 3; i++) {
        // row,
        if (board[i][0] != '.') {
            char cmp_r = board[i][0];
            int f_r = 0;
            for (int j = 0;j < 3; j++) {
                if (board[i][j] == cmp_r)
                    f_r++;
                if (f_r == 3) {
                    if (board[i][j] == 'O')
                        arr[0]++;
                    else
                        arr[1]++;
                    cnt++;
                }
            }
        }
        if (board[0][i] != '.') {
            char cmp_c = board[0][i];
            int f_c = 0;
            for (int j = 0;j < 3; j++) {
                if (board[j][i] == cmp_c)
                    f_c++;
                if (f_c == 3) {
                    if (board[j][i] == 'O')
                        arr[0]++;
                    else
                        arr[1]++;
                    cnt++;
                }
            }
        }
    }
    // x+y, x-y
    char cmp_p = board[0][0];
    char cmp_m = board[0][2];
    int f_p = 0;
    int f_m = 0;
    if (cmp_p != '.' || cmp_m != '.') {
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == cmp_p)
                f_p++;
            if (board[i][2-i] == cmp_m)
                f_m++;
            if (f_m == 3 || f_p == 3) {
                if (board[1][1] == 'O')
                    arr[0]++;
                else if (board[1][1] == 'X')
                    arr[1]++;
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(vector<string> board) {
    int answer = -1;
    int win = 0;
    int o_cnt = 0;
    int x_cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O')
                o_cnt++;
            else if (board[i][j] == 'X')
                x_cnt++;
        }
    }
    win = win_check(board);
    cout << "o_cnt :" << o_cnt << "/ x_cnt :" << x_cnt << "/o win : " << arr[0] << "/x win : " << arr[1] << '\n';
    if (arr[0] && arr[1]) {
        // cout << win << "eee\n";
        return 0;
    }
    if (arr[0]) {
        if (o_cnt - x_cnt != 1)
            return 0;
    }
    if (arr[1])
        if (x_cnt != o_cnt)
            return 0;
    if (x_cnt != o_cnt && o_cnt - 1 != x_cnt)
        return 0;

    return 1;
}

int main() {
    vector<string> boards = {
        "OOX", "XXO", "OXO",
        "XXX", "XXX", "XXX",
        "OOO", "OOO", "OOO",
        "OXO", ".XO", "X.O",
        "OOO", "X.X", "...",
        "OOO", "...", "...",
        "O..", "...", "...",
        ".O.", "...", "...",
        "..O", "...", "...",
        "...", "O..", "...",
        "...", ".O.", "...",
        "...", "..O", "...",
        "...", "...", "O..",
        "...", "...", ".O.",
        "...", "...", "..O",
        "X..", "...", "...",
        ".X.", "...", "...",
        "..X", "...", "...",
        "...", "X..", "...",
        "...", ".X.", "...",
        "...", "..X", "...",
        "...", "...", "X..",
        "...", "...", ".X.",
        "...", "...", "..X",
        "OX.", ".OX", "..O",
        "O..", ".O.", "..O",
        "X..", ".X.", "..X",
        "XO.", "XO.", "XO.",
        "XO.", "...", "...",
        "OXO", "...", "...",
        "OXO", "X..", "...",
        "OXO", "XO.", "...",
        "OOO", "X.X", ".X.",
        "OOO", "X.X", "XX.",
        "XXX", "OO.", ".OO",
        "XO.", "OXO", "XOX",
        "OOO", "XOX", "XXO",
        "OOO", "OOX", "XXX",
        "XOX", "OXO", "XOX",
        "XXO", "OOX", "XO.",
        "XXO", "OOX", "XOO",
        "X.X", ".X.", "X.X",
        ".X.", "X.X", ".X.",
        "O.O", ".O.", "O.O",
        ".O.", "O.O", ".O.",
        "OX.", "OXO", ".XO",
        "OX.", "OX.", ".XO",
        "OX.", "OXO", "XXO",
        "OX.", "...", "...",
        "...", "...", "OX.",
        "OXO", "XOX", "OXO",
        "OOX", "XXO", "OOX",
        "XXX", ".OO", "O..",
        "OX.", ".O.", ".XO",
        "X.X", "X.O", "O.O",
        "XO.", "OXO", "XOX",
        "OOO", "XOX", "X.X",
        "XXX", "OO.", "OO.",
        ".X.", "X..", ".O.",
        "XXX", "XOO", "OOO",
        "OOX", "OXO", "XOO",
        "OOX", "OXO", "XOX",
        ".OX", "OXO", "XO.",
        "OOO", "XX.", "X.."
    };

    for (int i = 0; i < boards.size(); i += 3) {
        vector<string> board = {boards[i], boards[i + 1], boards[i + 2]};
        int result = solution(board);
        cout << "Result " << i / 3 + 1 << ": " << result << endl;
    }

    return 0;
}