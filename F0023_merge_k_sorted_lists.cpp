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
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (51.79%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    129K
 * Total Submissions: 249.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if (l == r){
            return lists[l];
        }
        if (r < l){
            return NULL;
        }

        int mid = (l + r) >> 1;
        
        return mergeTwoLists(mergeKLists(lists, l, mid), mergeKLists(lists, mid + 1, r));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode node(0);
        ListNode *head = &node;
        while(l1 != NULL && l2 != NULL){
            if (l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            }else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        head->next = l1 ? l1 : l2;

        return node.next;
    }
};
// @lc code=end

int main()
{

}