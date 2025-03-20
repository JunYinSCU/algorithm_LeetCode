/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 *
 * https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
 *
 * algorithms
 * Medium (55.34%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 30.8K
 * Testcase Example:  '[1,3,2,3,3]\n2'
 *
 * 给你一个整数数组 nums 和一个 正整数 k 。
 * 
 * 请你统计有多少满足 「 nums 中的 最大 元素」至少出现 k 次的子数组，并返回满足这一条件的子数组的数目。
 * 
 * 子数组是数组中的一个连续元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,2,3,3], k = 2
 * 输出：6
 * 解释：包含元素 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和
 * [3,3] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,4,2,1], k = 3
 * 输出：0
 * 解释：没有子数组包含元素 4 至少 3 次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(n)
    // long long countSubarrays(vector<int>& nums, int k) {
    //     long long res = 0;
    //     int n = nums.size();
    //     int left = 0;
    //     int maxNum = 0;

    //     for(int i = 0; i < n; i++){
    //         maxNum = max(maxNum, nums[i]); //寻找最大值
    //     }

    //     unordered_map<int, int> cnt;
    //     for(int right = 0; right < n; right++){
    //         cnt[nums[right]]++;
    //         while(cnt[maxNum] >= k){ //如果最大值出现次数大于等于k
    //             cnt[nums[left]]--;
    //             left++;
    //         }
    //         res += left; //更新结果，如果当前窗口符合结果，那么当前窗口加上前面的窗口都符合
    //     }

    //     return res;
    // }

    //方法二：进行优化，只需判断最大值即可，不需要存储每个数的出现次数
    //时间复杂度O(n)
    //空间复杂度O(1)
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        int left = 0;
        int maxNum = 0;

        for(int i = 0; i < n; i++){
            maxNum = max(maxNum, nums[i]); //寻找最大值
        }

        int max_cnt = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] == maxNum){ //如果当前数是最大值
                max_cnt++;
            }
            while(max_cnt >= k){ //如果最大值出现次数大于等于k
                if(nums[left] == maxNum){ //如果左边界是最大值
                    max_cnt--; //窗口滑动时，最大值次数减一
                }
                left++;
            }
            res += left; //更新结果，如果当前窗口符合结果，那么当前窗口加上前面的窗口都符合
        }

        return res;
    }

    
};
// @lc code=end

