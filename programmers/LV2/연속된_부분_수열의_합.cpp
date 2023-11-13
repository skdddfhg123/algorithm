#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    int st = 0, end = 0;
    int len = sequence.size();
    int sum = sequence[0];
    pair<int, int> res;
    while (st <= end && end < sequence.size()) {
        if (sum < k)
            sum += sequence[++end];
        else if (sum == k) {
            if (end - st < len) {
                len = end - st;
                res = {st, end};
            }
            sum -= sequence[st++];
        }
        else
            sum -= sequence[st++];
    }


    return {res.first, res.second};
}