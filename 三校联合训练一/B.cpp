#include <bits/stdc++.h>

using namespace std;
using LL = long long;




void solve(){
    int n ;
    cin >> n;
    n -= 4;
    
    map<int,int> mp ;
    mp[0] = 6 , mp[1] = 2 , mp[2] = mp[3] = 5 , mp[4] = 4 , mp[5] = 5 , mp[6] = 6 , mp[7] = 3 , mp[8] = 7 , mp[9] = 6;
    int ans = 0;
    for(int i = 0 ; i <= 1000 ; i ++ ) {
        for(int j = 0 ; j <= 1000 ; j ++ ) {
            int a = i , b = j , c = a + b , cnt = 0 ;
            if(a) {
                while(a) {
                    cnt += mp[a % 10];
                    a /= 10;
                }
            } else {
                cnt += mp[0];
            }

             if(b) {
                while(b) {
                    cnt += mp[b % 10];
                    b /= 10;
                }
            } else {
                cnt += mp[0];
            }
            
            if(c) {
                while(c) {
                    cnt += mp[c % 10];
                    c /= 10;
                }
            } else {
                cnt += mp[0];
            }
            
            if(cnt == n) {
                ans ++ ;
            }
        }
    }
    
    

    cout << ans << "\n";

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
    //cin >> tt ;
    while(tt --> 0){
        solve();
    }
    
    return 0;
}