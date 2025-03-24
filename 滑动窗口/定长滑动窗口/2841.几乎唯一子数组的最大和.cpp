/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)，空间复杂度O(n)
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0;
        long long left = 0;
        long long n = nums.size();
        long long temp = 0;
        unordered_map<int, int> count;

        for(int right = 0; right < n; right++) {
            temp += nums[right];
            count[nums[right]]++;
            if(right < k - 1) {
                continue;
            }
            if(count.size() >= m) {
                sum = max(sum,temp);
            }

            temp -= nums[left];
            count[nums[left]]--;
            
            if (count[nums[left]] == 0) {
                count.erase(nums[left]);
            }
            left++;
            
        }
        return sum;
    }

    long long findDifferent(vector<int> nums, int left, int right) {
        // sort(nums.begin() + left, nums.begin() + right + 1);
        // long different = 0;
        // if (left <= right) {
        //     different = 1; // 至少有一个元素
        // }
        // for (int i = left; i < right; i++) {
        //     if (nums[i] != nums[i + 1]) {
        //         different++;
        //     }
        // }
        // return different;
        unordered_set<int> uniqueElements;
        for (int i = left; i <= right; ++i) {
            uniqueElements.insert(nums[i]);
        }
        return uniqueElements.size();
    }
};
// @lc code=end

