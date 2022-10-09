#include <bits/stdc++.h>
using namespace std;

bool m_check;
int ret;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, tmp;
	int b = 0, c = 0, p_num = 0, m_num = 0;
	cin >> a;
	if (a[0] == '-')
		m_check = 1;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '+' && !m_check) {
			p_num += stoi(tmp);
			tmp = "";
		}
		else if (a[i] == '+' && m_check) {
			m_num += stoi(tmp);
			tmp = "";
		}
		else if (a[i] == '-' && !m_check) {
			p_num += stoi(tmp);
			m_check = 1;
			tmp = "";
		}
		else if (a[i] == '-' && m_check) {
			m_num += stoi(tmp);
			tmp = "";
		}
		else {
			tmp += a[i];
		}
	}
	if (m_check)
		m_num += stoi(tmp);
	else
		p_num += stoi(tmp);
	ret = p_num - m_num;
	cout << ret;
}
