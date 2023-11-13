#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        int ret = 1;
        for (long long j = 2; sqrt(i) >= j; j++) {
            if (i % j == 0) {
                ret = j;
                // cout << ret << "   j : " << j << '\n';
                if (i / j <= 10000000) {
                    ret = i / j;
                    break ;
                }
            }
        }
        answer.push_back(ret);
    }
    return answer;
}


int main() {
    vector<int> v = solution(50, 60);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ',';
    }
    // double num = 25.0;
    // double squareRoot = sqrt(num);

    // std::cout << "Square root of " << num << " is: " << squareRoot << std::endl;

    return 0;
}