#include <iostream>
#include <vector>
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
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (65.73%)
 * Likes:    511
 * Dislikes: 0
 * Total Accepted:    110.3K
 * Total Submissions: 167.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode *res = head->next;
        ListNode *tail = head;
        while(head && head->next){
            ListNode *n1 = head;
            ListNode *n2 = head->next;

            tail->next = n2;

            n1->next = n2->next;
            n2->next = n1;

            head = n1->next;
            tail = n1;
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution solu;

    cout << solu.swapPairs(NewList(vector<int>{1})) << endl;

    cout << solu.swapPairs(NewList(vector<int>{1,2,3,4,5,6,7,8,9})) << endl;

    cout << solu.swapPairs(NewList(vector<int>{1})) << endl;

    cout << solu.swapPairs(NewList(vector<int>{1, 2})) << endl;

}
