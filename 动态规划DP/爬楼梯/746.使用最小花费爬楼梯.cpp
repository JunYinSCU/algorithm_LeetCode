/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (67.84%)
 * Likes:    1659
 * Dislikes: 0
 * Total Accepted:    563.3K
 * Total Submissions: 828.8K
 * Testcase Example:  '[10,15,20]'
 *
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
 * 
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
 * 
 * 请你计算并返回达到楼梯顶部的最低花费。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：cost = [10,15,20]
 * 输出：15
 * 解释：你将从下标为 1 的台阶开始。
 * - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
 * 总花费为 15 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 * 解释：你将从下标为 0 的台阶开始。
 * - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
 * 总花费为 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, 0);
        //dp[i]表示从0到i台阶的最小花费
        dp[0] = 0;  //从0到0台阶的花费为0
        dp[1] = 0;  //可以直接从下标为1的台阶开始，开销也为0

        for (int i = 2; i <= n; ++i) {
            //跳到i时，可以由i-1跳一格，或者由i-2跳两格
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];   //返回从0跳到n需要的开销
    }
};
// @lc code=end

