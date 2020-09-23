/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int cnt[6][26], best = 0, x;
        for(int t = 0; t < 10; t++){
            memset(cnt, 0, 6*26*sizeof(int));
            for(string &w: wordlist)
                for(int i = 0; i < 6; i++)
                    cnt[i][ w[i] - 'a'] ++;
            
            best = 0;
            string guess = wordlist[0];
            
            for(string w: wordlist){
                int score = 0;
                for(int i = 0; i < 6; i++)
                    score += cnt[i][w[i] - 'a'];
                
                if(score > best){
                    guess = w;
                    best = score;
                }
            }
            
            x = master.guess(guess);
            vector<string> wordlist2;
            for(auto &w: wordlist)
                if(match(guess, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }
private:
    
    int match( const string &s1, const string &s2){
        int res = 0;
        for(int i = 0; i < 6; i++)
            if( s1[i] == s2[i] )
                res++;
        return res;
    }
};
