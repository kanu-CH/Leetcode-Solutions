/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Get lengths of both lists
        int length1 = getLength(headA);
        int length2 = getLength(headB);
        
        // Align start pointers of both lists
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        
        if (length1 > length2) {
            int diff = length1 - length2;
            for (int i = 0; i < diff; i++) {
                head1 = head1->next;
            }
        } else {
            int diff = length2 - length1;
            for (int i = 0; i < diff; i++) {
                head2 = head2->next;
            }
        }
        
        // Traverse both lists together to find the intersection point
        while (head1 != NULL && head2 != NULL) {
            if (head1 == head2) {
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // If no intersection
        return NULL;
    }
};
