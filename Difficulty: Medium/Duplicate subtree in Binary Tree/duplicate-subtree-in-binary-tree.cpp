//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
  
    int checkNodeType(Node * root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }else{
            return 2;
        }
    }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         // code here
         set<string> s;
         int ans=0;
         
         checkForDuplicates(root, s, ans);
         
         return ans;
    }
    
    void checkForDuplicates(Node *root, set<string> & s1, int & ans)
    {
        if(root==NULL){
            return;
        }
        
        int p1, p2;
        string s="";
        
        p1=checkNodeType(root->left);
        p2=checkNodeType(root->right);
        
        if(p1==0 && p2==0){
            ;
        }else if(p1==0 && p2==1){
            s=root->data;
            s+='$';
            s+=root->right->data;
            
            if(s1.find(s)!=s1.end()){
                ans=1;
            }
            s1.insert(s);
        }else if(p1==1 && p2==0){
            s=root->data;
            s+=root->left->data;
            s+='$';
            
            if(s1.find(s)!=s1.end()){
                ans=1;
            }
            s1.insert(s);
        }else if(p1==1 && p2==1){
            s=root->data;
            s+=root->left->data;
            s+=root->right->data;
            
            if(s1.find(s)!=s1.end()){
                ans=1;
            }
            s1.insert(s);
        }else{
            if(p1==2){
                checkForDuplicates(root->left, s1, ans);
            }
            if(p2==2){
                checkForDuplicates(root->right, s1, ans);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends