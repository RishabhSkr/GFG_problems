//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool check(string &str){
      if(str.empty() || (str.size()>1 && str[0]=='0'))return false;
      for(auto &ch : str){
          if(!isdigit(ch))return false;
      }
      int num = stoi(str);
      if(num<0 || num>255)return false;
      return true;
  }
    int isValid(string str) {
        // code here
        int n = str.size();
        // split string using dots
        int dot =0;
        vector<string>octet;
            string s = "";
        for(int i =0;i<n;++i){
            if(str[i]=='.'){
                octet.push_back(s);
            
                s="";
                dot++;
            }
            else s+=str[i];
        }
        octet.push_back(s);
        if(dot!=3)return false;
        for(string &s : octet){
            if(check(s)==false)return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends