#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> check_g;
vector<pair<int ,int>> check_p[10001];

vector<int> solution(vector<string> genres, vector<int> plays) {
	for (int i =0; i< genres.size(); i++) {
		check_g[genres[i]]+= plays[i];
	}
	vector<int> answer;
	return answer;
}