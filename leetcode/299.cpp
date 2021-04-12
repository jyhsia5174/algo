class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt1[10], cnt2[10];
        for(int i = 0; i < 10; i++)
            cnt1[i] = cnt2[i] = 0;
        
        int L = secret.size();
        int bulls = 0;
        
        for(int i = 0; i < L; i++){
            if( secret[i] == guess[i] ){
                bulls++;
                continue;
            }
            
            cnt1[ secret[i] - '0' ]++;
            cnt2[ guess[i] - '0' ]++;
        }
        
        int cows = 0;
        for(int i = 0; i < 10; i++){
            cout << setw(10) << cnt1[i] << setw(10) << cnt2[i] << endl;
            cows += min<int>(cnt1[i], cnt2[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
