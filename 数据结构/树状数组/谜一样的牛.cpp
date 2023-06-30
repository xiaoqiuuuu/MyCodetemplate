#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n ;
	cin >> n;
	vector<int> b(n + 1);
	for(int i = 2 ; i <= n ; i ++ )
		cin >> b[i];
	vector<int>	tr(n + 1 );

	auto lowbit = [](int x){
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
		tr[i] = lowbit(i);
	
	vector<int> ans(n + 1 );
	for(int i = n ; i >= 1 ; i -- )
	{
		int k = b[i] + 1;
		int l = 1 , r = n ; 
		while(l < r)
		{
			int mid = l + r >> 1;
			if(sum(mid) >= k )r = mid;
			else l = mid + 1;
		}
		
		ans[i] = l ;
		add(l , - 1);
	}
	
	for(int i = 1 ; i <= n ; i ++ )
		cout << ans[i] << "\n";
	cout << "\n";
	
	return 0;
}