/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 *
 * https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
 *
 * algorithms
 * Medium (62.95%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    36.3K
 * Total Submissions: 57.5K
 * Testcase Example:  '[18,43,36,13,7]'
 *
 * 给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与
 * nums[j] 的数位和相等。
 * 
 * 请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值。如果不存在这样的下标对，返回
 * -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [18,43,36,13,7]
 * 输出：54
 * 解释：满足条件的数对 (i, j) 为：
 * - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
 * - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
 * 所以可以获得的最大和是 54 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [10,12,19,14]
 * 输出：-1
 * 解释：不存在满足条件的数对，返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度NlogN,空间复杂度O(N)
    // int maximumSum(vector<int>& nums) {
    //     unordered_map<int,vector<int>> pos; //记录每个数位和对应的下标
    //     sort(nums.begin(),nums.end());  //排序，方便后续计算

    //     int n = nums.size();
    //     for(int i = 0; i < n; i++){
    //         pos[getSum(nums[i])].push_back(i);  //将数位和作为key，下标作为value存入map
    //     }

    //     int res = -1;
    //     auto it = pos.begin();
        
    //     while(it != pos.end()) {    //遍历哈希表，选择最后两个数，相加并更新结果
    //         vector<int>& index = it->second;
    //         int m = index.size();
    //         if(m >= 2){
    //             int num1 = nums[index[m - 1]];
    //             int num2 = nums[index[m - 2]];
    //             res = max(res,num1+num2);
    //         }
    //         it++;
    //     }
        
    //     return res;
    // }

    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    //方法二：哈希表直接存储数位和该数位的最大值，遍历原数组，判断当前遍历数的数位和在其之前是否存在
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp; //记录每个数位和对应的最大值
        int res = -1;

        for(int i = 0; i < nums.size(); i++){
            int sum = getSum(nums[i]);
            if(mp.count(sum)){  //如果左边存在和当前数的数位一致的数，则更新结果
                res = max(res,mp[sum]+nums[i]); //更新结果
                mp[sum] = max(mp[sum],nums[i]); //更新最大值
            }else{
                mp[sum] = nums[i]; //如果不存在，则直接存入
            }
        }
        return res;
    }
};
// @lc code=end

