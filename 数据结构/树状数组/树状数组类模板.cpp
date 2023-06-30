class Fenwick {

	vector<int> tr;
	int n;
public:
	Fenwick(int x) {
		tr = vector<int>(x + 1, 0);
		n = x;
	}
	Fenwick(vector<int>& a) {
		n = a.size() - 1;
		tr = vector<int>(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			tr[i] += a[i];
			int j = i + lowbit(i);
			if (j <= n)
				tr[j] += tr[i];
		}
	}
	void add(int x, int c) {
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}
	int sum(int x) {
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
	void debug(){
		for(int i = 1 ; i <= n ; i ++ )
			cout << tr[i] << " ";
		cout << "\n";
	}

private:
	int lowbit(int x) {
		return x & -x;
	}

};

