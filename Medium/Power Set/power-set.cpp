//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>res;
	void solve(int ind, string s , string temp){
	    if(ind == s.length()){
	        if(temp=="")return ;
	        res.push_back(temp);
	        return;    
	    }
	    
	    
	    solve(ind+1,s,temp+s[ind]); 
	    solve(ind+1,s,temp); 
	    temp="";
	    
	    
	}
	vector<string> AllPossibleStrings(string s){
		    // Code here
		solve(0,s,"");
	    sort(res.begin(),res.end());
	    return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends