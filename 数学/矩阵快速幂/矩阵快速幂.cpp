// Problem: 
//     P3390 【模板】矩阵快速幂
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3390


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int mod = 1e9 + 7;

struct Matrix {
    int n , m ;
    vector<vector<LL>> s;
    
    Matrix(int n , int m):n(n) ,m(m),s(n , vector<LL>(m , 0)){};
    
    vector<LL>&operator [](int x , int y){
        return s[x];
    }
    
    
    friend Matrix operator *(Matrix &a , Matrix b){
        assert(a.m == b.n);
        Matrix res(a.n , b.m);
        int n = a.n , m = b.m;
        for(int k = 0 ; k < a.m ; k ++ )  
            for(int i = 0 ; i < n ; i ++ )
                for(int j = 0 ; j < m ; j ++ )
                    res.s[i][j] = (res.s[i][j] + a.s[i][k] * b.s[k][j] % mod) % mod;                
        return res;
}
};

Matrix qmi(Matrix a , LL b )
{
    assert(a.n == a.m);
   
    Matrix res(a.n , a.m);
    for(int i = 0 ; i < a.n ; i ++ )
        res.s[i][i] = 1;
        
    while(b)
    {
        if(b & 1)res = res * a;
        b >>= 1;
        a = a * a;
    }

    return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	LL n , m;
	cin >> n >> m;
	
	Matrix a(n ,n);
	for(int i = 0 ; i < n ; i ++ )
	    for(int j = 0 ; j < n; j ++ )
	        cin >> a.s[i][j];
    
    Matrix b(20 , 30);
    a = a * b ;
	

    // auto b = qmi(a , m);
// 
	// for(int i = 0 ; i < n ; i ++ )
	    // for(int j = 0 ; j < n ; j ++ )
	        // cout << b.s[i][j] << " \n"[j == n - 1];
// // 		
	return 0;
}
