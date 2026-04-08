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
    ListNode*  reverse(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }           
            ListNode* newHead = reverse(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newHead;
        }
    bool isPalindrome(ListNode* head) {
       
        ListNode* reverselist = reverse(head);
        while(head && reverselist){
            if(head->val != reverselist->val){
                return false;
            }
            head = head->next;
            reverselist = reverselist->next;
        }
        return true;
    }
};