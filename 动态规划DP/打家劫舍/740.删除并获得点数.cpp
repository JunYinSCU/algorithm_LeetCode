/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode.cn/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (60.15%)
 * Likes:    1121
 * Dislikes: 0
 * Total Accepted:    166K
 * Total Submissions: 275.8K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 * 
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和
 * nums[i] + 1 的元素。
 * 
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
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
    //转化为值域数组
    //如果当前元素要选，则所有的当前值都要选
    int deleteAndEarn(vector<int>& nums) {   
        int mx = ranges::max(nums);
        vector<int> a(mx + 1);
        for (int x : nums) {
            a[x] += x; // 统计等于 x 的元素之和
        }
        return rob(a);
    
    }

    //动态规划
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n+1,-1);
        
        dp[0] = 0;
        dp[1] = nums[0];
        //从左到右，如果当前元素要选，则不能选前一元素，即dp[i-2] + nums[i-1]
        //如果当前元素不选，则可以选前一元素，即dp[i-1]
        //不考虑比当前元素大一的元素，因为还未到那个长度
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        return dp[n];
    }
};
// @lc code=end

