// 158. Read N Characters Given Read4 II - Call multiple times
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int idx = 0;
        read_remain(buf, n, idx);
        
        char buffer[4];
        while( idx < n ){
            int count = read4(buffer);
            if( count == 0 ) break;
            
            int i_count = 0;
            while( idx < n && i_count < count){
                buf[idx] = buffer[i_count];
                i_count++;
                idx++;
            }
            
            if( i_count < count ){
                while( i_count < count ){
                    remain.push(buffer[i_count]);
                    i_count++;
                }
                break;
            }
        }
        
        return idx;
    }
    
    void read_remain(char *buf, int n, int &idx){
        while( (!remain.empty()) && idx < n ){
            buf[idx] = remain.front();
            remain.pop();
            idx++;
        }
    }
    
private:
    queue<char> remain;
};
