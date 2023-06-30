#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector<double> yx;

struct Seg{
    double x , y1 , y2;
    int k ;
    
    bool operator < (const Seg &t)const{
        return x < t.x;
    }
    
}seg[N << 1];

struct Node{
    int l , r , cnt ;
    double len;
}tr[N << 3];

int id(double x)
{
    return lower_bound(yx.begin() , yx.end() , x) - yx.begin();
}

void build(int u , int l , int r)
{
    tr[u] = {l , r , 0 , 0};
    if(l != r)
    {
        int mid = l + r >> 1;
        build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
    }
}

void pushup(int u)
{
    if(tr[u].cnt)tr[u].len = yx[tr[u].r + 1] - yx[tr[u].l];
    else if(tr[u].l != tr[u].r)tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    else tr[u].len = 0;
}

void modify(int u , int l , int r , int x)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += x ;
        pushup(u);
    }
    else
    {
        int mid =  tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r , x);
        if(r > mid)modify(u << 1 | 1 , l , r , x);
        pushup(u);
    }
}

double solve()
{
    yx.clear();
    for(int i = 0 , j = 0 ; i < n ; i ++ )
    {
        double x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        seg[j ++ ] = {x1 , y1 , y2 , 1};
        seg[j ++ ] = {x2 , y1 , y2 , -1};
        yx.push_back(y1) , yx.push_back(y2);
    }
    
    sort(yx.begin() , yx.end());
    yx.erase(unique(yx.begin() , yx.end()) , yx.end());
    
    sort(seg , seg + 2 * n);
    
    build(1 , 0 , yx.size() - 2);
    
    double ans = 0 ;
    for(int i = 0 ; i < 2 * n ; i ++ )
    {
        if(i > 0)ans += (seg[i].x - seg[i - 1].x) * tr[1].len;
        modify(1 , id(seg[i].y1) , id(seg[i].y2) - 1, seg[i].k);
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    while(cin >> n && n)
    {
        cout << "Test case #" << T++ << "\n";
        cout << "Total explored area: " << fixed << setprecision(2) << solve() << "\n\n";
    }
    return 0;
}