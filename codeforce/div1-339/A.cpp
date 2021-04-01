// 10 1h
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
LL x, y;
double pi = 4 * atan(1);

double norm(LL a, LL b){
    return a*a + b*b;
}

LL inner_product(LL a, LL b, LL c, LL d){
    return a * c + b * d;
}

double middleLen(LL a, LL b, LL c, LL d){
    double area = abs(a * d - b * c);
    area *= area;
    double len = norm(a-c, b-d);
    return area / len;
}

int main(){
    cin >> n >> x >> y;
    vector<LL> a(n);
    vector<LL> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        a[i] -= x;
        b[i] -= y; // bug1 : -= y not -= x
    }
    double maxL = 0, minL = LLONG_MAX; // bug3: wrong initial for minL sqrt(LLONG_MAX) is wrong
    for(int i = 0; i < n; i++){
        int j = (i+1) % n;
        double iL = norm(a[i], b[i]);
        maxL = max(maxL, iL);
        minL = min(minL, iL);
        if( ( inner_product(-a[i], -b[i], a[j]-a[i], b[j]-b[i]) > 0 ) &&
            ( inner_product(-a[j], -b[j], a[i]-a[j], b[i]-b[j]) > 0 )
                ){ // bug2: wrong detection condition
            double ijL = middleLen(a[i], b[i], a[j], b[j]);
            minL = min(minL, ijL);
        }
    }

    cout << setprecision(20) << pi * (maxL - minL) << endl; 
    return 0;
}
