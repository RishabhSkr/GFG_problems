//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
   Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    unordered_map<int, bool> mp;
    Node* prev = head;
    Node* curr = head->next;

    mp[head->data] = true;

    while (curr != NULL) {
        if (mp.find(curr->data) != mp.end()) {
            prev->next = curr->next;
            Node* tmp = curr;
            curr = curr->next;
            tmp->next = NULL;
            delete tmp;
        } else {
            mp[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
};


//{ Driver Code Starts.

int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends