// 140. Word Break II
// credit samoshka
// 
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &s: wordDict)
            dict.insert(s);
        
        return find_next(s);
    }

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
    
    vector<string> find_next(string s) {
        if(cached.count(s)) return cached[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,find_next(rem));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        cached[s]=result; //memorize
        return result;
    }
    
private:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> cached;
};
