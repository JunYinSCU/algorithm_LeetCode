/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (78.47%)
 * Likes:    1973
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树 root ，返回其最大深度。
 * 
 * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,null,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数量在 [0, 10^4] 区间内。
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*,int> mem;   //带记忆的递归
public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }

    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int leftDepth;
        if(mem.contains(root->left)){
            leftDepth = mem[root->left];
        }else{
            leftDepth = depth(root->left);
        }

        int rightDepth;
        if(mem.contains(root->right)){
            rightDepth = mem[root->right];
        }else{
            rightDepth = depth(root->right);
        }
        
        return max(leftDepth,rightDepth) + 1;
    }
};
// @lc code=end

