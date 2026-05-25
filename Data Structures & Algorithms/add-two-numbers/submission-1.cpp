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
        stack<int> stackL1;
        stack<int> stackL2;
        stack<int> stackF;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        while(curr1 != nullptr){
            stackL1.push(curr1->val);
            curr1 = curr1->next;
        }
        while(curr2 != nullptr){
            stackL2.push(curr2->val);
            curr2 = curr2->next;
        }

        
        int num1 = 0;

        while (!stackL1.empty()) {
            num1 = num1 * 10 + stackL1.top();   
            stackL1.pop();
        }
        

        int num2 = 0;

        while (!stackL2.empty()) {
            num2 = num2 * 10 + stackL2.top();   
            stackL2.pop();
        }


        int final = num1+num2;
        if (final ==0) stackF.push(final);
        else{
            while(final>0){
                stackF.push(final%10);
                final/=10;
            }
        }


        ListNode* head = nullptr;

        while (!stackF.empty()) {
            int digit = stackF.top();
            stackF.pop();

            ListNode* newNode = new ListNode(digit);
            newNode->next = head;
            head = newNode;
        }

        return head;



    }
};
