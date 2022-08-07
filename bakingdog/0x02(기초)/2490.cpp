#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp, check;
	for (int i = 0; i < 3; i++) {
		check = 0;
		for (int i = 0; i < 4; i++) {
			cin >> tmp;
			if (tmp)
				check++;
		}
		if (check == 1)
			cout << "C\n";
		else if (check == 2)
			cout << "B\n";
		else if (check == 3)
			cout << "A\n";
		else if (check == 4)
			cout << "E\n";
		else
			cout << "D\n";
	}
}