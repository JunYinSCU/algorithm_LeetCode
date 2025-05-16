/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 *
 * https://leetcode.cn/problems/next-greater-node-in-linked-list/description/
 *
 * algorithms
 * Medium (66.03%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    70.1K
 * Total Submissions: 105.7K
 * Testcase Example:  '[2,1,5]'
 *
 * 给定一个长度为 n 的链表 head
 * 
 * 对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。
 * 
 * 返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i
 * 个节点没有下一个更大的节点，设置 answer[i] = 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [2,1,5]
 * 输出：[5,5,0]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [2,7,4,3,5]
 * 输出：[7,0,5,5,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数为 n
 * 1 <= n <= 10^4
 * 1 <= Node.val <= 10^9
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> s;//first: index, second: value
        vector<int> ans;
        int index = -1;

        while(head){
            index++;
            ans.push_back(0);   //初始化为0
            while(!s.empty() && s.top().second < head->val){    //如果栈顶元素小于当前元素
                //说明当前元素是栈顶元素的下一个更大元素
                ans[s.top().first] = head->val; //找到栈顶元素的位置，在ans中更新
                s.pop();    //出栈，继续判断下一个栈顶元素
            }
            s.push({index, head->val}); //把当前元素的下标和当前元素的值压入栈中
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end

