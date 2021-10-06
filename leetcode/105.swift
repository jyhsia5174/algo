// 105. Construct Binary Tree from Preorder and Inorder Traversal
/**
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
    var idx = [Int : Int]()
    var preorder: [Int] = []
    var inorder:[Int] = []
    
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        for (i, val) in inorder.enumerated() {
            idx[val] = i 
        }
        
        self.preorder = preorder
        self.inorder = inorder
        
        return helper(0, preorder.count, 0, inorder.count)
    }
    
    func helper(_ x1: Int, _ y1: Int, _ x2: Int, _ y2: Int) -> TreeNode? {
        if x1 == y1 { return nil }
        
        if let z2 = idx[preorder[x1]] {
            var lsz = z2 - x2
            var rsz = y2 - z2 - 1
            var lchild = try? helper(x1+1, x1+1+lsz, x2, z2)
            var rchild = try? helper(x1+1+lsz, y1, z2+1, y2)
        
            return TreeNode(preorder[x1], lchild, rchild)
        }
        
        return nil
    }
}
