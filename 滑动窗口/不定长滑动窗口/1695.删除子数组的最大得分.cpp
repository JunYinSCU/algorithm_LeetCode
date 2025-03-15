/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //题目意思是：找到一个连续的子数组，和最大且无重复元素
        //空间复杂度O(n)
        //时间复杂度O(n)
        int sum = 0;
        int left = 0;
        int ans = 0;
        unordered_map<int,int> map;

        for(int right = 0;right < nums.size();right++){
            sum += nums[right];
            map[nums[right]]++;
            while(map[nums[right]] > 1){
                sum -= nums[left];
                map[nums[left]]--;
                left++;
            }
            ans = max(ans,sum);
            
        }

        return ans;
    }
};
// @lc code=end

