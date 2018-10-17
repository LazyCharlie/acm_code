struct hashmap
{
	static const int mask = 999961;
	int q[mask + 1], p[mask + 1];
	void clear() { memset(q, 0, sizeof(q)); }
	int & operator[](int k)
	{
		int i;
		for (i = k & mask; q[i] && p[i] != k; i = (i + 1)&mask);
		p[i] = k;
		return q[i];
	}
};