// 50m 3
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> perm(n);
    for(auto &v: perm)
        cin >> v;

    int maxLen = 0;
    int maxCnt = 0;
    int lLen, rLen;
    for(int i = 1; i < n-1; i++){
        if( perm[i-1] < perm[i] && perm[i] > perm[i+1] ){
            int l = i, r = i;
            while(l-1 >= 0 && perm[l-1] < perm[l])
                l--;
            while(r+1 < n && perm[r+1] < perm[r])
                r++;
            int len1 = i-l;
            int len2 = r-i;
            if( len1 < len2 ) swap( len1, len2 );
            
            if( len1 > maxLen ){
                maxLen = len1;
                maxCnt = 1;
                lLen = len1;
                rLen = len2;
            }
            else if( len1 == maxLen ){
                maxCnt++;
            }
        }
    }

    int x = 0, y = n-1;
    while( x+1 < n && perm[x] > perm[x+1] )
        x++;
    while( y-1 >= 0 && perm[y] > perm[y-1] )
        y--;

    int lslp = x+1;
    int rslp = n-1-y+1;
    int slp = max(lslp, rslp);

    if( maxCnt == 0 ){
        cout << 0 << endl;
    }
    else if( maxCnt > 1 ){
        cout << 0 << endl;
    }
    else if( lLen > rLen ){
        cout << 0 << endl;
    }
    else if( lLen % 2 == 1 ){
        cout << 0 << endl;
    }
    else if( lLen+1 <= slp ){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }

}
