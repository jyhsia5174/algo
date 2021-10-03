 // 1652. Defuse the Bomb

class Solution {
    var codesize: Int = 1
    
    func idx(_ idx: Int) -> Int {
        return ((idx % codesize) + codesize ) % codesize
    }
    
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        codesize = code.count
        var res = Array<Int>(repeating: 0, count: codesize)
        
        if k == 0 {
            return res
        } else if k < 0 {
            var sum = 0
            for i in stride(from: -1, through: k, by: -1) {
                sum += code[idx(i)]
            }
            
            for i in 0..<codesize {
                res[i] = sum
                sum += code[i] - code[idx(i+k)]
            }
        } else {
            var sum = 0
            for i in stride(from: 1, through: k, by: 1) {
                sum += code[idx(i)]
            }
            
            for i in 0..<codesize {
                res[i] = sum
                sum += code[idx(i+k+1)] - code[idx(i+1)]
            }
        }
        
        return res
    }
}
