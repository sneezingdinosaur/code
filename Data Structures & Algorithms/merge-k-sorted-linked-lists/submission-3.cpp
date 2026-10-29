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
    // ListNode* merge(ListNode* head1, ListNode* head2){
    //     ListNode* curr; ListNode* other; ListNode* head;
    //     if(head1==nullptr){
    //         return head2;
    //     }
    //     if(head2==nullptr){
    //         return head1;
    //     }
    //     if(head2->val>=head1->val){
    //         head = head1;
    //         curr = head1;
    //         other = head2;
    //     }
    //     else{
    //         head = head2;
    //         curr = head2;
    //         other = head1;
    //     }

    //     while(other){
    //         ListNode* temp;
    //         if(curr->next == nullptr || curr->next->val > other->val){
    //             temp = curr->next;
    //             curr->next = other;
    //             other = temp;
    //             curr = curr->next;
    //         }
    //         else{
    //             curr = curr->next;
    //         }
    //     }
    //     return head;
    // }

    // ListNode* mergeSort(vector<ListNode*>& lists){
    //     if(lists.size()==0){return nullptr;}
    //     if(lists.size()==1){
    //         return lists[0];
    //     }
    //     int half = lists.size()/2;
    //     vector<ListNode*> list1;
    //     vector<ListNode*> list2;

    //     for(int i = 0; i<lists.size(); i++){
    //         if(i>=half){
    //             list2.push_back(lists[i]);
    //         }
    //         else{
    //             list1.push_back(lists[i]);
    //         }
    //     }

    //     auto left = mergeSort(list1);
    //     auto right = mergeSort(list2);
    //     return merge(left, right);
    // }

    ListNode* mergeList(ListNode* list1, ListNode* list2){
        ListNode dummy;
        ListNode* tail = &dummy;

        while(list1 && list2){
            if (list1->val < list2->val){
                tail -> next = list1;
                list1 = list1->next;
            }
            else{
                tail -> next = list2;
                list2 = list2->next;
            }
            tail = tail -> next;
        }
        if(list1){
            tail->next = list1;
        }
        if(list2){
            tail->next = list2;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }

        while (lists.size()>1){
            vector<ListNode*> mergedLists;
            vector<ListNode*> list1;
            vector<ListNode*> list2;
            for (int i = 0; i<lists.size(); i+=2){
                 ListNode* list1 = lists[i];
                 ListNode* list2;
                 if(i+1<lists.size()){
                    list2 = lists[i+1];
                 }
                 else{
                    list2 = nullptr; 
                 }
                 mergedLists.push_back(mergeList(list1, list2));
            }
            lists = mergedLists;
        }
        return lists[0];


        // return mergeSort(lists);

    }
};
