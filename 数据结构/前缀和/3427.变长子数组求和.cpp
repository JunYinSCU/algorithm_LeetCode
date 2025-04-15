/*
 * @lc app=leetcode.cn id=3427 lang=cpp
 *
 * [3427] 变长子数组求和
 *
 * https://leetcode.cn/problems/sum-of-variable-length-subarrays/description/
 *
 * algorithms
 * Easy (91.02%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 7.2K
 * Testcase Example:  '[2,3,1]'
 *
 * 给你一个长度为 n 的整数数组 nums 。对于 每个 下标 i（0 <= i < n），定义对应的子数组 nums[start ...
 * i]（start = max(0, i - nums[i])）。
 * 
 * 返回为数组中每个下标定义的子数组中所有元素的总和。
 * 子数组 是数组中的一个连续、非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,1]
 * 
 * 输出：11
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 下标 i
 * 子数组
 * 和
 * 
 * 
 * 0
 * nums[0] = [2]
 * 2
 * 
 * 
 * 1
 * nums[0 ... 1] = [2, 3]
 * 5
 * 
 * 
 * 2
 * nums[1 ... 2] = [3, 1]
 * 4
 * 
 * 
 * 总和
 * 
 * 11
 * 
 * 
 * 
 * 
 * 总和为 11 。因此，输出 11 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,1,1,2]
 * 
 * 输出：13
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 下标 i
 * 子数组
 * 和
 * 
 * 
 * 0
 * nums[0] = [3]
 * 3
 * 
 * 
 * 1
 * nums[0 ... 1] = [3, 1]
 * 4
 * 
 * 
 * 2
 * nums[1 ... 2] = [1, 1]
 * 2
 * 
 * 
 * 3
 * nums[1 ... 3] = [1, 1, 2]
 * 4
 * 
 * 
 * 总和
 * 
 * 13
 * 
 * 
 * 
 * 
 * 总和为 13 。因此，输出为 13 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == nums.length <= 100
 * 1 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> pre(nums.size()+1);
        
        pre[0] = 0;
        int ans = 0;

        for(int i = 0; i< nums.size(); i++){
            pre[i+1] = pre[i] + nums[i];
            ans += pre[i+1] - pre[max(0,i-nums[i])];
        }
              
        return ans;
    }
};
// @lc code=end

