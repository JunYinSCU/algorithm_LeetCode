/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 *
 * [2537] 统计好子数组的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-good-subarrays/description/
 *
 * algorithms
 * Medium (56.08%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 20.4K
 * Testcase Example:  '[1,1,1,1,1]\n10'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。
 * 
 * 一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。
 * 
 * 子数组 是原数组中一段连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,1,1,1,1], k = 10
 * 输出：1
 * 解释：唯一的好子数组是这个数组本身。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,1,4,3,2,2,4], k = 2
 * 输出：4
 * 解释：总共有 4 个不同的好子数组：
 * - [3,1,4,3,2,2] 有 2 对。
 * - [3,1,4,3,2,2,4] 有 3 对。
 * - [1,4,3,2,2,4] 有 2 对。
 * - [4,3,2,2,4] 有 2 对。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^9
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(n)
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        int left = 0;
        long long cnt = 0;
        unordered_map<int,int> window;

        for(int right = 0;right < nums.size();right++){
            window[nums[right]]++;
            cnt+= window[nums[right]] -1; // 根据阶乘的性质，需要增加window[nums[right]] -1

            while(cnt >= k){
                res += nums.size() - right;
                window[nums[left]]--;           
                cnt -= window[nums[left]]; //同理，当左窗口移动时，需要减去window[nums[left]]                             
                left++;
            }
            
        }
        //小结：判断需要加减多少，可以通过观察举例的方式
        return res;
    }
};
// @lc code=end

