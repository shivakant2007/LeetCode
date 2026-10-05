class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min-heap
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Put first node of every list into heap
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* current = pq.top();
            pq.pop();

            // Add it to result
            tail->next = current;
            tail = tail->next;

            // Add next node from same list
            if (current->next != nullptr) {
                pq.push(current->next);
            }
        }

        return dummy->next;
    }

private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};