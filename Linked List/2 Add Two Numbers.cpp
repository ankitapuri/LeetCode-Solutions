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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode;
        ListNode* head;
        dummyNode = head = new ListNode(-1);
        
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        int carry = 0;
        int total = 0;
        while(l1!=NULL and l2!=NULL){
            int firstVal =  l1->val ;
            int secondVal =  l2->val;
            int total = firstVal + secondVal + carry;
            if(total>9)
            {carry = total / 10;
              total %= 10;
            }
            else carry =0;
            ListNode* newNode = new ListNode(total);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
            l1=l1->next;
            l2=l2->next;
         
        }
        while(l1!=NULL)
        {
            total = l1->val + carry;
            
            if(total>9)
            {
                carry = total / 10;
                total %= 10;
            }
            else
            carry=0;
            ListNode *newnode = new ListNode(total);
            dummyNode->next = newnode;
            dummyNode= dummyNode->next;
            l1 = l1->next;
        }
            while(l2!=NULL)
        {
            total = l2->val + carry;
            
            if(total>9)
            {
                carry = total / 10;
                total %= 10;
            }
            else
            carry=0;
            ListNode *newnode = new ListNode(total);
            dummyNode->next = newnode;
            dummyNode= dummyNode->next;
            l2= l2->next;

        }
        
        if(carry)
            dummyNode->next = new ListNode(1);
        
        return head->next;
    }
};