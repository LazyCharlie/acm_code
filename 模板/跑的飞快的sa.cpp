const int maxn = (int)1e6 + 1, maxn2 = maxn << 1 | 1;
int t, n, seq[maxn2], sa[maxn], rk[maxn], ht[maxn], ctr[maxn], pos[maxn], *cur = ht;
bool typ[maxn2];
inline void pushS(int seq[], int x) {
	sa[cur[seq[x]]--] = x;
}
inline void pushL(int seq[], int x) {
	sa[cur[seq[x]]++] = x;
}
inline void inducedSort(int n, int m, int seq[], bool typ[], int n1, int v[]) {
	memset(sa, -1, n * sizeof(int));
	memset(ctr, 0, m * sizeof(int));
	for(int i = 0; i < n; ++i)
		++ctr[seq[i]];
	for(int i = 1; i < m; ++i)
		ctr[i] += ctr[i - 1];
	for(int i = 0; i < m; ++i)
		cur[i] = ctr[i] - 1;
	for(int i = n1 - 1; i >= 0; --i)
		pushS(seq, v[i]);
	for(int i = 1; i < m; ++i)
		cur[i] = ctr[i - 1];
	for(int i = 0; i < n; ++i)
		if(sa[i] > 0 && typ[sa[i] - 1])
			pushL(seq, sa[i] - 1);
	for(int i = 0; i < m; ++i)
		cur[i] = ctr[i] - 1;
	for(int i = n - 1; i >= 0; --i)
		if(sa[i] > 0 && !typ[sa[i] - 1])
			pushS(seq, sa[i] - 1);
}
inline void sais(int n, int m, int seq[], bool typ[], int pos[]) {
	int n1 = typ[n - 1] = 0, ch = rk[0] = -1, *seq1 = seq + n;
	for(int i = n - 2; i >= 0; --i)
		typ[i] = seq[i] == seq[i + 1] ? typ[i + 1] : (seq[i] > seq[i + 1]);
	for(int i = 1; i < n; ++i)
		rk[i] = typ[i - 1] && !typ[i] ? (pos[n1] = i, n1++) : -1;
	inducedSort(n, m, seq, typ, n1, pos);
	for(int i = 0, j, k, x, y; i < n; ++i) {
		if((x = rk[sa[i]]) < 0)
			continue;
		if(ch < 1 || pos[x + 1] - pos[x] != pos[y + 1] - pos[y])
			++ch;
		else
			for(j = pos[x], k = pos[y]; j <= pos[x + 1]; ++j, ++k)
				if((seq[j] << 1 | typ[j]) != (seq[k] << 1 | typ[k])) {
					++ch;
					break;
				}
		seq1[y = x] = ch;
	}
	if(ch + 1 < n1)
		sais(n1, ch + 1, seq1, typ + n, pos + n1);
	else
		for(int i = 0; i < n1; ++i)
			sa[seq1[i]] = i;
	for(int i = 0; i < n1; ++i)
		seq1[i] = pos[sa[i]];
	inducedSort(n, m, seq, typ, n1, seq1);
}
inline void SuffixArray() {
	int m = 101;
	memset(ctr, 0, m * sizeof(int));
	for(int i = 0; i <= n; ++i)
		ctr[seq[i]] = 1;
	for(int i = 1; i < m; ++i)
		ctr[i] += ctr[i - 1];
	for(int i = 0; i <= n; ++i)
		seq[i] = ctr[seq[i]] - 1;
	sais(n + 1, ctr[m - 1], seq, typ, pos);
	for(int i = 0; i < n; ++i)
		rk[sa[i] = sa[i + 1]] = i;
	for(int i = 0, j, k = ht[0] = 0; i < n; ++i) {
		if(k)
			--k;
		if(!rk[i])
			continue;
		for(j = sa[rk[i] - 1]; seq[i + k] == seq[j + k]; ++k);
		ht[rk[i]] = k;
	}
}
