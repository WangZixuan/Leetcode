/*


Merge k Sorted Lists


You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6


Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

@Author Zixuan
@Date 2022-01-19
*/


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

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListNodeComparison 
{
public:
    bool operator() (ListNode* node1, ListNode* node2) 
    {
        return node1->val > node2->val;
    }
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.size() == 0)
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparison> headerNodes;

        for (auto node : lists)
            if (node != nullptr)
                headerNodes.push(node);

        ListNode* header = nullptr;

        while (headerNodes.size() > 0)
        {
            ListNode* current = headerNodes.top();
            if (header == nullptr)
                header = current;
            
            headerNodes.pop();
            if (current->next != nullptr)
                headerNodes.push(current->next);

            if (headerNodes.empty()) break;
               
            current->next = headerNodes.top();

            if (headerNodes.size() == 1)
                break;
        }

        return header;
    }
};