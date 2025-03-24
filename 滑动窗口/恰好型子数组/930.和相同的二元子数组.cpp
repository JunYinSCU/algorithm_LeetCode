/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 *
 * https://leetcode.cn/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (57.92%)
 * Likes:    347
 * Dislikes: 0
 * Total Accepted:    60.9K
 * Total Submissions: 104.9K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * 给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
 * 
 * 子数组 是数组的一段连续部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,1,0,1], goal = 2
 * 输出：4
 * 解释：
 * 有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0,0,0], goal = 0
 * 输出：15
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * nums[i] 不是 0 就是 1
 * 0 
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1）
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal == 0)
            return slideWindow(nums,goal);
        return slideWindow(nums,goal) - slideWindow(nums,goal - 1); //<=goal - <=goal-1就是恰好等于goal的个数
    }

    int slideWindow(vector<int>& nums,int goal) { //封装的至多型（最短子数组）滑动窗口函数
        int res = 0;
        int sum = 0;
        int left = 0;

        for(int right = 0;right < nums.size();right++){
            sum += nums[right];
            while(sum > goal){ //严格大于时，才不满足要求，需要收缩窗口
                sum -= nums[left];
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }
};
// @lc code=end

