#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	vector<string> v;
	map<string, int> poke;
	string tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		v.push_back(tmp);
		poke.insert(pair(tmp ,i));
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (tmp[0] >= '0' && tmp[0] <= '9')
			cout <<  v[stoi(tmp) - 1] << '\n';
		else
			cout << poke[tmp] << '\n';
	}
}