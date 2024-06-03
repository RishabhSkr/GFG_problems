//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void maxHeapify(vector<int>&arr,int ind,int size){
        // int parent = ind;
        int leftChild = 2*ind+1;
        int rightChild = 2*ind+2;
        int largest = ind;
        if(leftChild<size && arr[leftChild]>arr[largest])largest = leftChild;
        if(rightChild<size && arr[rightChild]>arr[largest])largest = rightChild;
        if(largest!=ind){
            swap(arr[largest],arr[ind]);
            maxHeapify(arr,largest,size);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i =N/2-1;i>=0;--i){
            maxHeapify(arr,i,N);
        }
           
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends