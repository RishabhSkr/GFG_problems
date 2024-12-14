//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid =s+(e-s)/2;
            if(arr[mid]==key)return mid;
            
            //either we are left part 
           if(arr[s]<=arr[mid]){
               if(arr[s]<= key && key<=arr[mid])e= mid-1;
               else s=mid+1;
           }
           // right part
           else{
               if(key>= arr[mid] && key<=arr[e])s= mid+1;
               else e=mid-1;
           }
            
        }
        return -1;
    }
    //5 6 1 2 3 4
//    0 1 2 3 4 5 key =4
// s = 3 mid = 4 e= 5
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends