/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 *
 * [2799] 统计完全子数组的数目
 *
 * https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/
 *
 * algorithms
 * Medium (66.53%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 21.8K
 * Testcase Example:  '[1,3,1,2,2]'
 *
 * 给你一个由 正 整数组成的数组 nums 。
 * 
 * 如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：
 * 
 * 
 * 子数组中 不同 元素的数目等于整个数组不同元素的数目。
 * 
 * 
 * 返回数组中 完全子数组 的数目。
 * 
 * 子数组 是数组中的一个连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,1,2,2]
 * 输出：4
 * 解释：完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,5,5,5]
 * 输出：10
 * 解释：数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2000
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(n)
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int diff = s.size();
        int left = 0;
        int res = 0;
        unordered_map<int, int> m;

        for(int right =  0;right < nums.size();right++){
            m[nums[right]]++;
            while(m.size() == diff){
                res += nums.size() - right; //为什么该窗口后面的子数组也满足呢？因为子数组不同值个数以及和原数组相同了，所有后面的数字也必定是重复的
                m[nums[left]]--;
                if(m[nums[left]] == 0){
                    m.erase(nums[left]);
                }
                left++;
            }
            //res += left;
        }
        return res;
    }
};
// @lc code=end

