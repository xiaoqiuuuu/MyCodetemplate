#include<bits/stdc++.h>

using namespace std;
using LL = long long ;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n ;cin >> n ;
	vector<int>a(n + 1) , Greater(n + 1 , 0 ) , lower(n + 1 , 0 ) , tr(n + 1, 0);
	
	auto lowbit = [&](int x){
		return x & -x ;
	};
	auto add =[&] (int x , int c){
		for(int i = x ; i <= n ; i += lowbit(i))
			tr[i] += c;
	};
	auto sum = [&] (int x){
		LL res = 0 ;
		for(int i = x ; i ; i -= lowbit(i))
			res += tr[i];
		return res;
	};
	
	
	for(int i = 1 ; i <= n ; i ++ )
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++ )
	{
		int y = a[i];
		Greater[i] = sum(n) - sum(y);
		lower[i] = sum(y - 1);
		add(y , 1);
	}
	
	tr = vector<int>(n + 1 , 0 );
	
	LL res1 = 0 , res2 = 0 ;
	for(int i = n ; i >= 1 ; i  --)
	{
		int y = a[i];
		res1 += Greater[i] * (LL)(sum(n) - sum(y));
		res2 += lower[i] * (LL)sum(y - 1);
		add(y , 1 );
	}
	cout << res1 << " " << res2 << "\n";
	
	return 0;
}