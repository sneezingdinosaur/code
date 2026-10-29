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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){return list2;}
        if(!list2){return list1;}
        ListNode* curr;
        ListNode* other;
        ListNode* temp;
        ListNode* head;
        if(list1->val<list2->val){
            curr = list1;
            head = curr;
            other = list2;
        }
        else{
            curr = list2;
            head = curr;
            other = list1;
        }
        while(other!=nullptr){
            if(curr->next == nullptr || curr->next->val > other->val){
                temp = curr->next;
                curr->next = other;
                other = temp;
                curr = curr->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
