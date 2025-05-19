/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode.cn/problems/house-robber/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    3274
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[1,2,3,1]
 * 输出：4
 * 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：[2,7,9,3,1]
 * 输出：12
 * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //方法一：递归+记忆化搜索
    // vector<int> dp;
    // int rob(vector<int>& nums) {
    //     dp.resize(nums.size(),-1);
    //     return robCash(nums,0);
    // }

    // int robCash(vector<int>& nums,int start){
    //     int n = nums.size();
    //     if(start >= n) return 0;

    //     if(dp[start] != -1) return dp[start];
     
    //     int cash1 = robCash(nums,start+1);
    //     int cash2 = robCash(nums,start+2) + nums[start];
    //     dp[start] = max(cash1,cash2);
    //     return dp[start];
    // }

    //方法二：动态规划，翻译为递推
    // int rob(vector<int>& nums){
    //     int n = nums.size();
    //     //dp[i]表示从0到i能偷的最大金额
    //     vector<int> dp(n+1,0);
    //     dp[0] = 0;  //0时没法偷，为0
    //     dp[1] = nums[0];    //1时只能偷第一个房子
    //     for(int i = 2; i <= n; i++){
    //         //从2开始，取下面两种情况的最大值
    //         //当前不偷，则金额为dp[i-1]
    //         //当前偷，则金额为dp[i-2]+nums[i-1]
    //         dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
    //     }

    //     return dp[n];
    // }

    //方法三：动态规划，空间优化
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int pre2 = nums[0];//当前位置的前两个截止最多能偷多少
        int pre1 = max(nums[0],nums[1]);    //前一个截止

        for(int i = 2; i < n; i++){
            int temp = pre1;
            pre1 = max(pre2+nums[i],pre1);
            pre2 = temp;
        }
        return pre1;
    }
};
// @lc code=end

