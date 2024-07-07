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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    
        // Initialize the heap with the head of each list
        for (ListNode* head : lists) {
            if (head) {
                minHeap.push(head);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            current->next = smallest; 
            current = current->next;
            
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
