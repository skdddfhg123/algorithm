#include <vector>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

bool vis[200001];

int solution(vector<int> nums)
{
	memset(vis, 0, sizeof(vis));
	int answer = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (!vis[nums[i]] && answer+1 <= nums.size()/2) {
			vis[nums[i]] = 1;
			answer++;
		}
	}

	return answer;
}
