/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.48%)
 * Likes:    1956
 * Dislikes: 0
 * Total Accepted:    739.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;   //单调栈，用于存储下标
        int n = temperatures.size();
        vector<int> ans(n,0);

        for(int i = 0; i < n; i++){
            //如果当前温度大于栈顶元素的温度，则说明找到了下一个更高的温度
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int pre = s.top();  //取出栈顶元素的下标
                ans[pre] = i - pre; //计算天数差
                s.pop();    //弹出栈顶元素
            }
            s.push(i);  //找到合适位置放入当前下标
        }

        return ans;
    }
};
// @lc code=end

