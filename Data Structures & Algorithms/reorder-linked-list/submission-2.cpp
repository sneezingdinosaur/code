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
    void reorderList(ListNode* head) {
        // ListNode* s = head;
        // ListNode* f = head->next;
        // ListNode* start = head;

        // while(f){
        //     s = s->next;
        //     f = f->next;
        //     if(f){
        //         f = f->next;
        //     }
        // }

        // ListNode* second = s->next;
        // ListNode* prev = nullptr;
        // s->next = nullptr;

        // while(second){
        //     ListNode* tmp = second->next;
        //     second->next = prev;
        //     prev = second;
        //     second = tmp;
        // }

        // ListNode* first = head;
        // second = prev;
        // while (second){
        //     ListNode* tmp1 = first -> next;
        //     ListNode* tmp2 = second -> next;
        //     first -> next = second;
        //     second -> next = tmp1;
        //     first = tmp1;
        //     second = tmp2;
        // }






        ListNode* scope = head;
        stack<ListNode*> backend;

        int total = 0;
        while(scope){
            backend.push(scope);
            scope = scope->next;
            total++;
        }

        int count = 0;
        ListNode* curr = head;
        while(count<total){

            ListNode* temp = head->next;

            curr->next = backend.top();
            backend.pop();
            curr = curr->next;

            count++;

            if(count==total){break;}

            curr->next = temp;
            head = temp;
            curr = curr->next;
            
            count++;
        } 
        curr->next = nullptr;





        // ListNode* reversed = nullptr;
        // int length = 0;
        // for(ListNode* curr = head; curr; curr = curr->next){
        //     reversed = new ListNode(curr->val, reversed);
        //     length++;
        // }
        // ListNode begin;
        // ListNode* tail = &begin;
        // int count = 0;
        // while(count<length){
        //     tail->next = head;
        //     head = head->next;
        //     count++;
        //     if(count == length){break;}
        //     tail->next = reversed;
        //     reversed = reversed->next;
        //     count++;
        // }
        // tail->next = nullptr;
    }
};
