#include<bits/stdc++.h>
using namespace std;
char s[5][20] = { "forward","left","right","dig" };
bool step(bool st)
{
	char str[10];
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		puts(s[0]);
		fflush(stdout);
		scanf("%s", str);
		if (str[0] != 'f') {
			if (st)return true;
			else flag = 1;
		}
		//moveback and turn to a new direction
		puts(s[1]);
		fflush(stdout);
		puts(s[1]);
		fflush(stdout);
		puts(s[0]);
		fflush(stdout);
		scanf("%s", str);
		puts(s[2]);
		fflush(stdout);
	}
	return flag;
}
bool forward()
{
	char str[10];
	puts(s[0]);
	fflush(stdout);
	scanf("%s", str);
	return str[0] == 'f';
}
vector<int>ans;
int main()
{
	while (step(1));
	ans.push_back(forward());
	while (step(0)) {
		ans.push_back(forward());
	}
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 1)cnt++;
	}
	if (cnt * 2 > ans.size()) {
		forward();
		while (step(0))forward();
		puts(s[3]);
		fflush(stdout);
		return 0;
	}
	else {
		puts(s[3]);
		fflush(stdout);
		return 0;
	}
}