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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* temp= head;
        int count=0;
        while(temp){
            count++;
            temp = temp->next;
        }
        k = (k%count);
        if(k==0) return head;
        int run = count - k;
        temp = head;
        ListNode* fast = temp->next;
        ListNode* start = head;
        while(run-1){
            temp = temp->next;
            fast = fast->next;
            run--;
        }
        head = fast;
        temp->next = NULL;
        while(fast->next){
            fast = fast->next;
        }
        fast->next = start;
        return head;
    }
};