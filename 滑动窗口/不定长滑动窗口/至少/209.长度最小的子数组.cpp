/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    //方法一：在每次内层循环时更新最小值
    int minSubArrayLen(int target, vector<int>& nums) {
        //最小的情况与最大情况不同，需要在每次内层循环时更新最小值
        int left = 0;
        int sum = 0;
        int res = INT_MAX;

        for(int right = 0;right < nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                res = min(res,right - left + 1);//在每次循环时都更新最小长度
                sum -= nums[left];
                left++;
            }           
        }

        return res == INT_MAX ? 0 : res;
    }

    // //方法二：在每次外层循环时更新最小值
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int left = 0;
    //     int sum = 0;
    //     int res = INT_MAX;

    //     for(int right = 0;right < nums.size();right++){
    //         sum += nums[right];
    //         while(sum - nums[left] >= target){     //循环条件不同，提前判断要减去的下一个值后是否还满足答案         
    //             sum -= nums[left];
    //             left++;
    //         }   
    //         if(sum >= target){
    //             res = min(res,right - left + 1);//更新最小长度
    //         }        
    //     }

    //     return res == INT_MAX ? 0 : res;
    // }
};
// @lc code=end

