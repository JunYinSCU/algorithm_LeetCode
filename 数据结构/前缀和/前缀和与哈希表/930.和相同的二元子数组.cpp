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
class Solution {
public:
    //方法二：前缀和+哈希表
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     vector<int> pre(nums.size() + 1);
    //     pre[0] = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         pre[i+1] = pre[i] + nums[i];
    //     }
    //     unordered_map<int,int> cnt;
    //     int res = 0;
    //     //区间[i,j]的和为：pre[j+1] - pre[i];
    //     //pre[j+1] - pre[i] =  goal;
    //     //pre[i] = pre[j+1] - goal;
    //     for(int i = 0; i < pre.size(); i++){
    //         if(cnt.count(pre[i]-goal)){
    //             res += cnt[pre[i]-goal];
    //         }
    //         cnt[pre[i]]++;
    //     }

    //     return res;
    // }

    //方法二:恰好型滑动窗口
    int numSubarraysWithSum(vector<int>& nums, int goal){
        if(goal == 0)
            return slideWindow(nums,goal);
        return slideWindow(nums,goal) - slideWindow(nums,goal-1);
    }

    int slideWindow(vector<int>& nums, int goal){
        //寻找sum<=goal的个数
        int left = 0;
        int res = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end

