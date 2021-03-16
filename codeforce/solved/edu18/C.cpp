// 47m 8
#include <bits/stdc++.h>
using namespace std;

string clean(const string &s, int cnt, int target){
    string res = "";
    int n = s.size();
    for(int i = n-1; i >= 0; i--){
        if( (s[i]-'0') % 3 == target && cnt > 0 ){
            cnt--;
        }
        else{
            res += s[i];
        }
    }
    reverse(res.begin(), res.end());
    if(res == "" || cnt > 0)
        return "";
    size_t x = res.find_first_not_of('0');
    if( x == string::npos )
        return "0";
    return res.substr( x, res.size() - x );
}

int main(){
    string s;
    cin >> s;

    int sum = 0;
    vector<int> cnt(3, 0);
    for(auto &c: s){
        sum = (sum + c-'0') % 3;
        cnt[(c-'0') % 3]++;
    }

    sum %= 3;
    if( sum == 0 ){
        cout << s << endl;
        return 0;
    }

    string res = "";
    if( sum == 1 ){
        string tmp = clean( s, 1, 1);
        string tmp2 = clean( s, 2, 2);
        if( tmp.size() > tmp2.size() )
            res = tmp;
        else
            res = tmp2;
    }
    else{
        string tmp = clean( s, 2, 1);
        string tmp2 = clean( s, 1, 2);
        if( tmp.size() > tmp2.size() )
            res = tmp;
        else
            res = tmp2;
    }

    if( res == "" )
        cout << -1 << endl;
    else
        cout << res << endl;
    
    return 0;
}
