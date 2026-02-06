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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* h3 = root;
        int carry = 0;
        while(h1 && h2){
            int sum = (h1->val+h2->val+carry);
            carry = sum/10;
            sum = sum%10;
            h3->next = new ListNode(sum);
            h3 = h3->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1){
            int sum = h1->val+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new ListNode(sum);
            h1 = h1->next;
            h3 = h3->next;
        }
        while(h2){
            int sum = h2->val+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new ListNode(sum);
            h2 = h2->next;
            h3 = h3->next;
        }
        if(carry){
            h3->next = new ListNode(carry);
        }
        root = root->next;
        return root;
    }
};