#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int>check;

bool solution(vector<string> phone_book) {
	bool answer = true;
	for ( int i = 0; i < phone_book.size(); i++)
		check[phone_book[i]] = 1;
	for (int i = 0; i < phone_book.size(); i++) {
		string tmp = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			tmp += phone_book[i][j];
			if (check[tmp] && tmp != phone_book[i])
				answer = false;
		}
	}
	return answer;
}