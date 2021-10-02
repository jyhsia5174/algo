// 344. Reverse String

class Solution {
    func reverseString(_ s: inout [Character]) {
        let n = s.count
        
        for i in 0..<(n/2) {
            s.swapAt(i, n-1-i)
        }
    }
}
