#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push('(');
        }
        else if (!st.empty() && s[i] == ')' && st.top() == '(') {
            st.pop();
        }
        else
            answer = false;
    }
    if (!st.empty())
        answer = false;
        
    return answer;
}

int main() {
    cout << solution(")()(");
}