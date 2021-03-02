#include <bits/stdc++.h>
using namespace std;

class solver{
public:
    int score(vector<int> &B, vector<int> &S){
        int bi = 0;
        int si = 0;

        while(bi < B.size() && B[bi] < 0 )
            bi++;

        while(si < S.size() && S[si] < 0 )
            si++;

        vector<int> BR(B.begin()+bi, B.end());
        vector<int> SR(S.begin()+si, S.end());

        vector<int> BL;
        vector<int> SL;
        for(int i = bi-1; i >= 0; i--)
            BL.push_back( -B[i] );
        for(int i = si-1; i >= 0; i--)
            SL.push_back( -S[i] );

        return best(BR, SR) + best(BL, SL);
    }
    
    int best(vector<int> &B, vector<int> &S){
        if( B.size() == 0 || S.size() == 0 )
            return 0;

        vector<int> dp(B.size()+1, 0);
        int x = B.size()-1;
        int y = S.size()-1;
        while( x >= 0 && y >= 0 ){
            if( B[x] > S[y] ){
                dp[x] = dp[x+1];
                x--;
            }
            else if( B[x] < S[y] ){
                y--;
            }
            else{
                dp[x] = dp[x+1]+1;
                x--;
                y--;
            }
        }
        while( x >= 0 ){
            dp[x] = dp[x+1];
            x--;
        };

        int res = dp[0];
        int j = 0;
        while( j < S.size() && S[j] < B[0] )
            j++;
        for(int i = 1; i <= B.size(); i++){
            while(j < S.size() && 
                    (i == B.size() || S[j] < B[i]) ){
                int k = lower_bound(S.begin(), S.end(), S[j]-i+1) 
                    - S.begin();
                res = max(res, j - k + 1 + dp[i]);
                j++;
            }
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n, m;
    solver mySol;
    while( t-- ){
        cin >> n >> m;
        vector<int> B(n), S(m);
        for(auto &b: B)
            cin >> b;
        for(auto &s: S)
            cin >> s;

        cout << mySol.score(B, S) << endl;
    }
}
