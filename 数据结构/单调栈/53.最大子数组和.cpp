/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (55.98%)
 * Likes:    7040
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 子数组 是数组中的一个连续部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 * 
 */

// @lc code=start
class Solution {
public:
//方法一：前缀和
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> prefix(n+1);

    //     prefix[0] = 0;
    //     for (int i = 1; i <= n; ++i) {
    //         prefix[i] = prefix[i-1] + nums[i-1];
    //     }

    //     int maxSum= nums[0];
    //     int minPrefixSum = 0;
                        
    //     //[i,j]的和 = prefix[j+1] - prefix[i]
    //     for(int i = 1; i <= n; ++i) {
    //         maxSum = max(maxSum, prefix[i] - minPrefixSum);
    //         minPrefixSum = min(minPrefixSum, prefix[i]);
    //     }

    //     return maxSum;
    // }

    //方法二：动态规划
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        //dp[i]表示以第i个元素结尾的最大子数组和
        
        dp[0] = nums[0];
        int maxSum = dp[0]; //记录最大值

        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            maxSum = max(maxSum,dp[i]);
        }

        return maxSum;
    }
        
};
// @lc code=end

