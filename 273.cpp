// 273. Integer to English Words
class Solution {
public:
    string numberToWords(int num) {
        if( num == 0 )
            return "Zero";
        
        init_two_digit();
        vector<string> res;
        int mod_base = 1000000000;
        int idx = 2;
        
        while( mod_base > 0 ){
            int thr_digit = (num / mod_base) % 1000;
            if( thr_digit != 0 ){
                string tmp;
                tmp += convert(thr_digit);
                cout << thr_digit << " " << tmp << endl;
                if( idx >= 0 )
                    tmp += " " + base[idx];
                res.push_back(tmp);
            }
            mod_base /= 1000;
            idx--;
        }
        
        string ans = res[0];
        for(int i = 1; i < res.size(); i++)
            ans += " " + res[i];
        return ans;
    }
    
    string convert( int num ){
        int a = num / 100;
        int b = num % 100;
        string res;
        if( a == 0 ){
            if( b != 0 )
                res = two_digit[b];
        }
        else{
            res += digit[a] + " " + "Hundred";
            if( b != 0 )
                res += " " + two_digit[b];
        }
        return res;
    }
    
    void init_two_digit(){
        two_digit.resize(100);
        for(int i = 0; i < 100; i++){
            if( i >= 0 && i < 10 ){
                two_digit[i] = digit[i];
            }
            else if( i >= 11 && i < 20){
                two_digit[i] = ten_to_twenty[i];
            }
            else if( i % 10 == 0 ){
                two_digit[i] = sd_digit[i];
            }
            else{
                int a = (i / 10) * 10;
                int b = i % 10;
                assert( a != 0 && b != 0 );
                two_digit[i] = sd_digit[a] + " " + digit[b]; 
            }
        }
    }
private:
    vector<string> two_digit;
    vector<string> digit{"Zero", "One", "Two", "Three", "Four", "Five", 
                   "Six", "Seven", "Eight", "Nine"};
    unordered_map<int, string>
        ten_to_twenty{ {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}
                     , {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}
                     , {19, "Nineteen"}};
    unordered_map<int, string> 
        sd_digit{{10, "Ten"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}
                , {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}
                , {80, "Eighty"}, {90, "Ninety"}};
    vector<string> base{"Thousand", "Million", "Billion"};
};
