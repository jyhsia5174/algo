#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

class FT{
private:
    int size;
    int ft[3013];
public:
    FT(int s){
        size = s;
        fill(ft, ft+size+1, 0);
    }

    void update(int x, int v){
        while( x <= size ){
            ft[x] += v;
            x += x & -x;
        }
    }

    int query(int x){
        if( x <= 0 )
            return 0;
        return ft[x] + query( x- (x&-x));
    }
};

int n, m;
char z[3013][3013];
int l[3013][3013];
int r[3013][3013];

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        scanf(" %s", z[i]+1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            l[i][j] = (z[i][j] == 'z') ? l[i][j-1] + 1 : 0;
        }

        for(int j = m; j >= 1; j--){
            r[i][j] = (z[i][j] == 'z') ? r[i][j+1] + 1 : 0;
        }
    }

    LL ans = 0;
    
    for(int i = 1; i <= n+m-1; i++){
        int x = (i<=n) ? i : n;
        int y = (i<=n) ? 1 : i-n+1;
        
        FT tree(m);
        vector<int> rem[m+2];
        int diag = 0;
        while( x > 0 && y <= m ){
            for(int j: rem[y])
                tree.update(j, -1);

            if( z[x][y] == '.' ){
                diag = 0;
            }
            else{
                diag++;
                rem[y+r[x][y]].push_back(y);
                tree.update(y, 1);
                int high = min(diag, l[x][y]);
                ans += tree.query(y);
                ans -= tree.query(y-high);
            }
            x--; y++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}

