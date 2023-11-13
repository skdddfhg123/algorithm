#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string two[5] = {"", "RR", "Rr", "Rr", "rr"};


vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for (int i = 0; i < queries.size(); i++) {
        int n = queries[i][1];
        if (queries[i][0] == 2)
            answer.push_back(two[queries[i][1]]);
        else if (queries[i][1] <= pow(4, queries[i][0] - 2)) {
            answer.push_back("RR");
            cout << "RR\n";
        }
        else if (queries[i][1] >= (pow(4, queries[i][0] - 1) - pow(4, queries[i][0] - 2))) {
            answer.push_back("rr");
            cout << "rr\n";
        }
        else {
            for (; n > 4; ) {
                int tmp = n % 4;
                n /= 4;
                // cout << "tmp : " << tmp << '\n';
                // cout << "n : " << n << '\n';
                if (tmp == 1) {
                    answer.push_back("RR");
                    // cout << "RR\n";
                    break ;
                } else if (tmp == 0) {
                    answer.push_back("rr");
                    // cout << "rr\n";
                    break ;
                } else if (n < 4) {
                    answer.push_back("Rr");
                    // cout << "Rr\n";
                }
            }
        }
    }
    return answer;
}


int main() {
    vector<vector<int>> queries = {{4, 26}};
    solution(queries);
}