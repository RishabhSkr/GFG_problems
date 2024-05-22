//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
vector<string>res;
void help(string op,int n,int one,int zero){
    if(one+zero==n){
        res.push_back(op);
        return;
    }
    if(one<n)help(op+"1",n,one+1,zero);
    if(one>zero)help(op+"0",n,one,zero+1);
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    help("1",n,1,0);
	    return res;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends