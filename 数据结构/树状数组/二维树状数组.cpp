struct Two_Fenwick {
	typedef long long LL;
	vector<vector<LL>>tr;
	int n, m;
	Two_Fenwick(int n, int m){
		this->n = n, this->m = m;
		tr = vector<vector<LL>>(n + 1, vector<LL>(m + 1));
	}
	void add(int x, int y, int c){
		for (int i = x; i <= n; i += lowbit(i))
			for (int j = y; j <= m; j += lowbit(j))
				tr[i][j] += c;
	}
	LL sum(int x, int y) {
		LL res = 0;
		for (int i = x; i; i -= lowbit(i))
			for (int j = y; j; j -= lowbit(j))
				res += tr[i][j];
	}
	int lowbit(int x) {
		return x & -x;
	}
};
