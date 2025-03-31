/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 *
 * https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/description/
 *
 * algorithms
 * Medium (46.76%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    60.5K
 * Total Submissions: 129.3K
 * Testcase Example:  '[5,1,3]\n[1,2,3,4,5]\n7'
 *
 * 给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i
 * 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。
 * 
 * 同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。
 * 
 * 请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * 输出：[4,0,3]
 * 解释：
 * - 第 0 个咒语：5 * [1,2,3,4,5] = [5,10,15,20,25] 。总共 4 个成功组合。
 * - 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
 * - 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,9,12,15] 。总共 3 个成功组合。
 * 所以返回 [4,0,3] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：spells = [3,1,2], potions = [8,5,8], success = 16
 * 输出：[2,0,2]
 * 解释：
 * - 第 0 个咒语：3 * [8,5,8] = [24,15,24] 。总共 2 个成功组合。
 * - 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
 * - 第 2 个咒语：2 * [8,5,8] = [16,10,16] 。总共 2 个成功组合。
 * 所以返回 [2,0,2] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == spells.length
 * m == potions.length
 * 1 <= n, m <= 10^5
 * 1 <= spells[i], potions[i] <= 10^5
 * 1 <= success <= 10^10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(NlogN)
    //空间复杂度O(1)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());

        sort(potions.begin(),potions.end()); //先排序

        for(int i = 0;i < spells.size();i++){

            long long target  = (success - 1) / spells[i] + 1;  //向上去整

            if(target <= potions.back())
                res[i] = lower_bound(potions,(int)target);
            else
                res[i] = 0;
        }

        return res;
    }

    int lower_bound(vector<int>& n, int target){
        int left = 0;
        int right = n.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(n[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return  n.size() - left;    //此处返回的是大于等于目标值的个数
    }
};
// @lc code=end

