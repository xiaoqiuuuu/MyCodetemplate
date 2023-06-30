#include<bits/stdc++.h>

using namespace std;

int count(int x , int c)
{
    if(x == 0)return 0;
    
    vector<int>a ;
    int X = x;
    while(X)
    {
        a.push_back(X % 10);
        X /= 10;
    }
    

    int ans = 0 , pre = (c ? 0 : a.back()) , last = x ;
    for(int i = a.size() - 1 - (!c) ; ~ i ; i -- )
    {
        last = last % (int)pow(10 , i);
        
        if(i < a.size() - 1) //i前面的位数取0 - pre - 1的时候
        {
            ans += pre * (int)pow(10 , i); 
            if(!c)ans -= pow(10 , i); 
        }
        
        if(a[i] == c)ans += last + 1; // i 前面取 pre 的时候   
        else if(a[i] > c) ans += (int)pow(10 , i);
//        cout << last << " " << pre << "\n";
        
        pre = pre * 10 + a[i];

    } 
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    count(10 , 0) ;
    
    int l , r;
    while(cin >> l >> r , l || r)
    {
        if(l > r)swap(l , r);
        
        for(int i = 0 ; i <= 9 ; i ++ )
            cout << count(r , i) - count(l - 1 , i) << " ";
        cout << "\n";
    }
    
    
    return 0 ;
}