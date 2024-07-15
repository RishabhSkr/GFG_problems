//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
       if(9*d<s)return "-1";
        string num(d,'0');
        s--; //reserver 1
        // logic is to fill from LSB to MSB(max numbers)
       for(int i =d-1;i>0;--i){
           if(s>9){
               num[i]='9';
               s-=9;
           }else{
               num[i]='0'+s;
               s=0;
           }
       }
        num[0]=(s + 1) + '0'; // because we reserved 1 earlier;
       return num;
       
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends