#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> check;

int solution(vector<vector<string>> clothes) {
	for (int i = 0; i < clothes.size(); i++) {
		check[clothes[i][1]]++;
	}
	int answer = 1;
	for (auto it = check.begin(); it != check.end(); it++)
		answer *= it->second + 1;
	return answer - 1;
}
