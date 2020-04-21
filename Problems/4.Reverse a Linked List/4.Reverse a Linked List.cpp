    // Method 1 - Iterative approach
    ListNode* reverseList(ListNode* head) 
    {
        // using 3 pointers
        ListNode *slow = nullptr;
        ListNode *curr = head;
        ListNode *fast = head;
        
        while(fast)
        {
            fast = curr->next;
            curr->next = slow;
            slow = curr;
            curr = fast;
        }
        return slow;
    }
    
    // Method 2 - recurssive approach
    ListNode* helper(ListNode* prev,ListNode* curr)
    {
        if (curr == nullptr)
            return prev;
        else
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            return helper(curr,temp);
        }
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        return helper(nullptr,head);
    }