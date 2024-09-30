//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

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

            // Create the left child for the current node
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
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to flatten the binary tree into a linked list using the right pointers
    Node* flatten(Node* root) {
        if (root == NULL) return NULL;
        Node* curr = root;

        // Traverse the tree
        while (curr != NULL) {
            if (curr->left != NULL) {
                // Find the predecessor in the left subtree (rightmost node of left subtree)
                Node* pred = curr->left;
                while (pred->right != NULL) pred = pred->right;

                // Connect the predecessor's right pointer to the current node's right child
                pred->right = curr->right;

                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = NULL; // Set left to NULL after moving it
            }
            // Move to the next node (which is now in the right pointer)
            curr = curr->right;
        }
        return root;
    }

    // Function to merge two sorted linked lists (flattened trees)
    vector<int> merge(Node* root1, Node* root2) {
        // Flatten both trees
        root1 = flatten(root1);
        root2 = flatten(root2);

        // If one list is empty, return the other as a vector
        if (root1 == NULL && root2 == NULL) return {};
        if (root1 == NULL) root1 = root2;
        if (root2 == NULL) root2 = root1;

        // Merge two sorted linked lists
        Node* ans;
        if (root1->data < root2->data) {
            ans = root1;
            root1 = root1->right;
        } else {
            ans = root2;
            root2 = root2->right;
        }
        Node* tail = ans;

        // Merge logic
        while (root1 != NULL && root2 != NULL) {
            if (root1->data < root2->data) {
                tail->right = root1;
                root1 = root1->right;
            } else {
                tail->right = root2;
                root2 = root2->right;
            }
            tail = tail->right;
        }

        // Append remaining nodes
        if (root1 != NULL) tail->right = root1;
        if (root2 != NULL) tail->right = root2;

        // Collect the merged list into a vector
        vector<int> res;
        while (ans != NULL) {
            res.push_back(ans->data);
            ans = ans->right;
        }
        sort(begin(res),end(res));
        return res;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends