/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (53.23%)
 * Likes:    2360
 * Dislikes: 0
 * Total Accepted:    785.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
//记忆化搜索
    // bool canPartition(vector<int>& nums) {
    //     //顺序无关，只需要选出其中的数字，恰好为总和的一半。

    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i = 0; i < n; i++){
    //         sum += nums[i];
    //     }
    //     //如果是奇数则不可分为两个和相等的子集
        
    //     if(sum % 2 == 1){
    //         return false;
    //     }

    //     int target = sum / 2;

    //     vector<vector<int>> memo(n,vector<int>(target+1,-1));

    //     return dfs(n-1,target,nums,memo);

    // }

    // //dfs(c,t)含义：从0到c位置的数,能否在选择后,和为t
    // bool dfs(int c, int t, vector<int>& nums,vector<vector<int>>& memo){
    //     if(t == 0) return true;
    //     if(c < 0 || t < 0) return false;

    //     if(memo[c][t] != -1){
    //         return memo[c][t] == 1;
    //     }

    //     bool selectThis = dfs(c-1,t,nums,memo);    
    //     bool noSelectThis = dfs(c-1,t-nums[c],nums,memo);

    //     bool res = selectThis || noSelectThis;
    //     memo[c][t] = res ? 1 : 0;
    //     return res;
    // }


//递推
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int target = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1){
            return false;
        }

        target = sum / 2;

        // vector dp(n,vector<bool>(target+1,false));
        // dp[0][0] = true;
        // if (nums[0] <= target) dp[0][nums[0]] = true;
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < target+1; j++){
        //        dp[i][j] = dp[i-1][j];  // 不选 nums[i]
        //         if (j >= nums[i]) { //这里需要判断剩下的值还能否支持
        //             dp[i][j] = dp[i][j] || dp[i-1][j - nums[i]];  // 选 nums[i]
        //         }
        //     }          
        // }

        // return dp[n-1][target];

        //空间优化：
        vector<bool> dp(target+1,false);
        dp[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){ //倒序遍历避免覆盖计算结果
                dp[j] = dp[j] || dp[j-nums[i]]; //不选择或则选择当前num
            }
        }

        return dp[target];
    }
};
// @lc code=end

