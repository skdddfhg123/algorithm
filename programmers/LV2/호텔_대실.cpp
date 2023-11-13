#include <string>
#include <vector>

using namespace std;
int arr[1450];

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    for (int i = 0; i < book_time.size(); i++) {
        int start_t = stoi(book_time[i][0].substr(0, 2)) * 60 +
                      stoi(book_time[i][0].substr(3, 2));
        int end_t = stoi(book_time[i][1].substr(0, 2)) * 60 +
                    stoi(book_time[i][1].substr(3, 2)) + 10;
        for (int j = start_t; j < end_t; j++)
            arr[j]++;
    }

    for (int i = 0; i < 1440; i++) 
        answer = max(answer, arr[i]);

    return answer;
}

int main() {
    // vector<vector<string>> input1 = {{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};
    // int result1 = solution(input1);
    // cout << "Result 1: " << result1 << endl; // Expected output: 3

    // vector<vector<string>> input2 = {{"09:10", "10:10"}, {"10:20", "12:20"}};
    // int result2 = solution(input2);
    // cout << "Result 2: " << result2 << endl; // Expected output: 1

    vector<vector<string>> input3 = {{"10:20", "12:30"}, {"10:20", "12:30"}, {"10:20", "12:30"}};
    int result3 = solution(input3);
    cout << "Result 3: " << result3 << endl; // Expected output: 3

    return 0;
}