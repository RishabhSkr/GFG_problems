//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string add(string &s1,string &s2){
        string ans = "";
        int carry = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        int i = n1-1,j = n2-1;
        while(i>=0 && j>=0){
            
            int d1=s1[i]-'0';
            int d2 = s2[j]-'0';
            int sum = d1+d2+ carry;
           
            ans+=to_string(sum%10);
            carry = sum/10;
            i--,j--;
            
        }
        
        while(i>=0){
            int sum = s1[i]-'0'+carry ;
            ans+=to_string(sum%10);
            carry = sum/10;
            i--;
        }
    
        while(j>=0){
            int sum = s2[j]-'0' + carry;
            ans+=to_string(sum%10);
            carry = sum/10;
            j--;
        }
         if(carry) ans += to_string(carry);
         reverse(ans.begin(),ans.end());
         return ans;
    }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        
        string min1 = "",min2 = "";
        int n = arr.size();
        
        for(int i =0;i<n;i++){
      
            if(arr[i] == 0) continue;
            if(i%2){
                min2+= to_string(arr[i]);
            }else min1+=to_string(arr[i]);
    
        }
       
        return add(min1,min2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends