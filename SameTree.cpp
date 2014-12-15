/* 题目描述
Given two binary trees, write a function to check if they are equal or not.
给定两棵二叉树判断它们是否相同。
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
相同的标准：
（1）两棵二叉树的结构一致
（2）对应位置节点的值相同
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if((p==NULL && q!=NULL)||(p!=NULL && q==NULL))
		    return false;
	    if(p==NULL && q==NULL)
		    return true;
	    bool isLeftSame,isRightSame;
	    if(p->val == q->val){
		    isLeftSame = isSameTree(p->left,q->left);
		    isRightSame = isSameTree(p->right,q->right);
		    return isLeftSame && isRightSame;
	    }
	    return false;  
    }
};

