#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int arr[10011];

int solution(int n) {
    for (int i = 1; i <= n; i++) {
        int cmp = i;
        for (int j = i; cmp <= n; j++, cmp += j) {
            arr[cmp]++;
        }
    }
    return arr[n];
}

int main() {
    cout << solution(18);
}