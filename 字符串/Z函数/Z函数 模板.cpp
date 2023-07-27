#include <bits/stdc++.h>

using namespace std;
using LL = long long;


// 所有字符串都是 1 下标
using T = LL ;
vector<T> get_z(const string &a ) {
    T n = a.size() - 1;
    vector<T>z(n + 1);
    z[1] = n ; 
    for(T i = 2 , l , r = 0 ; i <= n ; i ++ ) {
        if(i <= r) {
            z[i] = min(z[i - l + 1] , r - i + 1);
        }
        while(a[1 + z[i]] == a[i + z[i]]) {
            z[i] ++ ;
        }
        if(i + z[i] - 1 > r) {
            l = i , r = i + z[i] - 1;
        }
    }
    return z;    
}

// a 的 Z 函数， 计算b的后缀与 a 的最长匹配
vector<T> get_p(const string &a , const string &b ,const vector<T> &z) {
    T n = a.size() - 1 , m = b.size() - 1;
    vector<T> p (m + 1); //维护 b[l ,r] = a[1 , r - l + 1]
    for(T i = 1 , l , r = 0; i <= m ; i ++ ) {
        if(i <= r) {
            p[i] = min(z[i - l + 1] ,  r - i + 1);
        }
        while(1 + p[i] <= n && i + p[i] <= m && b[i + p[i]] == a[1 + p[i]]) {
            p[i] ++ ;
        }
        if(i + p[i] - 1 > r) {
            r = i + p[i] - 1;
            l = i;
        }   
    }
    return p;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a , b ;
    cin >> a >> b ;
    a = " " + a , b = " " + b ;
    auto z = get_z(b);
    auto p = get_p(b , a , z);
    
    LL ans = 0 ;
    for(int i = 1 ; i < z.size() ; i ++ ) {
        ans ^= 1ll * i * (z[i] + 1);
    }
   
    cout << ans << "\n";
    
    ans = 0;
    for(int i = 1 ; i < p.size() ; i ++ ) {
        ans ^= 1ll * i * (p[i] + 1);
    }
    
    cout << ans << "\n";
    
    
    return 0;
}