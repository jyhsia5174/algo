// 5m 2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);

    for(int i = 0; i < n; i++)
        cin >> A[i];

    int maxLen = 1;
    int curLen = 1;
    for(int i = 1; i < n; i++){
        if( A[i] > A[i-1] ){
            curLen++;
            maxLen = max(curLen, maxLen);
        }
        else{
            curLen = 1;
        }
    }

    cout << maxLen << endl;
    return 0;
}
