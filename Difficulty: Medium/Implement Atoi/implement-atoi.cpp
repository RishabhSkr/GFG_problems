//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        // Alogo
            //case 1. check - if yes no is neg else no is +ve
            // case 2 : 0 occ
                // 2.1 if leading zero discard
                // 2.2 in between or end  consider
                // 2.3 
            // case 3 : maxi or min case overflow
            int n = strlen(s);
            long long num = 0;
            
            int i = 0;
            // handle spaces
            while(i<n && s[i]==' '){
                i++;
            }
            
            // handlesign
            int sign = 1;
            if(s[i]=='-' ){
                sign = -1;
                i++;
            }
            else if(s[i]=='+'){
                sign = 1;
                i++;
            }
           
            
            // process digits
            
            while(i<n && s[i]>='0' && s[i]<='9'){
                // Check for overflow before adding new digit
               num = num * 10 + (s[i] - '0');
               if(num*sign>INT_MAX)return INT_MAX;
               if(num*sign<INT_MIN)return INT_MIN;
                i++;
            }
            
            return (int)sign * num;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends