// 77m
#include <bits/stdc++.h>
using namespace std;

class solver{
public:
    int minT(int n, unordered_map<int, vector<int>> &E){
        visited.resize(n, false);
        visited[0] = true;

        int T = 0;
        for(auto &next: E[0]){
            dfs(next, 0, E);
            sort(level.begin(), level.end());
            
            int tmp = -1;
            for(auto &l: level){
                if( l <= tmp ){
                    tmp++;
                }
                else{
                    tmp = l;
                }
            }

            T = max( T, tmp + 1 );
            level.clear();
        }


        return T;
    }

    void dfs(int node, int l, unordered_map<int, vector<int>> &E){
        visited[node] = true;
        bool isleaf = true;
        for(auto &next_node: E[node]){
            if(!visited[next_node]){
                isleaf = false;
                dfs(next_node, l+1, E);
            }
        }

        if( isleaf )
            level.push_back( l );
    }

    vector<int> level;
    vector<bool> visited;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    unordered_map<int, vector<int>> E;
    int x, y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        x--; y--;
        E[x].push_back( y );
        E[y].push_back( x );
    }

    solver mySol;
    cout << mySol.minT( n, E ) << endl;


    return 0;
}
