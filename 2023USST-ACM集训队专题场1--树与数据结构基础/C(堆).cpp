#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

struct Heap{
    int n;
    vector<int> p;
    Heap(int n) : n(n) ,p(n + 1){}
     
    int query(){
        return p[1];
    }
    void pop(){
        if(n < 1)return;
        p[1] = p[n --] ;
        p.pop_back();
        down(1);
    }
    void add(int x){
        p.push_back(x);
        n ++ ;
        up(n);
    }
    void up(int u){
        while(u / 2 && p[u / 2] > p[u])
        {    
            swap(p[u] , p[u / 2]);
            u >>= 1;
        }
    }
    void down(int u){
        int t = u ;
        if(u * 2 <= n && p[t] > p[2 * t]) t = 2 * u;
        if(u * 2 + 1 <= n && p[t] > p[u * 2 + 1]) t = 2 * u + 1;
        if(u != t)
        {
            swap(p[u] , p[t]);
            down(t);
        }   
    }
};


void solve()
{
    int n ;
    cin >> n ;
    
    Heap heap(0);
    
    while(n -- )
    {
         int op , x;
         cin >> op ;
         
         if(op == 1)cin >> x , heap.add(x);
         else if(op == 2)cout << heap.query() << "\n";
         else heap.pop();   
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
