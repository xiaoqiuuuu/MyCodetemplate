#include<bits/stdc++.h>

using namespace std;
using LL = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n , k ;
    cin >> n >> k;
    vector<LL> a(n + 1) , b(n + 1 , 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1 , a.end());
    
    for(int i = 1 ; i <= n ; i ++ ) {
        LL x = a[i];
        while(x) {
            b[i] *= 10 ;
            x /= 10;
        }    
    }
    
    auto check = [=](LL i , LL j )->bool {
        if(a[i] * b[j] + a[j] <= k) {
            return true;
        }
        return false;
    };
    
    LL ans = 0;
        for(int i = 1 , j = 2 ; i <= n ; i ++ ) {
        if(i == 1) {
            while(j <= n && check(i , j)) j ++ ;
            j -- ;
        } else {
            while(j > i && !check(i , j)) j -- ;
        }        
        if(j > i) {
            ans += j - i;
        } else {
            break;
        }
    }

    for(int i = 1 , j = n ; j >= 1 ; j -- ) {
        if(!check(j , i)) {
            continue;
        }
        while(i < j && check(j , i)) {
            i ++ ;
        }
        i -- ;
        if(i < j) {
            ans += i;
        }
    }
    cout << ans << "\n";
    
    
    return 0 ;
}