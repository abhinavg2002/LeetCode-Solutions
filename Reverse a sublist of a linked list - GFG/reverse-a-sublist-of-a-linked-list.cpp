// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
   public:
   Node* reverseBetween(Node* head, int m, int n)
   {
       if(!head)
           return head;
           
       Node* ptr1 = head;
       int count=1;
       while(ptr1 && count<m-1){
           ptr1 = ptr1 -> next;
           ++count;
       }
       
       if(!ptr1)
           return head;
       
       if(m==1)
           ptr1 = NULL;
       
       if(m == n)
           return head;
       
       Node* ptr2 = head;
       count=1;
       while(ptr2 && count<=n){
           ptr2 = ptr2 -> next;
           ++count;
       }
       
       Node* tail = head;
       while(tail -> next!=ptr2)
           tail = tail -> next;
       
       if(ptr2){
           tail -> next = NULL;
       }
       
       Node* prev = NULL;
       Node* curr;
       if(m > 1)
           curr = ptr1 -> next;
       else
           curr = head;
       Node* nextNode;
       
       if(m>1)
           ptr1 -> next = NULL;
       
       while(curr){
           nextNode = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = nextNode;
       }
       if(m>1)
           ptr1 -> next = prev;
       
       ptr1 = prev;
       while(ptr1 -> next)
           ptr1 = ptr1 -> next;
       
       ptr1 -> next = ptr2;
       
       if(m>1)
           return head;
       
       return prev;
   }
};



// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends