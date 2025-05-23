/*
 * @lc app=leetcode.cn id=1381 lang=cpp
 *
 * [1381] 设计一个支持增量操作的栈
 *
 * https://leetcode.cn/problems/design-a-stack-with-increment-operation/description/
 *
 * algorithms
 * Medium (72.43%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 31.2K
 * Testcase Example:  '["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]\n' +
  '[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]'
 *
 * 请你设计一个支持对其元素进行增量操作的栈。
 * 
 * 实现自定义栈类 CustomStack ：
 * 
 * 
 * CustomStack(int maxSize)：用 maxSize 初始化对象，maxSize 是栈中最多能容纳的元素数量。
 * void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
 * int pop()：弹出栈顶元素，并返回栈顶的值，或栈为空时返回 -1 。
 * void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val
 * 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * 
 * ["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
 * [[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
 * 输出：
 * [null,null,null,2,null,null,null,null,null,103,202,201,-1]
 * 解释：
 * CustomStack stk = new CustomStack(3); // 栈是空的 []
 * stk.push(1);                          // 栈变为 [1]
 * stk.push(2);                          // 栈变为 [1, 2]
 * stk.pop();                            // 返回 2 --> 返回栈顶值 2，栈变为 [1]
 * stk.push(2);                          // 栈变为 [1, 2]
 * stk.push(3);                          // 栈变为 [1, 2, 3]
 * stk.push(4);                          // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
 * stk.increment(5, 100);                // 栈变为 [101, 102, 103]
 * stk.increment(2, 100);                // 栈变为 [201, 202, 103]
 * stk.pop();                            // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
 * stk.pop();                            // 返回 202 --> 返回栈顶值 202，栈变为 [201]
 * stk.pop();                            // 返回 201 --> 返回栈顶值 201，栈变为 []
 * stk.pop();                            // 返回 -1 --> 栈为空，返回 -1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= maxSize, x, k <= 1000
 * 0 <= val <= 100
 * 每种方法 increment，push 以及 pop 分别最多调用 1000 次
 * 
 * 
 */

// @lc code=start
class CustomStack {
private:
    int current;
    vector<int> stack;
    int maxSize;
public:
    CustomStack(int maxSize) {
        current = -1;
        stack.resize(maxSize);
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(current + 1 < maxSize){
            current++;
            stack[current] = x; 
        }
              
    }
    
    int pop() {
        if(current < 0){
            return -1;
        }
        return stack[current--];
    }
    
    void increment(int k, int val) {
        int index = k-1 >= current ? current : k-1;
        for(int i = 0;i <= index ; i++){
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

