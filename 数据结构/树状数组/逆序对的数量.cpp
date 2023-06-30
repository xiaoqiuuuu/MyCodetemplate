// Problem: 逆序对的数量
// Author : xiaoqiuuuu
// URL: https://www.acwing.com/problem/content/790/

#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n ;cin >> n;
	vector<int> a(n + 1);
	for(int i = 1 ; i <= n ; i ++ )
		cin >> a[i];
	auto b = a ;
	sort(b.begin() , b.end());
	b.erase(unique(b.begin() , b.end()) , b.end());
	
	int m = b.size() - 1;
	
	vector<int> tr(m + 1 , 0);
	
	auto id = [&](int x){
		int l = 1, r = m;
	    while(l < r)
	    {
	        int mid = l + r >> 1;
	        if(b[mid] >= x)r = mid;
	        else l = mid + 1;
	    }
    		return l;
	};
	
	auto lowbit = [&](int x){
		return x & - x;
	};
	auto add = [&] (int x ,int c){
		for(int i = x ; i <= m ; i += lowbit(i))
			tr[i] += c;
	};
	auto sum = [&](int x )->LL{
		LL res = 0;
		for(int i = x ; i ; i -= lowbit(i))
			res += tr[i];
		return res;
	};
	
	LL res = 0 ;
	for(int i = 1 ; i <= n ; i ++ )
	{
		int t = id(a[i]);
		res += sum(m) - sum(t);
		add(t , 1);
	}
	
	cout << res << "\n";
	return 0 ;
}