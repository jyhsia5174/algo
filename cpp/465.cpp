class Solution {
public:
    typedef long long int lli;
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, lli> balance;
        for(auto &t: transactions){
            int id1 = t[0], id2 = t[1], amount = t[2];
            if( balance.find(id1) != balance.end() )
                balance[id1] -= amount;
            else
                balance[id1] = -amount;
            
            if( balance.find(id2) != balance.end() )
                balance[id2] += amount;
            else
                balance[id2] = amount;
        }
        
        
        for(auto p: balance)
            if( p.second != 0 )
                debt.push_back( p.second );
            
        return get_min_transaction(0);
    }
    
    int get_min_transaction( int s ){
        while( s < debt.size() && debt[s] == 0 ) s++;
        int min_transaction = INT_MAX;
        
        for(int i = s+1; i < debt.size(); i++ ){
            if( debt[i]*debt[s] > 0 )
                continue;
            debt[i] += debt[s];
            min_transaction = min( min_transaction, 1+get_min_transaction( s+1 ));
            debt[i] -= debt[s];
        }
        
        return min_transaction < INT_MAX? min_transaction : 0;
    }
    
private:
    vector<int> debt;
};
