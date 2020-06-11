#include <iostream>
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

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;

        ListNode *first = &dummy;
        ListNode *second = &dummy;

        // 先让快的走N个
        int count = n;
        while (count-- > 0){
            first = first->next;
        }
        while(first->next != NULL){
            first = first->next;
            second = second->next;
        }

        // obj 是要删除的那个
        ListNode *obj = second->next;
        second->next = obj->next;

        return dummy.next;
    }
};
// @lc code=end

int func(int idx){
    ListNode head(-1);
    ListNode *tmp = &head;
    for (int i = 0 ; i < 5 ; i++){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    cout << "源:" << head.next << endl;
    Solution solu;
    cout << idx << ": " << solu.removeNthFromEnd(head.next, idx) << endl;
}

int main()
{
    for (int i = 0 ; i <= 5 ; i++){
        func(i);
    }
}