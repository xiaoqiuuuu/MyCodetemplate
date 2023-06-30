#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

void solve()
{
    int n , k ;
    cin >> n >> k ; 
    
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++ )
        cin >> a[i];

    deque<int> q;
    for(int i = 0 ; i < n ; i ++ )
    {
        while(q.size() && a[q.back()] >= a[i])q.pop_back();
        q.push_back(i);
        if(i - q.front() >= k) q.pop_front();
        if(i >= k - 1)cout << a[q.front()] << " ";
    }
    
    cout << "\n";
    
    q.clear();
    for(int i = 0 ; i < n ; i ++ )
    {
        while(q.size() && a[q.back()] <= a[i])q.pop_back();
        q.push_back(i);
        if(i - q.front() >= k) q.pop_front();
        if(i >= k - 1)cout << a[q.front()] << " ";
    }
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	//cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
