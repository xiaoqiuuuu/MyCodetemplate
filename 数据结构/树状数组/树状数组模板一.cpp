// Problem: 
//     P3374 【模板】树状数组 1
//   
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P3374


#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;

template<typename T = int>
class Fenwick{
public:
    const int n;
    vector<T> a;
    Fenwick(int n) : n(n), a(n + 1){}
    void add(int x, T val) {
        for(int i = x; i <= n; i += i & -i) 
            a[i] += val;
    }
    T sum(int x) {
        T res = 0;
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }
    T rangesum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	
	int n, m ; cin >> n >> m;
	//vector<int> tr(n + 1, 0);
	
	Fenwick tr(3e5 + 10);
    
	
	
	

	
	
	return 0;
}
