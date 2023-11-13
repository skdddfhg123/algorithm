#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int dp[60001] = {0,1,2,3,5,8,};


int solution(int n) {
    int answer = 0;
    for (int i = 3; i < 60001; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
    answer = dp[n];
    return answer;
}

int main() {
    cout << solution(6) << '\n';
}