/*
 * @lc app=leetcode.cn id=3355 lang=cpp
 *
 * [3355] 零数组变换 I
 *
 * https://leetcode.cn/problems/zero-array-transformation-i/description/
 *
 * algorithms
 * Medium (44.04%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 10.2K
 * Testcase Example:  '[1,0,1]\n[[0,2]]'
 *
 * 给定一个长度为 n 的整数数组 nums 和一个二维数组 queries，其中 queries[i] = [li, ri]。
 * 
 * 对于每个查询 queries[i]：
 * 
 * 
 * 在 nums 的下标范围 [li, ri] 内选择一个下标 子集。
 * 将选中的每个下标对应的元素值减 1。
 * 
 * 
 * 零数组 是指所有元素都等于 0 的数组。
 * 
 * 如果在按顺序处理所有查询后，可以将 nums 转换为 零数组 ，则返回 true，否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,0,1], queries = [[0,2]]
 * 
 * 输出： true
 * 
 * 解释：
 * 
 * 
 * 对于 i = 0：
 * 
 * 
 * 选择下标子集 [0, 2] 并将这些下标处的值减 1。
 * 数组将变为 [0, 0, 0]，这是一个零数组。
 * 
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [4,3,2,1], queries = [[1,3],[0,2]]
 * 
 * 输出： false
 * 
 * 解释：
 * 
 * 
 * 对于 i = 0： 
 * 
 * 
 * 选择下标子集 [1, 2, 3] 并将这些下标处的值减 1。
 * 数组将变为 [4, 2, 1, 0]。
 * 
 * 
 * 对于 i = 1：
 * 
 * 选择下标子集 [0, 1, 2] 并将这些下标处的值减 1。
 * 数组将变为 [3, 1, 0, 0]，这不是一个零数组。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= li <= ri < nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //  //说明：对于每个queries的子集的每个下标，可以选择当前num减少也可以选择不减少。也就是说减少到0就不再减少了
    // //方法一：隐式差分
    // bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //     int n = nums.size();
    //     vector<int> d(n+1,0);
    //    //此时d数组表示的是第i位上可以减少的次数的差分数组
    //     for(int i = 0; i < queries.size(); i++){
    //         int l = queries[i][0];
    //         int r = queries[i][1];
    //         d[l]++;  //因为是记录可以减少的次数，所以l处+1
    //         d[r+1]--;    //同理r+1处-1         
    //     }
    //     

    //     int sum = 0;
    //     for(int i = 0; i < n; i++){
    //         sum += d[i];     //sum为当前可以减少的次数
    //         if(sum < nums[i]){   //如果当前可以减少的次数sum小于当前nums[i]，则说明不可能变成零数组
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    //方法二：显式差分
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> d(n+1,0);

        d[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            d[i] = nums[i] - nums[i-1];
        }
        //初始化差分数组，为减少过后的nums数组的差分数组

        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            d[l]--; //因为是记录nums数组的差分，所以l处-1
            d[r+1]++;       //同理r+1处+1     
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += d[i];        //sum为当前nums[i]减少过后的值
            if(sum > 0){    //如果减了过后还是大于0，说明不可能变成零数组
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

