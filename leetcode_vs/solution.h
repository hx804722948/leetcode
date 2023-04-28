// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

#include <cstddef>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**********************************************************************************/
struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr)
	{
	}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int x = 0, y = 0, carry = 0, sum = 0;
		ListNode *h = nullptr, **t = &h;

		while (l1 != nullptr || l2 != nullptr)
		{
			x = getValueAndMoveNext(l1);
			y = getValueAndMoveNext(l2);

			sum = carry + x + y;

			auto node = new ListNode(sum % 10);
			*t = node;
			t = (&node->next);

			carry = sum / 10;
		}

		if (carry > 0)
		{
			auto node = new ListNode(carry % 10);
			*t = node;
		}

		return h;
	}

private:
	int getValueAndMoveNext(ListNode* & l)
	{
		int x = 0;
		if (l != nullptr)
		{
			x = l->val;
			l = l->next;
		}
		return x;
	}
};
