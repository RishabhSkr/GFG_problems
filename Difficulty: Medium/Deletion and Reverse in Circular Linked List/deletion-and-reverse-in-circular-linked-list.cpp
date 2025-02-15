//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (head == NULL || head->next == head) return head;
        Node *prev = NULL, *curr = head, *nxt = NULL;
        Node *first = head;  // Keep track of the first node (head)
        
        do {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        } while (curr != head);
    
        // After the loop, fix the original head's (first node) next pointer
        first->next = prev;
    
        return prev;  // 'prev' becomes the new head after reversal
    }


   Node* deleteNode(Node* head, int key) {
    if (head == NULL) return NULL;

    Node *curr = head;

    // Case 1: Deleting the head node
    if (head->data == key) {
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        // If there's only one node
        if (head->next == head) {
            delete head;
            return NULL;
        }

        Node *temp = head;
        tail->next = head->next;  // Make the last node point to the new head
        head = head->next;
        delete temp;
        return head;
    }

    // Case 2: Deleting non-head nodes
    Node *prev = NULL;
    do {
        if (curr->data == key) {
            prev->next = curr->next;  // Bypass the node to delete it
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head;  // Return the head if no deletion occurs
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends