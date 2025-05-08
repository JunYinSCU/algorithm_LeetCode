/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 *
 * https://leetcode.cn/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (64.19%)
 * Likes:    494
 * Dislikes: 0
 * Total Accepted:    102K
 * Total Submissions: 158.7K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n' +
  '[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * 设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 跨度 。
 * 
 * 当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
 * 
 * 
 * 
 * 例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。
 * 
 * 
 * 
 * 实现 StockSpanner 类：
 * 
 * 
 * StockSpanner() 初始化类对象。
 * int next(int price) 给出今天的股价 price ，返回该股票当日价格的 跨度 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * 输出：
 * [null, 1, 1, 1, 2, 1, 4, 6]
 * 
 * 解释：
 * StockSpanner stockSpanner = new StockSpanner();
 * stockSpanner.next(100); // 返回 1
 * stockSpanner.next(80);  // 返回 1
 * stockSpanner.next(60);  // 返回 1
 * stockSpanner.next(70);  // 返回 2
 * stockSpanner.next(60);  // 返回 1
 * stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
 * stockSpanner.next(85);  // 返回 6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= price <= 10^5
 * 最多调用 next 方法 10^4 次
 * 
 * 
 */

// @lc code=start
class StockSpanner {
private:
    stack<int> s;
    vector<int> nums;
    int current;
public:
    StockSpanner() {
        current = 0;
    }
    
    // int next(int price) {
    //     int res = 0;
    //     nums.push_back(price);  //当前元素入栈

    //     for(int i = nums.size()-1; i >= 0; i--){    //统计栈中<=当前元素的个数
    //         if(nums[i] > price){
    //             break;
    //         }
    //         res++;
    //     }

    //     return res;
    // }
    int next(int price) {
        nums.push_back(price);
        while(!s.empty() && price >= nums[s.top()]){
            s.pop();
        }
        int span;

        if (s.empty()) {    //如果栈为空了，则说明前面的价格都没有当前价格高，时间跨度为current+1；
            span = current + 1;
        } else {    //否则，栈顶元素就算第一个高于当前价格的天数，相减即为跨度
            span = current - s.top();
        }
        s.push(current);    //当前天数入栈
        current++;  //下一个天数
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

