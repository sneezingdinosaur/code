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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            size++;
        }

        int total = size;
        
        
        curr = head;
        ListNode* prev = nullptr;
        ListNode* first = curr;


        while(size>=k){ 
            ListNode* prevFirst = first;
            first = curr;

            for(int i = 0; i<k; i++){
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = prev;
                prev = temp;
            }

            first->next = curr;
            if(size!=total) prevFirst->next = prev;

            if(size == total){head = prev;}
            size-=k;
        }

        return head;
    }
};
