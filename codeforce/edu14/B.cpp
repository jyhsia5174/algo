#include <bits/stdc++.h>
using namespace std;


int main(){
    unordered_map<char, char> M;
    M['A'] = 'A';
    M['H'] = 'H';
    M['I'] = 'I';
    M['M'] = 'M';
    M['O'] = 'O';
    M['T'] = 'T';
    M['U'] = 'U';
    M['V'] = 'V';
    M['W'] = 'W';
    M['X'] = 'X';
    M['Y'] = 'Y';

    M['o'] = 'o';
    M['v'] = 'v';
    M['w'] = 'w';
    M['x'] = 'x';

    unordered_map<char, char> M1(M.begin(), M.end());
    M1['b'] = 'd';
    M1['d'] = 'b';
    M1['p'] = 'q';
    M1['q'] = 'p';

    string s;
    cin >> s;
    const int n = s.size();
    for(int i = 0; i < n / 2; i++){
        if( M1.find(s[i]) == M1.end() || M1[s[i]] != s[n-1-i] ){
            cout << "NIE" << endl;
            return 0;
        }
    }

    char c = s[n/2];
    if( n % 2 == 1 && 
            (M.find(c) == M.end()) ){
        cout << "NIE" << endl;
        return 0;
    }

    cout << "TAK" << endl;
    return 0;
}
