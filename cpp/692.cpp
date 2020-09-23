// 692. Top K Frequent Words
class Solution {
public:
    typedef pair<int, string> PIS;
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<PIS> w_count;
        unordered_map<string, int> count;
        
        for(auto &s: words)
            count[s]++;
        
        for(auto &pp: count){
            cout << pp.second << " " << pp.first << endl;
            w_count.push_back( {pp.second, pp.first} );
        }
        
        nth_element(w_count.begin(), w_count.begin()+k, w_count.end()
                    , [](
        const PIS &l, const PIS &r){
            if( l.first != r.first )
                return l.first > r.first;
            return l.second < r.second; 
        } );
        
        vector<string> res;
        sort( w_count.begin(), w_count.begin() + k, [](
        const PIS &l, const PIS &r){
            if( l.first != r.first )
                return l.first > r.first;
            return l.second < r.second; 
        }  );
        for(int i = 0; i < k; i++)
            res.push_back( w_count[i].second );
        return res;
    }
};
