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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode* temp = head;
        int numberOfNodes = 0;
        while(temp != nullptr){
            temp = temp->next;
            numberOfNodes++;
        }
        if (n == numberOfNodes) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        if (numberOfNodes==1){
            delete head;
            return nullptr;
        }
        else{
            int numberOfNext = numberOfNodes-n;
            ListNode* curr = head;
            ListNode* prev = nullptr;
            for (int i =0; i<numberOfNext;i++){
                prev = curr;
                curr = curr->next;
            }
            ListNode* safe = curr->next;

            delete curr;

            prev->next = safe;
        }

        return head;
    }
};
