// 1 17m
class FT{
public:
    int n;
    vector<int> tree;
    FT(int _n){
        n = _n;
        tree.resize(n+1, 0); // 1 ... n
    }
    
    void update(int x, int val){
        int oval = get(x) - get(x-1);
        int diff = val - oval;
        while(x <= n){
            tree[x] += diff;
            x += (x & -x);
        }
    }
    
    int get(int x){
        int res = 0;
        while(x > 0){
            res += tree[x];
            x -= (x & -x);
        }
        return res;
    }
};

class NumMatrix {
public:
    int m, n;
    vector<FT> rows;
    vector<FT> cols;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        rows.resize(m, FT(n));
        cols.resize(n, FT(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rows[i].update(j+1, matrix[i][j]);
                cols[j].update(i+1, matrix[i][j]);
            }
        }
    }
    
    void update(int x, int y, int val) {
        rows[x].update(y+1, val);
        cols[y].update(x+1, val);
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum = 0;
        if( abs(r1-r2) < abs(c1-c2) ){
            for(int i = r1; i <= r2; i++){
                sum += rows[i].get(c2+1) - rows[i].get(c1);
            }
        }
        else{
            for(int i = c1; i <= c2; i++)
                sum += cols[i].get(r2+1) - cols[i].get(r1);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
