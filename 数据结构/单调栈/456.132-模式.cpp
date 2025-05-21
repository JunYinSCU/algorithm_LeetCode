/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 *
 * https://leetcode.cn/problems/132-pattern/description/
 *
 * algorithms
 * Medium (36.63%)
 * Likes:    889
 * Dislikes: 0
 * Total Accepted:    88.2K
 * Total Submissions: 240.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k]
 * 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
 * 
 * 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：false
 * 解释：序列中不存在 132 模式的子序列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,1,4,2]
 * 输出：true
 * 解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [-1,3,2,0]
 * 输出：true
 * 解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //方法一：单调栈
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        int num_k = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < num_k)
                return true;
            
            while(!s.empty() && s.top() < nums[i]){                  
                num_k = s.top();
                s.pop();
            }   
            s.push(nums[i]);      
        }
        return false;
    }

};
// @lc code=end

