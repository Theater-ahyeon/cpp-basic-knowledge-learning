#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> modes;
        while (headA != NULL) {
            modes.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL) {
            if (modes.count(headB) > 0) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

// 方便你在 VSCode 点“运行当前 cpp 文件”时能直接看到结果。
int main() {
    // 构造相交链表：
    // A: 1 -> 2 -> 8 -> 9
    // B: 3 ------^ (与 A 在 8 处相交)
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n8 = new ListNode(8);
    ListNode* n9 = new ListNode(9);
    n1->next = n2;
    n2->next = n8;
    n8->next = n9;

    ListNode* m3 = new ListNode(3);
    m3->next = n8;

    Solution s;
    ListNode* inter = s.getIntersectionNode(n1, m3);
    if (inter) {
        cout << "Intersection at node value: " << inter->val << '\n';
    } else {
        cout << "No intersection\n";
    }

    // 释放内存（注意相交节点只能释放一次）
    unordered_set<ListNode*> uniq;
    for (ListNode* p = n1; p != NULL; p = p->next) uniq.insert(p);
    for (ListNode* p = m3; p != NULL; p = p->next) uniq.insert(p);
    for (ListNode* p : uniq) delete p;

    return 0;
}