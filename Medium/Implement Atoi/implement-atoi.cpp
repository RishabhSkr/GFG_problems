//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int i =0;
        bool isSign = false;
        long long int ans =0;
        int n = s.size()-1;
        for(int i = 0;i<s.length();++i){
            int no = s[i]-48;
            if(i==0 && s[i]=='-'){
                isSign = true;
                n=n-1;
                continue;
            }
            else if(s[i]=='-'){
                return -1;
            }
            else if(no>=0 && no<=9){
                ans+=no*pow(10,n);
                n--;
            }
            else return -1;
        }
        if(isSign)return (-1)*ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends