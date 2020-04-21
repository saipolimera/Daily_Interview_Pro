// Add two numbers as a linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	Node *next;
	Node(int v, Node *n) :val(v), next(n) {}
}Node;

Node* formList(vector<int> v)
{
	Node *root = new Node(0, nullptr);
	Node *runner = root;
	for (int x : v)
	{
		Node *n = new Node(x,nullptr);
		runner->next = n;
		runner = runner->next;
	}
	return root->next;
}

Node* Add_two_numbers_as_a_linked_list(Node *l1, Node *l2)
{
	int carry = 0;
	Node *dummy = new Node(0,nullptr);
	Node *runner = dummy;
	while (l1 && l2)
	{
		int val = l1->val + l2->val + carry;
		carry = val / 10;
		val = val % 10;
		Node *n = new Node(val, nullptr);
		runner->next = n;
		runner = runner->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1)
	{
		Node *n = new Node(l1->val, nullptr);
		runner->next = n;
		l1 = l1->next;
	}

	while (l2)
	{
		Node *n = new Node(l2->val, nullptr);
		runner->next = n;
		l2 = l2->next;
	}

	return dummy->next;
}

int main()
{
	vector<int> v1{2,4,3};
	vector<int> v2{5,6,4};

	Node *l1 = formList(v1);
	Node *l2 = formList(v2);

	Node *dummy = Add_two_numbers_as_a_linked_list(l1, l2);
	while (dummy)
	{
		cout << dummy->val << ", ";
		dummy = dummy->next;
	}

	return 0;
}

