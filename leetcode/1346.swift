class Solution {
    func checkIfExist(_ arr: [Int]) -> Bool {
        var nums = Set<Int>()
        
        for num in arr {
            if nums.contains(2*num) { return true }
            
            if num % 2 == 0 && nums.contains(num/2) {
                return true
            }
            
            nums.insert(num)
        }
        
        return false
    }
}
