//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   To solve the problem of finding the longest alternating sequence in an array, we need to track two things: the length of the sequence when it ends in an increasing fashion and the length of the sequence when it ends in a decreasing fashion. 
//Here's how you can implement this in Java:
// Iterate through the array.
// Use two variables to keep track of the lengths of the alternating sequences:
//one for sequences ending with an increase and another for sequences ending with a decrease.
// Update these variables as you find alternating patterns.

    int alternatingMaxLength(vector<int>& arr) {
       int inc = 1;
        int dec = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] > arr[i-1])
                inc = dec +1;
            else if(arr[i] < arr[i-1])
                dec = inc + 1;
        }
        return max(inc,dec);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends