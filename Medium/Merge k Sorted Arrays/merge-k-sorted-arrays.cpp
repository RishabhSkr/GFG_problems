//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
        vector<int> partition(vector<vector<int>>& arrays, int start, int end) {
        if (start == end) 
            return arrays[start];
            int mid = start + (end - start) / 2;
            vector<int> left = partition(arrays, start, mid);
            vector<int> right = partition(arrays, mid + 1, end);
            return merge(left, right);
        
    }

    vector<int> merge(vector<int>& left, vector<int>& right) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result.push_back(left[i]);
                i++;
            } else {
                result.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size()) {
            result.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            result.push_back(right[j]);
            j++;
        }
        return result;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        if (arr.empty()) return {};
        return partition(arr, 0, arr.size() - 1);
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends