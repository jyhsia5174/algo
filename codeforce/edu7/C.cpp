// new version

// 57m
#include <vector>
#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int val;
    vector<int> A;
    while( n-- ){
        cin >> val;
        A.push_back( val );
    }

    vector<int> jump(A.size(), A.size());
    for(int i = A.size()-1; i >= 0; i--){
        if( A[i] == A[i+1] )
            jump[i] = jump[i+1];
        else
            jump[i] = i+1;
    }

    int l, r, x;
    while( m-- ){
        cin >> l >> r >> x;
        l--; r--;

        if( A[l] != x ){
            cout << l+1 << endl;
        }
        else{
            if( jump[l] > r )
                cout << -1 << endl;
            else
                cout << jump[l] + 1 << endl;
        }
    }

    return 0;
}


// 57m
#include <vector>
#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int val;
    vector<int> A;
    while( n-- ){
        cin >> val;
        A.push_back( val );
    }

    vector<int> jump(A.size(), A.size());
    for(int i = A.size()-1; i >= 0; i--){
        if( A[i] == A[i+1] )
            jump[i] = jump[i+1];
        else
            jump[i] = i+1;
    }

    int l, r, x;
    while( m-- ){
        cin >> l >> r >> x;
        l--; r--;

        if( A[l] != x ){
            cout << l+1 << endl;
        }
        else{
            if( jump[l] > r )
                cout << -1 << endl;
            else
                cout << jump[l] + 1 << endl;
        }
    }

    return 0;
}




// old version
#include <vector>
#include <iostream>
using namespace std;

class solver{
public:
    solver(vector<int> &A){
        n = A.size();
        tree.resize(2*n);

        for(int i = 0; i < n; i++)
            tree[n+i].push_back( {A[i], i} );

        for(int i = n-1; i > 0; i--){
            tree[i] = tree[2*i];

            for(auto &v: tree[2*i+1]){
                if( tree[i].size() >= 2 )
                    break;

                if( tree[i][0][0] != v[0] )
                    tree[i].push_back( v );
            }
        }
    }

    int query(int l, int r, int x){
        l += n;
        r += n;

        while( l <= r ){
            if( l % 2 == 1 ){
                for(auto &v: tree[l])
                    if( v[0] != x )
                        return v[1] + 1;
                l++;
            }

            if( r % 2 == 0 ){
                for(auto &v: tree[r])
                    if( v[0] != x )
                        return v[1] + 1;
                r--;
            }

            l /= 2;
            r /= 2;
        }
        return -1;
    }

    int n;
    vector<vector<vector<int>>> tree;
};

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int val;
    vector<int> A;
    while( n-- ){
        cin >> val;
        A.push_back( val );
    }

    solver mySol( A );

    int l, r, x;
    while( m-- ){
        cin >> l >> r >> x;
        cout << mySol.query(l-1, r-1, x) << endl;
    }

    return 0;
}
