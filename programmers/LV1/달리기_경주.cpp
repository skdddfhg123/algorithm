#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }
    for (int i = 0; i < callings.size(); i++) {
        int idx = m[callings[i]];
        m[players[idx - 1]]++;
        m[callings[i]]--;
        swap(players[idx - 1], players[idx]);
    }
    return players;
}