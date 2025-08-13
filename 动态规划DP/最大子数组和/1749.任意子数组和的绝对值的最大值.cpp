/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 *
 * https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/description/
 *
 * algorithms
 * Medium (62.34%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    47.4K
 * Total Submissions: 75.6K
 * Testcase Example:  '[1,-3,2,3,-4]'
 *
 * 给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为
 * abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。
 * 
 * 请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。
 * 
 * abs(x) 定义如下：
 * 
 * 
 * 如果 x 是负整数，那么 abs(x) = -x 。
 * 如果 x 是非负整数，那么 abs(x) = x 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,-3,2,3,-4]
 * 输出：5
 * 解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,-5,1,-4,3,-2]
 * 输出：8
 * 解释：子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
//方法一：前缀和
// int maxAbsoluteSum(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> prefixSum(n + 1, 0);

//     for (int i = 1; i <= n; i++) {
//         prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
//     }

//     int maxSum = 0;
//     int minPrefixSum = 0;   //最小前缀和
//     int maxPrefixSum = 0;   //最大前缀和
//     //同时维护最小前缀和和最大前缀和，以覆盖负数的情况

//     for (int i = 1; i <= n; i++) {
//         maxSum = max({maxSum, abs(prefixSum[i] - minPrefixSum), abs(prefixSum[i] - maxPrefixSum)});
//         minPrefixSum = min(minPrefixSum, prefixSum[i]);
//         maxPrefixSum = max(maxPrefixSum, prefixSum[i]);
//     }

//     return maxSum;
// }

//方法二：动态规划
// int maxAbsoluteSum(vector<int>& nums) {
//     int n = nums.size();
//     int ans = 0;
//     int maxSum = 0, minSum = 0;

//     for(int x : nums){
//         maxSum = max(x,maxSum+x);
//         minSum = min(x,minSum+x);

//         ans = max({ans,maxSum,abs(minSum)});
//     }

//     return ans;
// }


int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n+1,0);//dp1[i] 表示以[i-1]结尾的数组的最大值
        vector<int> dp2(n+1,0);//dp1[i] 表示以[i-1]结尾的数组的最小值

        int maxSum = 0; //以[i-1]结尾的数组的最大值并不一定是全局最大值，所以还需要格外变量记录全局最大值
        int minSum = 0;//同理
        
        dp1[0] = 0;
        dp2[0] = 0;

        for(int i = 1; i <= n; i++){
            dp1[i] = max(dp1[i-1] + nums[i-1],nums[i-1]);
            dp2[i] = min(dp2[i-1] + nums[i-1],nums[i-1]);

            maxSum = max(dp1[i],maxSum);
            minSum = min(dp2[i],minSum);
        }
    return max(maxSum,abs(minSum));

}
};
// @lc code=end

