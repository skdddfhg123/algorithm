#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> check;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	for (auto c : completion)
		check[c] += 1;
	for (auto res: participant) {
		check[res] -= 1;
		if (check[res] < 0)
			return res;
	}
}