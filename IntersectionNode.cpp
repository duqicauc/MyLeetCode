/*
Write a program to find the node at which the intersection of two singly linked lists begins.
程序功能：查找两个单链表的首个交叉节点，并返回该节点。

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
(1)If the two linked lists have no intersection at all, return null.
   如果两个链表没有交叉节点，返回null。
(2)The linked lists must retain their original structure after the function returns.
   函数结束后，两个链表必须保持原有结构不变。
(3)You may assume there are no cycles anywhere in the entire linked structure.
   假设：在整个链表结构中，不存在环路。
(4)Your code should preferably run in O(n) time and use only O(1) memory.
   时间复杂度：O(n)、空间复杂度O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 计算两个链表的长度，若有链表为空则直接返回NULL
	    int lenA=0,lenB=0;
	    ListNode *p = headA;
	    while(p != NULL){
		    lenA++;
		    p = p->next;
	   }
	    p = headB;
	    while(p != NULL){
		    lenB++;
		    p = p->next;
	    }
	    if(lenA==0 || lenB==0)
		    return NULL;
	    // 将较长的那个链表的指针先走steps步
	    ListNode *pa,*pb;
	    pa = headA;
	    pb = headB;
	    int steps = 0, n;
	    if(lenA > lenB){
		    steps = lenA - lenB;
		    n=0;
		    while(n < steps){
			    pa = pa->next;
		    	n++;
		    }
	    }else{
		    steps = lenB - lenA;
		    n=0;
		    while(n < steps){
			    pb = pb->next;
			    n++;
		    }
	    }
	    // 两个链表指针同时后移
	    while(pa != pb && pa != NULL){
		    pa = pa->next;
		    pb = pb->next;
	    }

	    if(pa != NULL)
		    return pa;
	    else
		    return NULL;
    }
};
