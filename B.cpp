#include<bits/stdc++.h>
using namespace std;
int T, N;
vector<string>s;
string tmp;
int main()
{
	cin.sync_with_stdio(0);
	cin >> T;
	while (T--) {
		s.clear();
		cin >> N;
		int id = 0;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			s.push_back(tmp);
			if (i&&s[i].size() > s[id].size())id = i;
		}
		int ok = 1;
		for (int i = 0; i < s.size() && ok; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] != s[id][j]) {
					ok = 0;
					break;
				}
			}
		}
		if (!ok) {
			printf("Impossible\n");
		}
		else printf("%d\n", s[id].size());
	}
}