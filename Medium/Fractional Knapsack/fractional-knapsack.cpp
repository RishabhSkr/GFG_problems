//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    // double solve(int i,int n,int w,Item arr[]){
    //     if(i==n)return 0;
    //     double take =0,notTake =0;
    //     notTake +=solve(i+1,n,w,arr);
    //     if(arr[i].weight<=w)take +=arr[i].value +solve(i+1,n,w-arr[i].weight,arr);
    //     else{
    //         take+=((arr[i].value)/(arr[i].weight))*w;
    //     }
    //     return max(notTake,take);
    // }
    
    static bool compare(Item &a,Item &b){
        float aVal = 1.0*a.value/a.weight;
        float bVal = 1.0*b.value/b.weight;
        return aVal>bVal;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans =0;
        sort(arr,arr+n,compare);
        for(int i =0;i<n;++i){
            int take = min(W,arr[i].weight);
            ans+=take*(1.0 * arr[i].value/arr[i].weight);
            W-=take;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends