#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const double pi = acos(-1);
struct Circle{
    double x , y ;
    double r;
    Circle(double x , double y , double r) :x(x) , y(y) ,r(r) {}
};

double func(Circle a , Circle b) {
    if(a.r > b.r) {
        swap(a , b);
    }
    double r = a.r , R = b.r;
    double x1 = a.x , y1 = a.y , x2 = b.x , y2 = b.y;
    double d = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
    d = sqrt(d);
    if(d >= r + R) {
        return 0;
    } else if(R - r >= d){
        return pi * r * r ;
    } else {
        double ang1= acos((r*r+d*d-R*R)/(2*r*d));
        double ang2= acos((R*R+d*d-r*r)/(2*R*d));
        return ang1*r*r + ang2*R*R - r*d*sin(ang1);
    }
}

void solve(){
    cout << fixed << setprecision(6);
    int x1 ,y1 , x2 , y2 , r , R ;
    cin >> r >> R >> x1 >> y1 >> x2 >> y2;
    
    Circle R1(x1 , y1 , R) , r1(x1 , y1 , r) , R2(x2 , y2 , R) , r2(x2 , y2 , r);
    
    cout << func(R1 , R2) - func(R1 , r2) - func(r1 , R2) + func(r1 , r2) ;

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
    cin >> tt ;
    for(int i = 1 ; i <= tt ; i ++){
        cout << "Case #" << i << ": " ;
        solve();
        cout << "\n";
    }
    
    return 0;
}