/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 *
 * [1760] 袋子里最少数目的球
 *
 * https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/description/
 *
 * algorithms
 * Medium (65.25%)
 * Likes:    300
 * Dislikes: 0
 * Total Accepted:    43K
 * Total Submissions: 66K
 * Testcase Example:  '[9]\n2'
 *
 * 给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。同时给你一个整数 maxOperations 。
 * 
 * 你可以进行如下操作至多 maxOperations 次：
 * 
 * 
 * 选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
 * 
 * 
 * 比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
 * 
 * 
 * 
 * 
 * 你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。
 * 
 * 请你返回进行上述操作后的最小开销。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [9], maxOperations = 2
 * 输出：3
 * 解释：
 * - 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
 * - 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
 * 装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,4,8,2], maxOperations = 4
 * 输出：2
 * 解释：
 * - 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
 * 装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,17], maxOperations = 2
 * 输出：7
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
    //时间复杂度O(nlog(max(nums))) 空间复杂度O(1)
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 0;
        for(int i = 0;i < nums.size();i++){
            right = max(right,nums[i]);
        }
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(nums,maxOperations,mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(vector<int>& nums,int maxOperations,int maxNum){
        int cnt = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > maxNum){
                cnt += (nums[i] - 1) / maxNum;//计算需要分成多少个袋子，假设当前袋子里有x个球，最多只能放maxNum个球，那么需要分成 (x-1)/maxNum + 1 个袋子,需要的次数为 (x-1)/maxNum
            }
            
            if(cnt > maxOperations){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

