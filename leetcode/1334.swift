// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution {
    func findTheCity(_ n: Int, _ edges: [[Int]], _ distanceThreshold: Int) -> Int {
        var dp : [[Int]] = Array(repeating: Array(repeating: Int.max/2, count: n), count: n)
        
        for edge in edges {
            dp[edge[0]][edge[1]] = edge[2]
            dp[edge[1]][edge[0]] = edge[2]
        }
        
        for i in 0..<n {
            dp[i][i] = 0
        }
        
        for k in 0..<n {
            for i in 0..<n {
                for j in 0..<n {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
                }
            }
        }
        
        var neighborCount: [Int] = Array(repeating: 0, count: n)
        for i in 0..<n {
            for j in 0..<n{
                if dp[i][j] <= distanceThreshold {
                    neighborCount[i] += 1
                }
            }
        }
        
        var city = 0
        var min_count = neighborCount[city]
        for i in 1..<n {
            if neighborCount[i] <= min_count {
                city = i
                min_count = neighborCount[i]
            }
        }
        
        return city
    }
}
