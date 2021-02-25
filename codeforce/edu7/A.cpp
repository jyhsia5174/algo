// 18m
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

class solver{
public:
    lli getVal(lli n){
        lli lo = 1, hi = 2e7L;
        while( lo + 1 < hi ){
            lli m = lo + (hi - lo) / 2;
            lli sum = incrSum(m);

            if( sum <= n ){
                lo = m;
            }
            else{
                hi = m;
            }
        }

        // lo + 1 == hi
        lli diff = n - incrSum(lo);
        
        if( diff == 0 )
            return lo;
        return diff;
    }

    // 1+...+n
    lli incrSum(lli n ){
       return n * (n+1) / 2; 
    }
};

int main(){

    lli n;
    cin >> n;

    solver mySol;

    cout << mySol.getVal(n) << endl;

    return 0;
}
