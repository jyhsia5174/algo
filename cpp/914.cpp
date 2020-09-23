914. X of a Kind in a Deck of Cards
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if( deck.size() <= 1 )
            return false;
        
        unordered_map<int, int> count;
        for(auto &val: deck)
            count[val]++;
        
        int cd = count.begin()->second;
        for(auto &pp: count)
            cd = gcd(pp.second, cd);
        
        if( cd == 1 ) return false;
        return true;
    }
    
    int gcd( int a, int b ){
        if (b == 0)
            return a;
        return gcd( b, a%b );
    }
};
