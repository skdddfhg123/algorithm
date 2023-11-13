#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int y = board.size();
    int x = board[0].size();

    for (int i = 1; i < y; i++) {
        for (int j = 1; j < x; j++) {
            if (board[i][j] == 1) {
                board[i][j] = 1 + min({board[i - 1][j - 1],board[i][j - 1],board[i - 1][j] });
                answer = max(answer,board[i][j] * board[i][j]);
            }
        }
    }

    return answer;
}