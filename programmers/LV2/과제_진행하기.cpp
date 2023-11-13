#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int time_modify(const string& t) {
    int hours = stoi(t.substr(0, 2));
    int minutes = stoi(t.substr(3, 2));
    return hours * 60 + minutes;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string,int>> waitTesk;
    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1];
    });
    
    int time=0;
    
    for(vector<string> v : plans){
        int newTime= time_modify(v[1]);
        
        while( time < newTime ) {
            if(waitTesk.size() > 0 ){
                waitTesk.back().second--;
                if(waitTesk.back().second==0){
                    answer.push_back(waitTesk.back().first);
                    waitTesk.pop_back();
                }
            }
            time++;
        }  
        
        waitTesk.push_back({v[0],stoi(v[2])});
    }
    while(waitTesk.size()>0){
        answer.push_back(waitTesk.back().first);
        waitTesk.pop_back();
    }
    return answer;
}