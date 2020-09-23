class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> res;
            
        int i = 0; 
        int j, cur_sz, sp_sz;
        while( i < words.size() ){
            j=i, cur_sz = 0, sp_sz = L;
            while( j < words.size() && cur_sz + words[j].size() <= L){
                cur_sz += words[j].size() + 1;
                sp_sz -= words[j].size();
                j++;
            }
            
            string tmp;
            int num_w = j - i;
            tmp += words[i]; i++;
            for(int k = 0; i < j; i++ , k++){
                if(j == words.size())
                    tmp += " ";
                else
                    tmp += string( sp_sz / (num_w - 1) + (k < (sp_sz % (num_w - 1)))  , ' ');
                tmp += words[i];
            }
            
            tmp += string( L - tmp.size(), ' ' );
            
            res.push_back(tmp);
            
            i = j;
        }
        
        return res;
    }
};
