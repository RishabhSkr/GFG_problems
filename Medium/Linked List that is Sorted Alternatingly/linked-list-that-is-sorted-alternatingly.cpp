//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    Node *reversList(Node * head){
        if(head==NULL || head->next==NULL)return head;
        Node* newHead=reversList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    void sort(Node **head)
    {
         // Code here
        Node * chota =new Node(0),*bada = new Node(0);
        Node * curr = *head,*temp1=chota,*temp2 = bada;
        bool flag = true;
        while(curr){
            if(flag){
                temp1->next =curr;
                temp1 =temp1->next;
                
            }else{
                temp2 ->next = curr;
                temp2 = temp2->next;
            }
                curr=curr->next;
                flag =!flag;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        bada->next =reversList(bada->next);
        temp1->next = bada->next;
        *head = chota->next;
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends