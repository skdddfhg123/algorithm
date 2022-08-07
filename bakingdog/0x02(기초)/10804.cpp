#include <bits/stdc++.h>
using namespace std;

int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16 ,17 ,18 ,19, 20};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int f, s;
	for (int i = 0; i < 10; i++) {
		cin >> f >> s;
		if (f > s)
			swap(f, s);
		else if (f == s)
			continue ;
		else {
			int dif = s - f + 1;
			for (int j = 0; j < dif/2; j++) {
				int tmp = arr[f - 1 + j];
				arr[f - 1 + j] = arr[s - 1 - j];
				arr[s - 1 - j] = tmp;
			}
		}
	}
	for (int i = 0; i < 20; i++)
		cout << arr[i] << " ";
}