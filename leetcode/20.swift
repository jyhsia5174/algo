// 20. Valid Parentheses
class Solution {
    func isValid(_ s: String) -> Bool {
        var tmp = ""
        
        for c in s {
            if c == "(" || c == "{" || c == "[" {
                tmp.append(c)
            } else if c == ")" && tmp.popLast() != "(" {
                return false
            } else if c == "}"  && tmp.popLast() != "{" {
                return false
            } else if c == "]"  && tmp.popLast() != "["{
                return false
            }
        }
        
        if tmp.length != 0 { return false }
        return true
    }
}
