/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.60%)
 * Likes:    2163
 * Dislikes: 0
 * Total Accepted:    568.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个非负整数数组 nums 和一个整数 target 。
 * 
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 
 * 
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], target = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
//递归
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     //正数和为p
    //     int p = 0;
    //     //负数绝对值和为n
    //     int n = 0;
    //     //总和为sum
    //     int sum = 0;
    //     for(int num : nums){
    //         sum += num;
    //     }

    //     //p + n = sum
    //     //p - n = target
    //     //所以：p = (sum + target) / 2
    //     //在数组中，选择一些正数，使得其和为p(并且为偶数)
    //     //可以用01背包动态规划解决
    //     if((sum + target) % 2 == 1){
    //         return 0;
    //     }

    //     return dfs(nums,nums.size()-1,(sum + target) / 2);

    // }

    // int dfs(vector<int>& nums,int c,int t){
    //     if(c < 0){
    //         if(t == 0)
    //         return 1;
    //         else
    //         return 0;
    //     }
    //     //选择当前c位置，则target减少当前位置的值
    //     //不选择则target不变
    //     return dfs(nums,c-1,t-nums[c]) + dfs(nums,c-1,t);
    // }

//递推
    int findTargetSumWays(vector<int>& nums, int target) {
        int p = 0;
        int n = 0;
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        if((sum + target) % 2 == 1){
            return 0;
        }

        if(sum + target < 0)
        return 0;

        p = (sum + target) / 2;

        vector dp(nums.size()+1,vector<int>(p+1,0));
        //dp[i][j]表示使用前i个数的和为j的个数，这里的i不是索引，而是个数
        dp[0][0] = 1;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <= p; j++){
                if(nums[i] <= j){
                    dp[i+1][j] = dp[i][j-nums[i]] + dp[i][j];
                }else{
                    dp[i+1][j] = dp[i][j];
                }                   
            }
        }

        return dp[nums.size()][p];
    }
};
// @lc code=end

