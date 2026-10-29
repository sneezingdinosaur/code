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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*prev = head;
        ListNode* l = head;
        ListNode*after = head;
        ListNode* r = head;
        for(int i = 0; i<n; i++){
            r = r->next;
        }
        if (!r){
            return head->next;
        }
        
        while(r){
            prev = l;
            l = l->next;
            after = l->next;
            r = r->next;
        }
        prev->next = after;
        return head;






        // ListNode*prev = head;
        // ListNode*curr = head;
        // ListNode*after = head->next;
        // ListNode* scope = head;

        // int total = 0;
        // while(scope){
        //     scope = scope->next;
        //     total++;
        // }
        // int index = total-n;
        // int count = 0;
        // if(count==index){
        //     head = head->next;
        //     return head;
        // }
        // while(count != index){
        //     prev = curr;
        //     curr = curr->next;
        //     if(curr){
        //         after = curr->next;
        //     }

        //     count++;
        // }
        // prev->next = after;
        // return head;

        
    }
};
