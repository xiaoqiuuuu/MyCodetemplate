// Problem: 
//     P1328 [NOIP2014 提高组] 生活大爆炸版石头剪刀布
//   
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P1328


#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;
//const int N = 1e5 +10;  

void solve()
{
	int n , na , nb;
	cin >> n >> na >> nb;
	
	int g[6][6] ={
		{2 ,0 ,1 ,1 ,0},
		{1 ,2 ,0 ,1 ,0},
		{0 ,1 ,2 ,0 ,1},
		{0 ,0 ,1 ,2 ,1},
		{1 ,1 ,0 ,0 ,2}};
	
	auto check = [&](int a ,int b){
		return g[a][b];
	};
	
	
	
	vector<int>a(na) , b(nb);
	for(int i = 0 ; i < na ; i ++ )
		cin >> a[i] ;
	for(int i = 0 ; i < nb ; i ++ )
		cin >> b[i];
		
	vector<int> cnt(3 , 0 );
	for(int i = 0 ; i < n ; i ++ )
		cnt[check(b[i % nb] ,a[i % na])]++;
	cout << cnt[0] <<" " << cnt[1] << "\n";
	
	return ;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tt = 1;
//cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
