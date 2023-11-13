#include <string>
#include <vector>

using namespace std;

long long dp[2001] = {0, 1, 2, 3, 5, };

long long solution(int n) {
    long long answer = 0;
    for (int i = 3; i < 2001; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
    }
    
    return dp[n];
}