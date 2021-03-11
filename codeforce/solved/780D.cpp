#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, vector<int>> E;
unordered_map<int, vector<int>> EE;
unordered_map<int, vector<int>> rE;
vector<bool> use;
vector<int> who;
unordered_map<string, int> nameid;
unordered_map<int, vector<string>> name;
vector<int> prevvs;
vector<int> indegree;

void dfs(int nd, int rep){
    prevvs[nd] = true;
    for(auto &nnd: rE[nd])
        if( !prevvs[nd] )
            dfs(nnd, nd);
    who[nd] = rep;
}

int main(){
    cin >> n;

    string s1, s2, n1, n2;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;
        n1 = s1.substr(0, 3) + "1";
        n2 = s1.substr(0, 2) + s2.substr(0, 1) + "2";
        name[i].push_back( n1 );
        name[i].push_back( n2 );

        if( nameid.find( n1 ) == nameid.end() )
            nameid[n1] = nameid.size()*2 + 1;
        if( nameid.find( n2 ) == nameid.end() )
            nameid[n2] = nameid.size()*2 + 1;

        int id1 = nameid[n1];
        int nid1 = id1-1;
        int id2 = nameid[n2];
        int nid2 = id2-1;

        E[nid1].push_back( id2 );
        E[nid2].push_back( id1 );
        E[id1].push_back( nid2 );
        E[id2].push_back( nid1 );

        rE[id2].push_back( nid1 );
        rE[id1].push_back( nid2 );
        rE[nid2].push_back( id1 );
        rE[nid1].push_back( id2 );
    }

    int N = (nameid.size())*2;
    use.resize(N, false);
    who.resize(N);
    iota(who.begin(), who.end(), 0);
    prevvs(N, false);

    stack<int> stk;
    for(int i = 0; i < N; i++){
        if(!prevvs[i]){
            stack<int> tmp;
            tmp.push_back(i);
            while( !tmp.empty() ){
                int nd = tmp.top();
                if( prevvs[nd] ){
                    stk.push(nd);
                    tmp.pop();
                }
                else{
                    prevvs[nd] = true;
                    for(auto &nnd: E[nd])
                        if( !prevvs[nnd] )
                            tmp.push(nnd);
                }
            }
        }
    }

    fill(prevvs.begin(), prevvs.end(), false);
    while( !stk.empty() ){
        int nd = stk.top();
        if(!prevvs[nd])
            dfs(nd, nd);
        nd.pop();
    }

    indegree.resize(N, 0);
    for(int i = 0; i < N; i++){
        if( i == who[i] ){
            for(auto &j: E[i]){
                if(j == who[j] && who[i] != who[j]){
                    EE[i].push_back(j);
                    indegree[who[j]]++;
                }
            }
        }
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if( i == who[i] && indegree[who[i]] == 0 ){
            use[i] = false;
            Q.push(i);
        }
    }

    while( !Q.empty() ){
        int nd = Q.front();
        Q.pop(); 
        for(auto &nnd: EE[nd])
    }

}
