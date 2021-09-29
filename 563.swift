/**
563. Binary Tree Tilt
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    var totalTilt = 0
    
    func findTilt(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        sum(root)
        return totalTilt
    }
    
    func sum(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        
        var leftsum = sum(root!.left)
        var rightsum = sum(root!.right)
        totalTilt += abs(leftsum - rightsum)
        
        return root!.val + leftsum + rightsum
    }
}
