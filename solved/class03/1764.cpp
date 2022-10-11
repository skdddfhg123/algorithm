#include "bits/stdc++.h"
using namespace std;

map<string, int> m;
vector<string> v;

int N, M;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N + M; i++) {
		cin >> tmp;
		m[tmp]++;
		if (m[tmp] == 2)
			v.push_back(tmp);
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}