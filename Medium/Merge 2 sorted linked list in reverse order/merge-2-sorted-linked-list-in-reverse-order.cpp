//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
    // struct Node * NlognApproach(Node *node1,Node *node2)
    // {
    //     // your code goes here
    //     Node * ptr = node1 ,*ptr2 = node2;
    //     vector<int>list;
    //     while(ptr){
    //         list.push_back(ptr->data);
    //         ptr=ptr->next;
    //     }
    //     while(ptr2){
    //         list.push_back(ptr2->data);
    //         ptr2=ptr2->next;
    //     }
    //   sort(list.begin(), list.end(), [](const int &a, const int &b) {
    //     return a > b;
    // });
    //     Node * head = NULL,*tail=NULL;
    //     for(int i=0;i<list.size();++i){
    //         Node * temp = newNode(list[i]);
    //         if(head == NULL){
    //             head=temp;
    //             tail=head;
    //         }
    //         else{
    //             tail->next = temp;
    //             tail=tail->next;
    //         }
    //     }
    //     return head;
        
    // }  
    Node * reverseLL(Node * head){
        if(head==NULL)return 0;
        Node * prev = NULL,*curr = head, *nxt = head->next;
        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt!=NULL)nxt = nxt->next;
        }
        return prev;
    }
class Solution
{
    public:
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if (node1 == NULL) return reverseLL(node2);
        if (node2 == NULL) return reverseLL(node1);

        Node *head,*tail;
        
        if(node1->data<node2->data){
            head=node1;
            tail = head;
            node1= node1->next;
        }
        else{
            head = node2;
            tail = head;
            node2= node2->next;
        }
        while(node1!=NULL && node2!=NULL){
             if(node1->data<node2->data){
                Node*temp = node1;
                tail->next = temp;
                tail=temp;
                node1=node1->next;
                
             }else{
                 Node*temp = node2;
                tail->next = temp;
                tail=temp;
                node2=node2->next;
             }
             
        }
        if(node1==NULL)tail->next=node2;
        else tail->next=node1;
        
        return reverseLL(head);
        
        
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends