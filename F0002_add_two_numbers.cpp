#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ListNode
{
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers2(l1,l2);
        
        ListNode *head = new ListNode(0);

        ListNode **d = &head;
        while (l1){
            *d = new ListNode(l1->val);
            d = &(*d)->next;
            l1 = l1->next;
        }

        ListNode *c = head;
        while (l2){
            auto v = l2->val + c->val;
            l2 = l2->next;            
            c->val = v % 10;
            if (c->next){
                c->next->val += v / 10;
            }else if (l2 || v / 10){
                c->next = new ListNode(v / 10);
            }
            c = c->next;
        }

        while (c && c->val >= 10){
            if (c->next){
                c->next->val += c->val / 10;
            }else{
                c->next = new ListNode(c->val / 10);
            }
            c->val = c->val % 10;
            c = c->next;
        }

        return head;
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode *pre = new ListNode(0);
        ListNode *cur = pre;
        int carry = 0;
        while (l1 || l2){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int v = x + y + carry;
            carry = v / 10;
            cur->next = new ListNode(v % 10);
            cur = cur->next;

            if (l1){
                l1 = l1->next;
            }
            if (l2){
                l2 = l2->next;
            }
        }

        if (carry){
            cur->next = new ListNode(carry);
        }
        delete pre;

        return pre->next;
    }
};

void test_case(vector<int> v1, vector<int> v2){
    ListNode *l1, *l2 = NULL;
    ListNode **tmp = &l1;
    for (int i = 0 ; i < v1.size() ; i++){
        *tmp = new ListNode(v1[i]);
        tmp = &(*tmp)->next;
    }
	cout << l1 <<endl;
    tmp = &l2;
    for (int i = 0 ; i < v2.size() ; i++){
        *tmp = new ListNode(v2[i]);
        tmp = &(*tmp)->next;
    }
    cout << l2 <<endl;
	Solution solu;
    cout << solu.addTwoNumbers(l1,l2) << endl;
    cout << "end of testcase" << endl << endl;;
}

int main()
{
    vector<int> v1 = {9,9};
    vector<int> v2 = {9};

    test_case({9,9},{9});

    test_case({2,4,3},{5,6,4});

    test_case({8,9,9},{2});

    return 0;
}
