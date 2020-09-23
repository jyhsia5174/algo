class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        init();
        bool res = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(!valid( i, j, board[i][j])){
                    res = false;
                    break;
                }
            }
            if(!res)
                break;
        }
        return res;
    }
    
private:
    int cols[9][10];
    int rows[9][10];
    int blocks[3][3][10];
    void init(){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 10; j++){
                cols[i][j] = rows[i][j] = 0;
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 10; k++){
                    blocks[i][j][k] = 0;
                }
            }
        }
    }
    
    bool valid(int i, int j, char c){
        bool res = true;
        if( c == '.' )
            return res;
        
        int a = int(c - '0') - 1 ;
        if( cols[i][a] == 1 || rows[j][a] == 1 || blocks[i/3][j/3][a] == 1 )
            res = false;
            
        cols[i][a]++;
        rows[j][a]++;
        blocks[i/3][j/3][a]++;
        
        return res;
    }
};
