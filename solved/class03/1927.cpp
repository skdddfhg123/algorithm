#include <bits/stdc++.h>

using namespace std;

int N, x;
priority_queue<int , vector<int>, greater<int>>pq;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}