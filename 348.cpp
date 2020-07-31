// 348. Design Tic-Tac-Toe
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        R.resize(n, 0);
        C.resize(n, 0);
        diag1 = diag2 = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int a = (player == 1)? 1:-1;
        R[row] += a;
        C[col] += a;
        
        if( row == col ) diag1+=a;
        if( col == (N-1 - row) ) diag2+=a;
        
        if( abs(R[row]) == N || abs(C[col]) == N 
          || abs(diag1) == N || abs(diag2) == N )
            return player;
            
        return 0;
    }
private:
    int N;
    vector<int> R, C;
    int diag1, diag2;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
