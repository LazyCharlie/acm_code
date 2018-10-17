
int p[maxn * 2], T;
char Ma[maxn * 2];
void Manacher(char s[], int len) {
	int l = 0;
	Ma[l++] = '$';
	Ma[l++] = '#';
	for (int i = 0; i < len; i++) {
		Ma[l++] = s[i];
		Ma[l++] = '#';
	}
	Ma[l] = 0;
	int pos = 0, R = 0;
	for (int i = 0; i < l; i++) {
		if (i < R)p[i] = min(p[pos * 2 - i], R - i);
		else p[i] = 1;
		while (Ma[i + p[i]] == Ma[i - p[i]])p[i]++;
		if (i + p[i] > R) R = i + p[i], pos = i;
	}
}