#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	cin >> tmp;
	if (tmp % 4 == 0 && 
	((tmp % 100 != 0) || 
	(tmp % 400 == 0)))
		cout << "1";
	else
		cout << "0";
}