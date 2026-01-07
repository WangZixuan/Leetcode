/*


Maximum Level Sum of a Binary Tree


Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 10^9 + 7.
Note that you need to maximize the answer before taking the mod and not after taking it.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Constraints:
The number of nodes in the tree is in the range [2, 5 * 10^4].
1 <= Node.val <= 10^4

@author Zixuan
@date	2026/1/7
*/

#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct SumOfNode
{
    long long leftSum;
    long long rightSum;
};

class Solution
{
public:
    int maxProduct(TreeNode *root)
    {
        unordered_map<TreeNode *, SumOfNode> nodeInfo;

        dfs(root, nodeInfo);
        long long totalSum = nodeInfo[root].leftSum + nodeInfo[root].rightSum + root->val;
        long long maxValue = 0;

        for (auto nodeWithInfo : nodeInfo)
        {
            long long cutLeftValue = nodeWithInfo.second.leftSum * (totalSum - nodeWithInfo.second.leftSum);
            if (cutLeftValue > maxValue)
                maxValue = cutLeftValue;

            long long cutRightValue = nodeWithInfo.second.rightSum * (totalSum - nodeWithInfo.second.rightSum);
            if (cutRightValue > maxValue)
                maxValue = cutRightValue;
        }
        const int modValue = 1e9 + 7;
        return maxValue % modValue;
    }

private:
    int dfs(TreeNode *node, unordered_map<TreeNode *, SumOfNode> &nodeInfo)
    {
        if (node->left != nullptr)
            nodeInfo[node]
                .leftSum = dfs(node->left, nodeInfo);
        else
            nodeInfo[node]
                .leftSum = 0;

        if (node->right != nullptr)
            nodeInfo[node]
                .rightSum = dfs(node->right, nodeInfo);
        else
            nodeInfo[node]
                .rightSum = 0;

        return node->val + nodeInfo[node].leftSum + nodeInfo[node].rightSum;
    }
};
