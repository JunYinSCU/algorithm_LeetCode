/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 *
 * https://leetcode.cn/problems/max-number-of-k-sum-pairs/description/
 *
 * algorithms
 * Medium (59.09%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    47.2K
 * Total Submissions: 79.8K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * 给你一个整数数组 nums 和一个整数 k 。
 * 
 * 每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。
 * 
 * 返回你可以对数组执行的最大操作数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4], k = 5
 * 输出：2
 * 解释：开始时 nums = [1,2,3,4]：
 * - 移出 1 和 4 ，之后 nums = [2,3]
 * - 移出 2 和 3 ，之后 nums = []
 * 不再有和为 5 的数对，因此最多执行 2 次操作。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,1,3,4,3], k = 6
 * 输出：1
 * 解释：开始时 nums = [3,1,3,4,3]：
 * - 移出前两个 3 ，之后nums = [1,4,3]
 * 不再有和为 6 的数对，因此最多执行 1 次操作。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n) 空间复杂度O(n)
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){           
            if(m.count(k-nums[i])){ //查找该数左边是否存在k-nums[i]
                m[k-nums[i]]--;     //如果存在，则要减少个数
                if(m[k-nums[i]] == 0){
                    m.erase(k-nums[i]);
                }
                        //不需把当前结果减去，因为此时还没将该数加入到哈希表中
                ans++;  //更新结果
            }else{
                m[nums[i]]++;   //如果不存在k-nums[i]，才把数加入到哈希表中
            }
            
        }
        return ans;
    }
};
// @lc code=end

