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
    ListNode* rev(ListNode* h){
        ListNode* prev = NULL;
        ListNode* fut = NULL;
        ListNode* curr = h;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode*slow = head;
        ListNode* fast = head;
        ListNode*prev = NULL;
        while(fast && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // so our slow is new head where we will reverse it
        prev->next = NULL;
        ListNode* new_head = rev(slow);
        int result = 0;
        ListNode* trav1 = head;
        ListNode* trav2 = new_head;
        while(trav1 && trav2){
            result = max(result,trav1->val + trav2->val);
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        return result;
    }
};