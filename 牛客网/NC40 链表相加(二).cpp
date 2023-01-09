/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stddef.h>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  private:
    string add(string n1, string n2) {
        string res;
        int p = 0;
        int i = n1.size() - 1, j = n2.size() - 1;
        while (i >= 0 && j >= 0) {
            int x = (n1[i] - '0') + (n2[j] - '0') + p;
            res = to_string(x % 10) + res;
            p = x / 10;
            i--, j--;
        }
        while (i >= 0) {
            int x = (n1[i] - '0') + p;
            res = to_string(x % 10) + res;
            p = x / 10;
            i--;
        }
        while (j >= 0) {
            int x = (n2[j] - '0') + p;
            res = to_string(x % 10) + res;
            p = x / 10;
            j--;
        }
        if (p) res = to_string(p) + res;
        return res;
    }

  public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *addInList(ListNode *head1, ListNode *head2) {
        // write code here

        string n1, n2;

        ListNode *cur = head1;
        while (cur) {
            n1.push_back(cur->val + '0');
            cur = cur->next;
        }

        cur = head2;
        while (cur) {
            n2.push_back(cur->val + '0');
            cur = cur->next;
        }

        string n = add(n1, n2);

        ListNode *newhead = new ListNode(0);
        cur = newhead;
        for (const char &c : n) {
            cur->next = new ListNode(c - '0');
            cur = cur->next;
        }
        cur = newhead->next;
        delete newhead;
        return cur;
    }
};