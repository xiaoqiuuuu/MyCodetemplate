// Problem: 
//     P3368 【模板】树状数组 2
//   
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P3368


#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n , m; cin >> n >> m ;
	vector<int> a(n + 2 , 0), tr(n + 2 );
	
	auto lowbit = [&](int x){
		return x & - x;
	};
	
	auto add = [&](int x , int c){
		for(int i = x ; i <= n ; i += lowbit(i))
			tr[i] += c;
	};
	
	auto sum = [&](int x) ->int {
		int res = 0;
		for(int i = x ; i ; i -= lowbit(i))
			res += tr[i];
		return res;
	};
	
	for(int i = 1 ; i <= n ; i ++ )
	{
		tr[i] += a[i];
		int j = i + lowbit(i);
		if(j <= n) tr[j] += tr[i];
	}
	
	while(m -- )
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int l , r , k;
			cin >> l >> r >> k ;
			add(l , k) ,add(r + 1 , - k);
		}
		else 
		{
			int k ;cin >> k;
			int res = 0 ,flg = 1;
			for(int i = 0 ; i < k ; i ++ )
			{
				int x ; cin >> x ;
				if(sum(x) == 0)
				{
					flg = 0;
					break;
				}
				else res ++;
			}
			if(flg) cout << k << "\n";
			else cout << "-1\n";
		}
	}
	
	
	return 0;
}