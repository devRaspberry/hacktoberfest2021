
#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;


class Node
{
	public:
	int data;
	Node* npx; /* XOR of next and previous node */
};

/* returns XORed value of the node addresses */
Node* XOR (Node *a, Node *b)
{
	return reinterpret_cast<Node *>(
	reinterpret_cast<uintptr_t>(a) ^
	reinterpret_cast<uintptr_t>(b));
}


void insert(Node **head_ref, int data)
{
	// Allocate memory for new node
	Node *new_node = new Node();
	new_node->data = data;


	new_node->npx = *head_ref;

	if (*head_ref != NULL)
	{
		(*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
	}

	// Change head
	*head_ref = new_node;
}

// prints contents of doubly linked
// list in forward direction
void printList (Node *head)
{
	Node *curr = head;
	Node *prev = NULL;
	Node *next;

	cout << "Following are the nodes of Linked List: \n";

	while (curr != NULL)
	{
		cout<<curr->data<<" ";
		next = XOR (prev, curr->npx);

		// update prev and curr for next iteration
		prev = curr;
		curr = next;
	}
}

// Driver code
int main ()
{
	head-->40<-->30<-->20<-->10 */
	Node *head = NULL;
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);

	printList (head);

	return (0);
}

// This code is contributed by rathbhupendra
