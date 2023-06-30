#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N =1e5 + 10 , M = 2 * N;


int dep[N] , son[N] , sz[N] , faz[N] , dfn[N] , rk[N] ,top[N] , tot;
int h[N] , e[M] , ne[M] , idx;
int n , m , r , p;
int w[N];

struct Node{
    int l ,r ;
    LL sum , add;
}tr[N << 2];

void pushup(int u) {
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void pushdown(Node &u , Node &l , Node &r) {
    l.add = (l.add + u.add) % p , r.add = (r.add + u.add) % p;
    l.sum += 1ll * (l.r - l.l + 1) * u.add % p;
    r.sum += 1ll * (r.r - r.l + 1) * u.add % p;
    u.add = 0;
}

void pushdown(int u) {
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void build(int u ,int l , int r) {
    tr[u] = {l , r };
    if(l == r) {
        tr[u] = {l , r , w[rk[r]] , 0};
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid) ;
    build(u << 1 | 1 , mid + 1 , r);
    pushup(u);
}

void add(int a , int b ) {
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs1(int u , int fa) {

    faz[u] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int j = e[i];
        if(j == fa) {
            continue;
        }
        dfs1(j , u);
        if(sz[son[u]] < sz[j]) {
            son[u] = j;
        }
        sz[u] += sz[j];
    }
    sz[u] += 1;
}

void dfs2(int u , int fa) {
    top[u] = fa;
    dfn[u] = ++ tot;
    rk[tot] = u;
    if(!son[u]) {
        return;
    }
    dfs2(son[u] , fa);
    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int j = e[i];
        if(j == faz[u] || j == son[u]) {
            continue;
        }
        dfs2(j , j);
    }
}

void modify(int u , int l , int r , int z ) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += 1ll * (tr[u].r - tr[u].l + 1 ) * z % p;
        tr[u].sum %= p;
        tr[u].add = (tr[u].add + z) % p;
        return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l) {
        modify(u << 1 , l ,r , z);
    } 
    if(r > mid) {
        modify(u << 1 | 1 , l , r , z);
    }
    pushup(u);
}

void add_path(int u , int v , int z) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) {
            swap(u , v);
        }
        modify(1 , dfn[top[u]] , dfn[u] , z);
        u = faz[top[u]];
    }
    if(dep[u] < dep[v]) {
        swap(u , v);
    }
    modify(1 , dfn[v] , dfn[u] , z);
}

LL query(int u , int l , int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum % p;
    }
    pushdown(u);
   int mid = tr[u].l + tr[u].r >> 1;
    LL res = 0;
    if(mid >= l) {
        res += query(u << 1 , l , r);
    }
    if(r > mid) {
        res += query(u << 1 | 1 , l , r);
    }
    return res % p;    
}


LL query_path(int u ,int v) {
   // cerr << dfn[u] << " " << dfn[v] << "\n";
    LL res = 0;
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) {
            swap(u , v);
        }
        res += query(1 , dfn[top[u]] , dfn[u]);
        res %= p;
        u = faz[top[u]];
    }
    if(dep[u] < dep[v]) {
        swap(u , v);
    }
    res += query(1 , dfn[v] , dfn[u]);
    return res % p;
} 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(h , -1 , sizeof h);
    
    cin >> n >> m >> r >> p;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> w[i];
    }
    for(int i = 0 ; i < n - 1 ; i ++ ) {
        int a , b ;
        cin >> a >> b;
        add(a , b ) , add(b , a);
    }
    dfs1(r , r);
    dfs2(r , r);
    build(1 , 1 , n);
    
    while(m -- ) {
        int op , x , y , z;
        cin >> op ;
        
        if(op == 1) {
            cin >> x >> y >> z;
            add_path(x , y , z);
        } else if(op == 2) {
            cin >> x >> y;
            cout << query_path(x , y) << "\n";
        } else if(op == 3) {
            cin >> x >> z;
            modify(1 , dfn[x] , dfn[x] + sz[x] - 1 , z);
        } else {
            cin >> x;
            //cout << dfn[x] << " " << dfn[x] + sz[x] - 1 << "\n";
            cout << query(1 , dfn[x] , dfn[x] + sz[x] - 1) << "\n";
        }        
    }
    
    return 0;
}