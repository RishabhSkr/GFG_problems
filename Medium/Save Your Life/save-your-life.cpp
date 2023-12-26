//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
          int maxi =INT_MIN,cur=0;
          string ans ="",str="";
          for(int i=0;i<w.size();++i){
              int num = 0;
                for(int j =0;j<n;++j){
                    if(w[i]==x[j]){
                        num=b[j];
                        break;
                    }    
                       
                }
                if(num!=0){
                    cur+=num;
                    
                }else{
                    cur+=(int)w[i];
                }
                str +=w[i];
                if(maxi<cur){
                    maxi = cur;
                    ans = str;
                }
                if(cur<0){
                    cur=0;
                    str="";
                }
                
          }
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends