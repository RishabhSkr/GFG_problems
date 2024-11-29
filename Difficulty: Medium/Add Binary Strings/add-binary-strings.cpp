//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public: 
  // reverse the string 
  //  iterate over two string if 1+1 gerate  carry 1 0+1 +carry
    string addBinary(string& s1, string& s2) {
        // your code here
       string ans = "";
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;
        
        // No need to reverse strings, process from right to left
        while(i >= 0 || j >= 0 || carry) {
            // Get digits or use 0 if string exhausted
            int sum = carry;
            if(i >= 0) sum += s1[i] - '0';
            if(j >= 0) sum += s2[j] - '0';
            
            // Add digit to result
            ans = char(sum % 2 + '0') + ans;
            carry = sum / 2;
            
            i--;
            j--;
        }
    
        string res  = "";
        bool leadingZeros =true;
        for(int i =0;i<ans.size();++i){
            if(ans[i]=='0' && leadingZeros)continue;
            
            leadingZeros= false;
            res+=ans[i];
        }
        if(res=="")res+='0';
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends