/*
 * @lc app=leetcode.cn id=3488 lang=cpp
 *
 * [3488] 距离最小相等元素查询
 *
 * https://leetcode.cn/problems/closest-equal-element-queries/description/
 *
 * algorithms
 * Medium (32.38%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 11K
 * Testcase Example:  '[1,3,1,4,1,3,2]\n[0,3,5]'
 *
 * 给你一个 循环 数组 nums 和一个数组 queries 。
 * 
 * 对于每个查询 i ，你需要找到以下内容：
 * 
 * 
 * 数组 nums 中下标 queries[i] 处的元素与 任意 其他下标 j（满足 nums[j] == nums[queries[i]]）之间的 最小
 * 距离。如果不存在这样的下标 j，则该查询的结果为 -1 。
 * 
 * 
 * 返回一个数组 answer，其大小与 queries 相同，其中 answer[i] 表示查询i的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,3,1,4,1,3,2], queries = [0,3,5]
 * 
 * 输出： [2,-1,3]
 * 
 * 解释：
 * 
 * 
 * 查询 0：下标 queries[0] = 0 处的元素为 nums[0] = 1 。最近的相同值下标为 2，距离为 2。
 * 查询 1：下标 queries[1] = 3 处的元素为 nums[3] = 4 。不存在其他包含值 4 的下标，因此结果为 -1。
 * 查询 2：下标 queries[2] = 5 处的元素为 nums[5] = 3 。最近的相同值下标为 1，距离为 3（沿着循环路径：5 -> 6 ->
 * 0 -> 1）。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [1,2,3,4], queries = [0,1,2,3]
 * 
 * 输出： [-1,-1,-1,-1]
 * 
 * 解释：
 * 
 * 数组 nums 中的每个值都是唯一的，因此没有下标与查询的元素值相同。所有查询的结果均为 -1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= queries.length <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 0 <= queries[i] < nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);   //按照顺序插入
        }

        for(int i = 0;i < queries.size();i++){
            if(mp.count(nums[queries[i]])){
                vector<int>& indexs = mp[nums[queries[i]]];
                if(indexs.size() == 1){
                    queries[i] = -1;
                }else{
                    //sort(indexs.begin(), indexs.end());
                    //不需要排序，因为在插入时是按照顺序插入的
                    int pos = lowerBound(indexs, queries[i]);
                    int left = pos == 0 ? indexs.size() - 1 : pos - 1;
                    int right = pos == indexs.size() - 1 ? 0 : pos + 1;
                    queries[i] = min(getDistance(indexs[pos], indexs[left], nums.size()), getDistance(indexs[pos], indexs[right], nums.size()));
                }
            }else{
                queries[i] = -1;
            }
        }
        return queries;
    }

    //循环数组中求两个下标之间的最小距离的函数
    int getDistance(int a, int b, int n){
        return min( (a - b + n) % n, (b - a + n) % n);
    }

    int lowerBound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

