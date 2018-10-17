#include<bits/stdc++.h>
using namespace std;
int h, w;
char  s[506][505];
int vis[506][506];
const int dx[4] = { 1,0,0,-1 };
const int dy[4] = { 0,1,-1,0 };
void dfs(int x, int y)
{
	if (vis[x][y])return;
	vis[x][y] = 1;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (s[nx][ny] == '.') {
			dfs(nx, ny);
			if (i == 0)break;
		}
	}
}
int main()
{
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < w; i++) {
		if (s[0][i] == '.')dfs(0, i);
	}
	int ok = 0;
	for (int i = 0; i < h && !ok; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.' && !vis[i][j]) {
				ok = 1;
				s[i][j] = 'X';
				break;
			}
		}
	}
	if (ok) {
		printf("Yes\n");
		for (int i = 0; i < h; i++) {
			printf("%s\n", s[i]);
		}
	}
	else printf("No\n");
}