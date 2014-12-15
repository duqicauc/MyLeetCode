/* 题目描述 
Given a binary tree, find its maximum depth.
给定一个二叉树，计算它的深度（即最长路径）。

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
概念定义：maximum depth是从根节点往下到最远的叶子节点经过的节点数目。

算法选择：
（1）递归处理
（2）后序遍历
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int left=0,right=0;
        if(root->left != NULL){
            left = maxDepth(root->left);
        }
        if(root->right != NULL){
            right = maxDepth(root->right);
        }
        return left>right? left+1:right+1;
    }
};
