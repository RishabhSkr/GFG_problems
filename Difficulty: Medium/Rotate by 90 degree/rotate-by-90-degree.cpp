//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n = mat.size();
    for(int i = 0 ;i<n;++i){
        for(int j = i ;j<n ;++j){
            swap(mat[i][j],mat[j][i]);
        }
    }
    
    // reverse
    
       int low = 0, high = n-1;
       while(low<high){
            for(int i = 0 ;i<n;++i){
                swap(mat[i][low],mat[i][high]);
            }
            low++,high--;
       }
     
    
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends