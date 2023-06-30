// Problem: 
//     P2471 [SCOI2007] 降雨量
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P2471


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 200010;

int n , m ;

unordered_map<int ,int> year;

struct Node{
    int l , r , v ;
}tr[N << 2];

vector<int> yx = {-0x3f3f3f3f};

int id(int x){
    return lower_bound(yx.begin() , yx.end() , x) - yx.begin();
}

bool check(int year)
{
    if(id(year) < yx.size() && yx[id(year)] == year )return true;
    return false;
}

void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v , tr[u << 1 | 1].v);
}

void build(int u , int l , int r)
{
    tr[u] = {l , r};
    if(l == r)tr[u].v = year[yx[l]];
    else
    {
        int mid = l + r >> 1;
        build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
        pushup(u);
    }
}

int query(int u ,int l , int r)
{
    if(l > r)return -0x3f3f3f3f;
    
   // cout<<tr[u].l<<' '<<tr[u].r<<' '<<tr[u].v<<'\n';
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].v;
    else
    {
        int res = 0 ;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)res = query(u << 1 , l , r);
        if(r > mid)res = max(res , query(u << 1 | 1 , l , r));
        return res;
    }
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    cin >> n; 
    for(int i = 1 ; i <= n ; i ++ ) 
	{
	    int x , y ;
	    cin >> x >> y;  
	    year[x] = y ;
	    yx.push_back(x);
	}
	
	sort(yx.begin() , yx.end());
    yx.erase(unique(yx.begin() , yx.end()) , yx.end());
	
	build(1 , 1 , yx.size() - 1);
	
    cin >> m ;
    while(m -- )
    {
        int year1, year2;
        cin >> year2 >> year1;
        if(check(year1) && check(year2))
        {
            
            if(year[year2] > year[year1] && query(1 , id(year2) + 1 , id(year1) - 1) < year[year1])
            {
                if(year1 - year2 == id(year1) - id(year2))cout << "true\n";
                else cout << "maybe\n";
            }
            else cout << "false\n";

        }
        else if(check(year1) && !check(year2))
        {
            if(year[year1] > query(1 , id(year2)  , id(year1) - 1))cout << "maybe\n";
            else cout << "false\n";
        }
        else if(!check(year1) && check(year2))
        {
            if(year[year2] <= query(1 , id(year2) + 1 , id(year1) - 1))cout << "false\n";
            else cout << "maybe\n";
        }
        else cout << "maybe\n";   
    }
	
	return 0;
}
