#include <bits/stdc++.h>

using namespace std;

int T, n;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		bool check = 0, e_check = 0;
		string order, arr;
		deque<int> dq;
		cin >> order >> n >> arr;
		string tmp = "";
		for (int i = 0; i < arr.length(); i++) {
			if (isdigit(arr[i]))
				tmp += arr[i];
			else {
				if (!tmp.empty()) {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}
		for (int i = 0; i < order.length(); i++) {
			if (order[i] == 'R') {
				if (check)
					check = 0;
				else 
					check = 1;
			}
			else {
				if (dq.empty()) {
					cout << "error\n";
					e_check = 1;
					break ; 
				}
				if (check)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if (!e_check) {
			cout << "[";
			int size = dq.size();
			if (!check) 
				for (int i = 0; i < size; i++) {
					if (i != size - 1)
						cout << dq[i] << ',';
					else
						cout << dq[i];
				}
			else
				for (int i = 0; i < size; i++) {
					if (i != size - 1)
						cout << dq[size - i - 1] << ',';
					else
						cout << dq[size - i - 1];
				}
			cout << "]\n";
		}
	}
}