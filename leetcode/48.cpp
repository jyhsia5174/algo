/*
48. Rotate Image
4
(4+1)/2 = 2
0-0 0-1 0-2 0-3
1-0 1-1 1-2 1-3
2-0 2-1 2-2 2-3
3-0 3-1 3-2 3-3

5
(5+1)/2 = 3
0-0 0-1 0-2 0-3 0-4
1-0 1-1 1-2 1-3 1-4
2-0 2-1 2-2 2-3 2-4
3-0 3-1 3-2 3-3 3-4
4-0 4-1 4-2 4-3 4-4

*/

class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        const int n = M.size();
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < (n+1)/2; j++){
                int x = i, y = j;
                int val = M[x][y];
                for(int k = 0; k < 4; k++){
                    int xx = y, yy = (n-1) - x;
                    swap(M[xx][yy], val);
                    x = xx, y = yy;
                }
            }
        }
    }
};
