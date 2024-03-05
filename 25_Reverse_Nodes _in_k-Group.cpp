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
          if(head==NULL){
         return NULL;
     }
     ListNode* next=NULL;
     ListNode* curr=head;
     ListNode* prev=NULL;
     int c=0;
     while (curr != NULL && c< k) {
            curr = curr->next;
            c++;
        }
        if (c < k) {
            return head;
        }

        curr = head;
        c = 0;
     while(curr!=NULL&&c<k){
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
         c++;
     }
     if(next!=NULL){
         head->next=reverseKGroup(next,k);
     }
     return prev;
    }
};
