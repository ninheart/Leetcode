class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return;
        stack<ListNode*> st;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            st.push(temp);
            temp = temp->next;
            n++;
        }
        ListNode* p = head;
        for(int i = 0; i < n/2; ++i){
            ListNode* node = st.top();
            node->next = p->next;
            p->next = node;
            p = p->next->next;
            st.pop();
        }
        p->next = NULL;
    }
};
