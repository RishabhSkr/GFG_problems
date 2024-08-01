//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        int top = 0,left = 0,bottom =m-1,right = n-1;
        vector<int>ans;
        while(top<=bottom && left <=right){
            for(int i = top;i<=right;++i){
                ans.push_back(mat[top][i]);
            }
            top++;
          
            for(int i =top ;i<=bottom;++i){
                ans.push_back(mat[i][right]);
            }
            right--;
        
            if(top<=bottom){
                for(int i= right;i>=left;--i){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
             if(left<=right){
                for(int i= bottom;i>=top;--i){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends