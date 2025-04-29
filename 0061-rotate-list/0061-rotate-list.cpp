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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int size=1;
        ListNode*temp=head ,*temp1=head;
        while(temp->next)
        {
            size++;
            temp=temp->next;
        }
        int n =size-k%size-1;
        while(n>0)
        {
          temp1=temp1->next;
          n--;
        }
        
        temp->next = head;
         head = temp1->next;
         temp1->next =NULL;
         return head;
    }
};