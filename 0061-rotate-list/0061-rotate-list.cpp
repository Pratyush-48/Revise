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
        if(head==NULL)return NULL;
        int n = 0;
        unordered_map<int,ListNode*>m;
        ListNode* trav = head;
        while(trav){
            n++;
            m[n] = trav;
            trav = trav->next;
        }
        k = k%n;
        if(k==0) return head;
        ListNode* change = m[n-k+1];
        ListNode* change_prev = m[n-k];
        change_prev->next = NULL;
        ListNode* last = m[n];
        last->next = head;
        head = change;
        return head;
    }
};