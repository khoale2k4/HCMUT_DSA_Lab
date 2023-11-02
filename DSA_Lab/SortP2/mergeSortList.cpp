#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode* head = nullptr;
    ListNode* curr = head;
    while (a && b) {
        if (a->val < b->val) {
            if (!head) {
                head = a;
                curr = head;
            }
            else {
                curr->next = a;
                curr = curr->next;
            }
            a = a->next;
        }
        else {
            if (!head) {
                head = b;
                curr = head;
            }
            else {
                curr->next = b;
                curr = curr->next;
            }
            b = b->next;
        }
    }
    while (a) {
        if (!head) {
            head = a;
            curr = head;
        }
        else {
            curr->next = a;
            curr = curr->next;
        }
        a = a->next;
    }
    while (b) {
        if (!head) {
            head = b;
            curr = head;
        }
        else {
            curr->next = b;
            curr = curr->next;
        }
        b = b->next;
    }
    return head;
}

ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;

    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(slow);

    return mergeLists(left, right);
}


int main()
{
}