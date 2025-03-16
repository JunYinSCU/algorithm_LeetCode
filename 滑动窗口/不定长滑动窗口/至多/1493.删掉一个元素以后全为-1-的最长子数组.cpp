/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //实际是判断最长的包含一个0的子数组
        int left = 0;
        int res = 0;
        int count0 = 0;

        for(int right = 0;right < nums.size();right++){
            if(nums[right] == 0){
                count0++;
            }
            while(count0 > 1){ //如果超过一个0，缩小窗口
                if(nums[left] == 0){
                    count0--;
                }
                left++;
            }
            res = max(res,right - left +1);//更新结果
        }
        
        return res - 1;//因为至少要删除一个元素，所以结果要减1（无论是删除的0还是1）
    }
};
// @lc code=end

