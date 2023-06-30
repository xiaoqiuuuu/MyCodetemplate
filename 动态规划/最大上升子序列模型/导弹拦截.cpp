// Problem: 拦截导弹
// Author : xiaoqiuuuu
// URL: https://www.acwing.com/problem/content/1012/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int x ;vector<int> h;
	while(cin >> x)h.push_back(x);
	
	int n = h.size() ;
	vector<int> f(n + 1 , 1);
	for(int i = 0 ; i < n ; i ++ )
		for(int j = 0 ; j < i ; j ++ )
			if(h[j] <= h[i])
				f[i] = max(f[i] , f[j] + 1);
		
	vector<int> down = {h[0]};		
	for(int i = 1 ; i < n ; i ++ )
	{
		int x = h[i] ; //尽量选择刚好大于当前导弹的系统
		int k = 0 ;
		while(k < down.size() && x > down) k ++ ;
		if(k == down.size()) down.push_back(x);
		else down[k] = x ;		
	}
	cout << f[max_element(f.begin() , f.end()) - f.begin()] << "\n";
	cout << down.size() << "\n";
	
	
	return 0;
}
