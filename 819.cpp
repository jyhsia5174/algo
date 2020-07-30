// 819. Most Common Word
class Solution {
public:
    string mostCommonWord(string P, vector<string>& banned) {
        unordered_set<string> B(banned.begin(), banned.end());
        unordered_map<string, int> count;
        
        string res;
        int max_count = 0;
        string word;
        for(int i = 0; i < P.size(); i++){
            if( !isalpha(P[i]) ){
                if(word.size() > 0 && B.count(word) == 0) 
                    count[word]++;
                if( max_count < count[word] ){
                    res = word;
                    max_count = count[word];
                }
                word = "";
            }
            else{
                word += tolower(P[i]);
            }
        }
        
        if(word.size() > 0 && B.count(word) == 0){
                count[word]++;
            if( max_count < count[word] ){
                    res = word;
                    max_count = count[word];
                }
            word = "";
        }
        
        return res;
    }
};
