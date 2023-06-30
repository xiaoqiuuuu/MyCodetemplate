#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

void solve()
{
    int n ;
    cin >> n ;
    
    priority_queue<int>q1 ;
    priority_queue<int , vector<int> , greater<int>> q2;
    
    for(int i = 1 ; i <= n ; i ++ )
    {
        int x ; cin >> x ;
        if(q1.empty() || x < q1.top())q1.push(x);
        else q2.push(x);
        
        if(q1.size() > q2.size() + 1)q2.push(q1.top()) ,q1.pop();
        if(q2.size() > q1.size() + 1)q1.push(q2.top()) ,q2.pop();
        
        if(i & 1)
        {
            cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << "\n";
        }
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
