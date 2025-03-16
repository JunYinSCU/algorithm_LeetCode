/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 *
 * https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
 *
 * algorithms
 * Medium (44.00%)
 * Likes:    269
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 75.2K
 * Testcase Example:  '[1,2,3,10,4,2,3,5]'
 *
 * 给你一个整数数组 arr ，请你删除一个子数组（可以为空），使得 arr 中剩下的元素是 非递减 的。
 * 
 * 一个子数组指的是原数组中连续的一个子序列。
 * 
 * 请你返回满足题目要求的最短子数组的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [1,2,3,10,4,2,3,5]
 * 输出：3
 * 解释：我们需要删除的最短子数组是 [10,4,2] ，长度为 3 。剩余元素形成非递减数组 [1,2,3,3,5] 。
 * 另一个正确的解为删除子数组 [3,10,4] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [5,4,3,2,1]
 * 输出：4
 * 解释：由于数组是严格递减的，我们只能保留一个元素。所以我们需要删除长度为 4 的子数组，要么删除 [5,4,3,2]，要么删除 [4,3,2,1]。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：arr = [1,2,3]
 * 输出：0
 * 解释：数组已经是非递减的了，我们不需要删除任何元素。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：arr = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)：因为在双重for中，我们不会每层都遍历一遍，最多总共遍历n次
    //空间复杂度O(1)
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int res = INT_MAX;
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        //寻找左边的最长的非递减序列
        while(left < n -1 && arr[left] <= arr[left + 1]){
            left++;
        }
        //寻找右边的最长的非递减序列
        while(right > 0 && arr[right] >= arr[right - 1]){
            right--;
        }
        //如果right == 0，说明整个数组都是非递减的，直接返回0
        if(right == 0)
            return 0;

        //现在拿到了两边各自的非递减序列，然后判断一下保留哪一边使得删除的序列更短
        res = min(right,n-left-1); //right表示的值是留右边需要删除的元素个数，n-left-1表示的是留左边需要删除的元素个数

        //开始遍历左右两个序列，寻找有没有更短的，先左后右
        for(int i = 0;i <= left;i++){
            for(int j = right;j < n;j++){
                if(arr[i] <= arr[j]){ //每次遇到符合情况的就更新一次res
                    res = min(res,j - i - 1);
                    break;//这里可以break是因为，如果arr[i] <= arr[j]，那么arr[i]肯定也是<= arr[j+1]的，所以不需要再继续遍历
                }
            }
        }

        //先遍历右边，再遍历左边也是可行的，但是不能提前break，因为可能有更短的序列，耗时更长
        // for(int j= right;j < n;j++){
        //     for(int i = 0;i <= left;i++){
        //         if(arr[i] <= arr[j]){
        //             res = min(res,j - i - 1);
        //             //break;
        //         }
        //     }
        // }

        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

