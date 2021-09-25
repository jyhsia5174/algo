// 1417. Reformat The String

// v2

class Solution {
    func reformat(_ s: String) -> String {
        var res = ""
        var s1 = Array( s.filter{ $0.isNumber } )
        var s2 = Array( s.filter{ $0.isLetter } )
        

        if abs(s1.count - s2.count) > 1 {
            return ""
        }
        
        if s1.count > s2.count {
            swap(&s1, &s2)
        }
        
        var idx1 = 0
        var idx2 = 0
        
        while idx1 < s1.count && idx2 < s2.count {
            res.append(s2[idx2])
            res.append(s1[idx1])
            idx1 += 1
            idx2 += 1
        }
        
        if idx2 < s2.count {
            res.append(s2[idx2])
        }
        
        return res
    }
}

// v1

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
