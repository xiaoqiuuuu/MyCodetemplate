#include<bits/stdc++.h>

using namespace std;
using LL = long long;

struct AC {
    int idx ;
    vector<int> fail , cnt;
    vector<vector<int>> tr ;
    AC() :tr(1 , vector<int>(26)) , cnt(1) , fail(1) , idx(0) {}
    void insert(string &s) {
        int n = s.size() , p = 0;
        for(int i = 0 ; i < n ; i ++ ) {
            int u = s[i] - 'a';
            if(!tr[p][u]) {
                tr.emplace_back(26);
                cnt.push_back(0);
                fail.push_back(0);
                tr[p][u] = ++ idx;
            }
            p = tr[p][u];
        }
        cnt[p] ++ ;
    }
    
    void build() {
        int hh = 0 , tt = -1 ;
        vector<int>q(idx , 0);
        for(int i = 0 ; i < 26 ; i ++ ) {
            if(tr[0][i]) {
                q[++ tt] = tr[0][i];
            }
        }
        while(hh <= tt) {
            int u = q[hh ++ ];
            for(int i = 0; i < 26; i++) {
                int v = tr[u][i];
                if(v) {
                    fail[v] = tr[fail[u]][i];
                    q[++tt] = v;
                } else 
                    tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    int query(string &s) {
        int n = s.size() , ans = 0;
        for(int i = 0 , j = 0; i < n ; i ++ ) {
            int u = s[i] - 'a';
            j = tr[j][u];
            for(int k = j ; k && ~cnt[k] ; k = fail[k]) {
                ans += cnt[k] ;
                cnt[k] = -1;
            }
        }
        return ans ;
    }
};

void solve() {
    int n;
    cin >> n;
    AC ac;
    string s;
    while(n -- ) {
        cin >> s;
        ac.insert(s);
    }
    ac.build();
    
    cin >> s;
    cout << ac.query(s) << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
   // cin >> tt;
    while(tt -- ) {
        solve();
    }
    
    return 0;
}