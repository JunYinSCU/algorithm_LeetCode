/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode.cn/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (45.58%)
 * Likes:    1699
 * Dislikes: 0
 * Total Accepted:    490.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums){
        //区分判断偷0与否
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        //1.不偷0；
        int pre2 = nums[1];//当前位置的前两个截止最多能偷多少
        int pre1 = max(nums[1],nums[2]);    //前一个截止

        for(int i = 3; i < n; i++){
            int temp = pre1;
            pre1 = max(pre2+nums[i],pre1);
            pre2 = temp;
        }
        

        //2.偷0，则不能偷n-1
        int pre22 = nums[0];
        int pre11 = max(nums[1],nums[0]);

        for(int i = 2; i < n-1; i++){
            int temp = pre11;
            pre11 = max(pre22+nums[i],pre11);
            pre22 = temp;
        }

        return max(pre1,pre11);

    }
};
// @lc code=end

