/* 72m
1

1   1   0

2

1   1   0
2   0

3

1   2   1
2   1   0
3   0

*/

#include<vector>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    if( n == 1 ){
        cout << 1 << " " << 1;
        return 0;
    }

    if( n == 2 ){
        cout << 1 << " " << 1 << " " << 2 << " " << 2;
        return 0;
    }

    vector<int> ans, tmp;
    for(int i = n-1; i >= 1; i-=2)
        tmp.push_back(i);

    for(auto it = tmp.rbegin(); it != tmp.rend(); it++)
        ans.push_back( *it );

    for(auto it = tmp.begin(); it != tmp.end(); it++)
        ans.push_back( *it );

    tmp.clear();
    for(int i = n-2; i >= 1; i-=2)
        tmp.push_back(i);
    
    for(auto it = tmp.rbegin(); it != tmp.rend(); it++)
        ans.push_back( *it );

    ans.push_back(n);
    for(auto it = tmp.begin(); it != tmp.end(); it++)
        ans.push_back( *it );

    ans.push_back(n);

    for(auto &v: ans)
        cout << v << " " ;
    return 0;
}
