/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (40.13%)
 * Likes:    7837
 * Dislikes: 0
 * Total Accepted:    2.7M
 * Total Submissions: 6.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     //存在问题：无法去重
    //     int n = nums.size();
    //     vector<vector<int>> res;
    //     unordered_map<int,int> m;

    //     for(int i = 0;i < n-2;i++){
    //         for(int j = i+1;j<n-1;j++){
    //             if(m.count(-nums[i] - nums[j])){
    //                 res.push_back({nums[i],-nums[i] - nums[j],nums[j]});
    //             }
    //             m[nums[j]]=j;
    //         }
    //     }

    //     return res;
    // }

    //双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n - 2; i++){
            if (nums[i] > 0) break;

            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1,right = n - 1;

            while(left < right){
                if(nums[left] + nums[right] > -nums[i]){
                    right--;
                }else if(nums[left] + nums[right] < -nums[i]){
                    left++;
                }else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    //寻找到目标后，左右指针去重
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    //循环过后，此时左右指针指向的还是相同的数，再次移动一次指向不同的数，方便下一次判断
                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};
// @lc code=end

