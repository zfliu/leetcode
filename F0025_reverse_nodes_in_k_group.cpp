#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ostream& operator << (ostream& out, const ListNode *node)
{
    while (node){
        out << node->val;
        if (node->next != NULL){
            out << " -> ";
        }
        node = node->next;
    }
    return out;
}

ListNode* NewList(std::vector<int> values){
    ListNode node(0);
    ListNode *head = &node;
    for (int i = 0 ; i < values.size() ; i++){
        head->next = new ListNode(values[i]);
        head = head->next;
    }
    return node.next;
}

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (61.20%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    72.9K
 * Total Submissions: 119.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1){
            return head;
        }

        ListNode *res = NULL; // 返回结果
        ListNode *tail = NULL;

        while(head){
            std::stack<ListNode*> s;
            ListNode *ohead = head;
            for (int i = 0 ; i < k && head ; i++){
                if (res == NULL && i == (k - 1)){
                    res = head;
                }
                if (tail == NULL && i == 0){
                    tail = head;
                }
                s.push(head);
                head = head->next;            
            }

            if (s.size() == k){
                // 数量够,反转
                while(!s.empty()){
                    tail->next = s.top();
                    s.pop();
                    tail = tail->next;
                    tail->next = NULL;
                }
            }else{
                tail->next = ohead;
            }
        }

        if (res == NULL){
            return tail;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solu;
    //cout << solu.reverseKGroup(NewList(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 1}), 3) << endl;

    //cout << solu.reverseKGroup(NewList(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 1}), 1) << endl;

    //cout << solu.reverseKGroup(NewList(vector<int>{1, 2}), 3) << endl;

    cout << solu.reverseKGroup(NewList(vector<int>{1, 2}), 2) << endl;
}
