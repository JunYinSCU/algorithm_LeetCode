/*
 * @lc app=leetcode.cn id=2762 lang=cpp
 *
 * [2762] 不间断子数组
 *
 * https://leetcode.cn/problems/continuous-subarrays/description/
 *
 * algorithms
 * Medium (54.73%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 19.3K
 * Testcase Example:  '[5,4,2,4]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。nums 的一个子数组如果满足以下条件，那么它是 不间断 的：
 * 
 * 
 * i，i + 1 ，...，j  表示子数组中的下标。对于所有满足 i <= i1, i2 <= j 的下标对，都有 0 <= |nums[i1] -
 * nums[i2]| <= 2 。
 * 
 * 
 * 请你返回 不间断 子数组的总数目。
 * 
 * 子数组是一个数组中一段连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,4,2,4]
 * 输出：8
 * 解释：
 * 大小为 1 的不间断子数组：[5], [4], [2], [4] 。
 * 大小为 2 的不间断子数组：[5,4], [4,2], [2,4] 。
 * 大小为 3 的不间断子数组：[4,2,4] 。
 * 没有大小为 4 的不间断子数组。
 * 不间断子数组的总数目为 4 + 3 + 1 = 8 。
 * 除了这些以外，没有别的不间断子数组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：6
 * 解释：
 * 大小为 1 的不间断子数组：[1], [2], [3] 。
 * 大小为 2 的不间断子数组：[1,2], [2,3] 。
 * 大小为 3 的不间断子数组：[1,2,3] 。
 * 不间断子数组的总数目为 3 + 2 + 1 = 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int left = 0;
        map<int,int> cnt;//map是有序的，可以通过rbegin()和begin()来获取最大值和最小值

        for(int right = 0; right < nums.size();right++)
        {
            cnt[nums[right]]++;
            
            while(cnt.rbegin()->first - cnt.begin()->first > 2) //最大值减最小值若超过2，则缩小窗口
            {
                cnt[nums[left]]--;
                if(cnt[nums[left]] == 0) //如果出现次数为0，则删除该键值对
                {
                    cnt.erase(nums[left]);
                }
                left++;
            }

            res += right - left + 1; //从left left+1 ... right都是满足要求的,总共有right-left+1个
        }

        return res;
    }
};
// @lc code=end

