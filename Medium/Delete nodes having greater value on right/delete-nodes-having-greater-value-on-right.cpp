//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node * reverseLL(Node * head){
    if(head==NULL || head->next==NULL)return head;
    Node * prev = NULL , *curr = head, *nextptr = head->next;
        while(curr!=NULL){
            curr->next = prev;
                prev = curr;
                curr = nextptr;
            if(nextptr!=NULL)
                nextptr = nextptr ->next;
        }
        return prev;
}
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL)return head;
        
        Node * temp =reverseLL(head);
        head=temp;
        Node *tail=temp->next;
        
        int maxi=temp->data;
        while(tail!=NULL){
            
            if(maxi<=tail->data){
                
                temp->next =tail;
                temp =tail;
            }
            maxi=max(tail->data,maxi);
            if(tail->next==NULL && maxi>tail->data){
                temp->next=NULL;
            }
            tail=tail->next;
        }
        
        return head=reverseLL(head);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends