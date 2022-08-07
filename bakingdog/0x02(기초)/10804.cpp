#include <bits/stdc++.h>
using namespace std;

int n, tmp, m, y;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		y += ((tmp / 30) * 10) + 10;
		m += ((tmp / 60) * 15) + 15;
	}
	if (m < y)
		cout << "M " << m;
	else if (m > y)
		cout << "Y " << y;
	else
		cout << "Y M " << m;
}