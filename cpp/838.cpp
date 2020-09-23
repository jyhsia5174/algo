// 838. Push Dominoes
class Solution {
public:
    string pushDominoes(string S) {
        int N = S.size();
        string Scp(S);
        
        while(true){
            for(int i = 0; i < N; i++){
                if( S[i] == 'R' ){
                    if( i+1 < N && S[i+1] == '.'){
                        if( i+2 >= N || (i+2 < N && S[i+2] != 'L') )
                            Scp[i+1] = 'R';
                    }
                }
                else if(S[i] == 'L'){
                    if( i-1 >= 0 && S[i-1] == '.' ){
                        if( i-2 < 0 || ( i-2 >= 0 && S[i-2] != 'R' ))
                            Scp[i-1] = 'L';
                    }
                }
            
            }
            if(S == Scp) break;
            S = Scp;
        }
        
        return S;
    }
};
