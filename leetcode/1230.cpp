// 1230. Toss Strange Coins
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> t1, t2;
        t1.resize(target+1, 0);
        t2.resize(target+1);
        
        t1[0] = (1-prob[0]);
        if(target+1 >= 2)
            t1[1] = prob[0];
        
        for(int i = 1; i < prob.size(); i++){
            for(int j = 0; j < target+1; j++){
                if( j == 0 ){
                    t2[j] = t1[j] * (1-prob[i]);
                }
                else{
                    t2[j] = t1[j] * (1-prob[i]) + t1[j-1] * prob[i];
                }
            }
            
            swap(t1, t2);
        }
        return t1[target];
    }
};
