// Problem: 一个简单的整数问题2
// Author : xiaoqiuuuu
// URL: https://www.acwing.com/problem/content/244/


#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	auto lowbit = [&](int x){
		return x & - x ;
	};
	auto add = [&](auto &tr , int x , LL c){
		for(int i = x ; i < tr.size() ; i += lowbit(i))
			tr[i] += c;
	};
	auto sum = [&](auto &tr ,int x){
		LL res = 0;
		for(int i = x ; i ; i -= lowbit(i))
			res += tr[i];
		return res;
	};
	auto prefix_sum = [&](auto &tr1 , auto &tr2 ,int x){
		return sum(tr1, x) * (x + 1) - sum(tr2 , x);
	};
	
	int n , m ;cin >> n >> m;
	vector<LL> a(n + 2 , 0);
	LL x ;
	for(int i = 1 ; i <= n ; i ++ )
		cin >> x , a[i] += x , a[i + 1] -= x;
		
	vector<LL> tr1(n + 1 , 0) , tr2(n + 1 , 0);
	
	for(int i =1 ; i <= n ; i ++ )
	{
		tr1[i] += a[i],tr2[i] += i * a[i];
		if(i + lowbit(i) <= n)
			tr1[i + lowbit(i)] += tr1[i],tr2[i + lowbit(i)] += tr2[i];
	}
	
	while(m -- )
	{
		string op;cin >> op;
		if(op == "Q")
		{
			int l , r ;cin >> l >> r ;
			
			cout << prefix_sum(tr1 , tr2 , r) - prefix_sum(tr1 , tr2 ,l - 1) << "\n";
			
		}
		else 
		{
			LL   l , r , x ;cin >> l >> r >> x;
			add(tr1 , l , x) , add(tr1 ,r + 1 , - x);
			add(tr2 , l , l * x) , add(tr2 , r + 1 , (l + 1) * -x);
		}
	}
	
	
	
	return 0 ;
}