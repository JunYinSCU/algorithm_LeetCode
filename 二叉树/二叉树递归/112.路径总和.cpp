/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode.cn/problems/path-sum/description/
 *
 * algorithms
 * Easy (55.22%)
 * Likes:    1448
 * Dislikes: 0
 * Total Accepted:    808.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点
 * 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * 输出：true
 * 解释：等于目标和的根节点到叶节点路径如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：false
 * 解释：树中存在两条根节点到叶子节点的路径：
 * (1 --> 2): 和为 3
 * (1 --> 3): 和为 4
 * 不存在 sum = 5 的根节点到叶子节点的路径。
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [], targetSum = 0
 * 输出：false
 * 解释：由于树是空的，所以不存在根节点到叶子节点的路径。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [0, 5000] 内
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //如果根节点为空，无法计算，直接返回false
        if(root == NULL){
            return false;
        }

        return sum(root,targetSum,0);
    }

    /**
    * @param(node) 当前节点
    * @param(targetSum) 目标和
    * @param(preSum) 当前节点之前的和
     */
    bool sum(TreeNode* node,int targetSum,int preSum){
         
        //如果当前节点为叶子节点，计算这条路经上的和，然后比较，返回结果
        if(node->left == NULL && node->right == NULL){
            if(preSum + node->val == targetSum){
                return true;
            }else{
                return false;
            }
        }

        int nowSum = preSum + node->val;
        bool left = false;
        bool right = false;

        //如果存在左子树，递归调用左子树结果
        if(node->left != NULL){
            left = sum(node->left,targetSum,nowSum);
        }

        //同理右子树
        if(node->right != NULL){
            right = sum(node->right,targetSum,nowSum);
        }

        //只要存在有一条路经满足条件，返回true
        if(left || right){
            return true;
        }else{
            return false;
        }
        
    }
};
// @lc code=end

