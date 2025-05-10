/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (55.74%)
 * Likes:    1277
 * Dislikes: 0
 * Total Accepted:    809.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 
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
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        // 如果当前节点是叶子节点，最小深度为 1
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }

        int left = INT_MAX;
        if (node->left != NULL) {
            left = dfs(node->left);
        }

        int right = INT_MAX;
        if (node->right != NULL) {
            right = dfs(node->right);
        }

        return min(left,right)+1;
    }
};
// @lc code=end

