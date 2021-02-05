/*
165. Compare Version Numbers
*/
class Solution {
public:
    int compareVersion(string s1, string s2) {
        size_t i1 = 0, i2 = 0;
        size_t j1, j2;
        int v1, v2;
        while( i1 != string::npos || i2 != string::npos ){
            j1 = s1.find('.',i1);
            j2 = s2.find('.',i2);
            cout << i1 << " " << i2 << endl;
            if( i1 != string::npos && i2 != string::npos ){
                if( j1 == string::npos ){
                    v1 = stoi( s1.substr(i1, s1.size() - i1) );
                    i1 = j1;
                }
                else{
                    v1 = stoi( s1.substr(i1, j1 - i1) );
                    i1 = j1+1;
                }
                
                if( j2 == string::npos ){
                    v2 = stoi( s2.substr(i2, s2.size() - i2) );
                    i2 = j2;
                }
                else{
                    v2 = stoi( s2.substr(i2, j2 - i2) );
                    i2 = j2+1;
                }
            }
            else if( i1 != string::npos){
                v2 = 0;
                if( j1 == string::npos ){
                    v1 = stoi( s1.substr(i1, s1.size() - i1) );
                    i1 = j1;
                }
                else{
                    v1 = stoi( s1.substr(i1, j1 - i1) );
                    i1 = j1+1;
                }
                
            }
            else{
                v1 = 0;
                if( j2 == string::npos ){
                    v2 = stoi( s2.substr(i2, s2.size() - i2) );
                    i2 = j2;
                }
                else{
                    v2 = stoi( s2.substr(i2, j2 - i2) );
                    i2 = j2+1;
                }
            }
            
            
            if(v1 < v2)
                return -1;
            else if(v1 > v2)
                return 1;
        }
            
        return 0;
    }
};
