class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Create a gap of n nodes
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;

        delete toDelete;

        return dummy->next;
    }
};