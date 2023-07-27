#include<bits/stdc++.h>

using namespace std;
using LL = long long;

struct AC {
    int n , idx;
    vector<int>cnt , ne;
    vector<vector<int>> tr;
    AC(int n) :n(n) , cnt(1) , ne(1) {
        tr = vector<vector<int>>(1, vector<int>(26));
    }
    void insert(string &s) {
        int p = 0;
        for(auto c : s) {
            int u = c - 'a';
            if(!tr[p][u]) {
                tr[p][u] = tr.size();
                tr.emplace_back(26);
                cnt.push_back(0);
                ne.push_back(0);
            } 
            p = tr[p][u];
        }
        cnt[p] ++ ;
    }
    void build() {
        queue<int>q;
        for(int i = 0 ; i < 26 ; i ++ ) {
            if(tr[0][i]) {
                q.push(tr[0][i]);
            }
        }
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(int i = 0 ; i < 26 ; i ++ ) {
                int c = tr[t][i];
                if(!c) {
                    continue;
                }
                int j = ne[t];
                while(j && !tr[j][i]) {
                    j = ne[j];
                }
                if(tr[j][i]) {
                    j = tr[j][i];
                }
                ne[c] = j;
                q.push(c);
            }
        }        
    }
    
    int query(string &s) {
        int j = 0 , ans = 0;
        for(auto c : s) {
            int u = c - 'a';
            while(j && !tr[j][u]) {
                j = ne[j];
            }
            
            if(tr[j][u]) {
                j = tr[j][u];
            }
            
            int p = j;
            while(p) {
                ans += cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }
        return ans;
    }
    
};


void solve() {
    int n;
    cin >> n;
    AC ac(n);
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
    
    int tt;
    cin >> tt;
    while(tt -- ) {
        solve();
    }
    
    return 0;
}