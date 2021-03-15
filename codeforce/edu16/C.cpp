// 1h 3
#include <bits/stdc++.h>
using namespace std;

int oddx = 1;
void odd(int x, int y, int xx, int yy, int l, vector<vector<int>> &M){
    int ib = ((l/2)%2 == 0) ? 0 : 1;
    for(int i = ib; i < l; i += 2){
        if( M[x][y+i] == -1 ){
            M[x][y+i] = oddx;
            oddx += 2;
        }
        if( M[x+i][y] == -1 ){
            M[x+i][y] = oddx;
            oddx+=2;
        }
        if( M[xx][yy-i] == -1 ){
            M[xx][yy-i] = oddx;
            oddx+=2;
        }
        if( M[xx-i][yy] == -1 ){
            M[xx-i][yy] = oddx;
            oddx+=2;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n, -1));

    int m = n/2;
    for(int i = 0; i < (n+1)/2; i++){
        odd(m-i, m-i, m+i, m+i, 2*i+1, M);
    }

    int evenx = 2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if( M[i][j] == -1 ){
                M[i][j] = evenx;
                evenx+=2;
            }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
