/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 *
 * https://leetcode.cn/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (60.25%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    64.2K
 * Total Submissions: 106.4K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k。如果某个连续子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
 * 
 * 请返回这个数组中 「优美子数组」 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2,1,1], k = 3
 * 输出：2
 * 解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,4,6], k = 1
 * 输出：0
 * 解释：数列中不包含任何奇数，所以不存在优美子数组。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * 输出：16
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        //最短子数组，<=k的子数组个数 - <=k-1的子数组个数
        return slideWindow(nums, k) - slideWindow(nums, k - 1);

        //最长子数组，>=k的子数组个数 - >=k+1的子数组个数
        //return slideWindow2(nums, k) - slideWindow2(nums, k + 1);
    }

    int slideWindow(vector<int>& nums, int k) {     //至多型（最短子数组）滑动窗口
        int left = 0;
        int res = 0;
        int count = 0;

        for(int right = 0;right < nums.size();right++) {
            if(nums[right] % 2 == 1) {
                count++;
            }
            while(count > k) { //大于k个奇数时，才不满足要求，收缩窗口寻找最短子数组
                if(nums[left] % 2 == 1) {
                    count--;
                }
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }

    int slideWindow2(vector<int>& nums, int k) { //或者使用至少型（最多子数组）滑动窗口
        int left = 0;
        int res = 0;
        int count = 0;

        for(int right = 0;right < nums.size();right++){
            if(nums[right] % 2 == 1) {
                count++;
            }

            while(count >= k) { //至少k个奇数时，才满足要求，收缩窗口寻找最多子数组
                if(nums[left] % 2 == 1) {
                    count--;
                }
                left++;
            }
            res += left;
        }
        

        return res;
    }
};
// @lc code=end

