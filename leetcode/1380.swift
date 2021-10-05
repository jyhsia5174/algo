class Solution {
    func luckyNumbers (_ matrix: [[Int]]) -> [Int] {
        var maxCol : [Int] = matrix[0]
        var minRow : [Int] = []
        
        for row in matrix{
            minRow.append(row[0])
        }
        
        for (i, row) in matrix.enumerated() {
            for (j, val) in row.enumerated() {
                minRow[i] = min(minRow[i], val)
                maxCol[j] = max(maxCol[j], val)
            }
        }
        
        var res : [Int] = []
        
        for (i, row) in matrix.enumerated() {
            for(j, val) in row.enumerated() {
                if val == minRow[i] && val == maxCol[j] {
                    res.append(val)
                }
            }
        }
        
        return res
    }
}
