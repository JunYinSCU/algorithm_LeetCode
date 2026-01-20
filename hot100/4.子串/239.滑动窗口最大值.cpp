/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (50.03%)
 * Likes:    3358
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1);
        deque<int> q;   //队列用于记录最大值和潜在的最大值

        for(int r = 0; r < n; r++){
            // 1.这时候要进来一个新的数据了
            // 先和当前队列中末尾的数据进行对比，如果新数据比末尾数据还大，说明末尾数据当前不可能成为最大值
            // 不是潜在最大值所以出列
            // 如果值相等的情况下保留后者，因为能在滑动窗口中待更久，更有潜力
            while(!q.empty() && nums[q.back()] <= nums[r]){
                q.pop_back();
            }

            // 2.当前数据的下标入列
            // 因为不知道后面的数据的情况，所以统统入列，后续来新数据再回到1判断
            // 下标入列是为了方便判断是否还在滑动窗口区间
            q.push_back(r);

            // 3.计算窗口左端的下标，如果队列最前面的数据不在滑动窗口区间就出队
            int left = r - k + 1;
            if(q.front() < left){
                q.pop_front();
            }

            // 4.记录窗口左端为left时的最大值，此时一定是队列最前端的下标处的值
            if(left >= 0){
                res[left] = nums[q.front()];
            }
        }

        return res;
    }
};
// @lc code=end

