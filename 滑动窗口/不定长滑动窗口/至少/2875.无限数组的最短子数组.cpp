/*
 * @lc app=leetcode.cn id=2875 lang=cpp
 *
 * [2875] 无限数组的最短子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/description/
 *
 * algorithms
 * Medium (36.56%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * 给你一个下标从 0 开始的数组 nums 和一个整数 target 。
 * 
 * 下标从 0 开始的数组 infinite_nums 是通过无限地将 nums 的元素追加到自己之后生成的。
 * 
 * 请你从 infinite_nums 中找出满足 元素和 等于 target 的 最短 子数组，并返回该子数组的长度。如果不存在满足条件的子数组，返回
 * -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3], target = 5
 * 输出：2
 * 解释：在这个例子中 infinite_nums = [1,2,3,1,2,3,1,2,...] 。
 * 区间 [1,2] 内的子数组的元素和等于 target = 5 ，且长度 length = 2 。
 * 可以证明，当元素和等于目标值 target = 5 时，2 是子数组的最短长度。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1,2,3], target = 4
 * 输出：2
 * 解释：在这个例子中 infinite_nums = [1,1,1,2,3,1,1,1,2,3,1,1,...].
 * 区间 [4,5] 内的子数组的元素和等于 target = 4 ，且长度 length = 2 。
 * 可以证明，当元素和等于目标值 target = 4 时，2 是子数组的最短长度。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [2,4,6,8], target = 3
 * 输出：-1
 * 解释：在这个例子中 infinite_nums = [2,4,6,8,2,4,6,8,...] 。
 * 可以证明，不存在元素和等于目标值 target = 3 的子数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include <numeric>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    //第一种方法：暴力滑动窗口解法，会超时
    // int minSizeSubarray(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     long long sum = 0;
    //     int left = 0;
    //     long long sumOfNums = 0;
    //     int res = INT_MAX;

    //     for(int i = 0; i < n; i++){ //计算数组和
    //         sumOfNums += nums[i];
    //     }
    //     if(sumOfNums == target){
    //         return n;
    //     }

    //     int l = (target) / sumOfNums + 2;//确定循环次数
        

    //     for(int right = 0;right < l*n;right++){
    //         sum += nums[right%n]; //取余数防止越界
    //         while (sum >= target) {
    //             if (sum == target) {
    //                 res = min(res, right - left + 1);
    //             }
    //             sum -= nums[left % n]; //如果是相等的情况也要继续循环，寻找是否有更短的子数组
    //             left++;
    //         }
    //     }

    //     return res == INT_MAX ? -1 : res;
    // }

    //第二种方法：
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        long long sum = 0;
        for (int right = 0; right < n * 2; right++) {
            sum += nums[right % n];
            while (sum > target % total) {
                sum -= nums[left++ % n];
            }
            if (sum == target % total) {
                ans = min(ans, right - left + 1);
            }
        }
        return ans == INT_MAX ? -1 : ans + target / total * n;


    }
};
// @lc code=end

