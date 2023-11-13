#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int find(int n) {
    int ret = 0;
    while(n) {
        if (n%2 == 1)
            ret++;            
        n /= 2;
    }
    return ret;
}

int solution(int n) {
    int cmp1 = find(n);
    while(1) {
        n++;
        int cmp2 = find(n);
        if (cmp1 == cmp2)
            break ;
    }

    return n;
}

int main() {
    cout << solution(15);
}