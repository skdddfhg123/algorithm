#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int idx = 0;
    int max = health;
    int casting = 0;
    int end_t = attacks[attacks.size() - 1][0];
    for (int t = 0; t <= end_t; t++) {
        if (attacks[idx][0] == t) {
            casting = 0;
            health -= attacks[idx++][1];
            cout << "t=" <<t<<"/attacked health :" << health << '\n';
            if (health <= 0)
                return -1;
        } else {
            if (++casting == bandage[0]) {
                if (health + bandage[1] + bandage[2] <= max)
                    health += bandage[1] + bandage[2];
                else
                    health = max;
                casting = 0;
            } else {
                if (health + bandage[1] <= max)
                    health += bandage[1];
                else
                    health = max;
            }
        }
        cout << "t=" <<t<<"/health :" << health << '\n';
    }

    return health;
}