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
    ListNode* reverseList(ListNode* head) {
        if (!head){
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next){
            newHead = reverseList(head->next);
            (head -> next) -> next = head;
        }
        head -> next = nullptr;
        return newHead;




        // ListNode* curr = head;
        // ListNode* prev = nullptr;
        // while (curr){
        //     ListNode* nxt = curr -> next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = nxt;
        // }
        // return prev;






        // ListNode* before = nullptr;
        // ListNode* current = head;

        // while(head != nullptr){
        //     current = head;
        //     head = head->next;
        //     current->next = before;
        //     before = current;
        // }
        // return current;
    }
};
