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
    bool hasCycle(ListNode* head) {
        // unordered_set <ListNode*> sets;
        // while(head){
        //     int temp = sets.size()+1;
        //     sets.insert(head);
        //     if(temp!=sets.size()){return true;}
        //     head = head->next;
        // }
        // return false;



        ListNode* cycle1 = head;
        ListNode* cycle2 = head;
        int num = 0;
        while(cycle2){
            if(num!=0 && cycle1->val == cycle2->val && cycle1->next == cycle2->next){
                return true;
            }
            cycle1 = cycle1->next;
            cycle2 = cycle2->next;
            if(cycle2){
                cycle2 = cycle2->next;
            }
            num++;
        }
        return false;

        
        
    }
};
