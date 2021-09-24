// 1417. Reformat The String


class Solution {
    func reformat(_ s: String) -> String {
        var s1 : String = ""
        var s2 : String = ""
        var res : String = ""
        
        for c in s {
            if c.isNumber {
                s1.append(c)
            }
            else {
                s2.append(c)
            }
        }
        

        if abs(s1.length - s2.length) > 1 {
            return ""
        }
        
        
        if s1.length == s2.length {
            for i in 0..<s2.length{
                let idx1 = s1.index(s1.startIndex, offsetBy: i)
                let idx2 = s2.index(s2.startIndex, offsetBy: i)
                res.append(s1[idx1])
                res.append(s2[idx2])
            }
        } else if s1.length > s2.length {
            for i in 0..<s2.length{
                let idx1 = s1.index(s1.startIndex, offsetBy: i)
                let idx2 = s2.index(s2.startIndex, offsetBy: i)
                res.append(s1[idx1])
                res.append(s2[idx2])
            } 
            let idx1 = s1.index(s1.startIndex, offsetBy: s1.length-1)
            res.append(s1[idx1])
        } else {
            for i in 0..<s1.length{
                let idx1 = s1.index(s1.startIndex, offsetBy: i)
                let idx2 = s2.index(s2.startIndex, offsetBy: i)
                res.append(s2[idx2])
                res.append(s1[idx1])
            }
            let idx2 = s2.index(s2.startIndex, offsetBy: s2.length-1)
            res.append(s2[idx2])
        }
        
        return res
    }
}
