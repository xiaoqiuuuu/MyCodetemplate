// Problem: 单词
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1287/


#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10 , M = 210 ;

int n ;
int tr[N][26] , f[N] , id[M] , idx , fail[N] ; 
int q[N] , hh , tt = -1;
string s; 

void insert(int x) {
    int p = 0 ;
    for(auto c : s) {
        int u = c - 'a';
        if(!tr[p][u]) {
            tr[p][u] = ++ idx;
        }
        p = tr[p][u];
        f[p] ++ ;
    }
    id[x] = p;
}

void build() {
    for(int i = 0 ; i < 26 ; i ++ ) {
        if(tr[0][i]) {
            q[++ tt] = tr[0][i];
        }
    }
    
    while(hh <= tt) {
        int t = q[hh ++ ];
        for(int i = 0 ; i < 26 ; i ++ ) {
            int c = tr[t][i];
            if(c) {
                fail[c] = tr[fail[t]][i];
                q[++ tt] = c;
            } else {
                tr[t][i] = tr[fail[t]][i];       
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> s;
        insert(i);
    }

    build();
    
    for(int i = idx - 1; i >= 0 ; i -- ) {
        f[fail[q[i]]] += f[q[i]];
    }    
    
    for(int i = 1 ; i <= n ; i ++ ) {
        cout << f[id[i]] << "\n";
    }
    
    
    return 0;
}