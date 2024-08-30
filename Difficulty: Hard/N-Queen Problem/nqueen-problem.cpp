//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
vector<vector<int>> res;
bool isSafe(int i ,int j  ,int n ,vector<string>&board){
    int x = i,y = j ;
    // left diag
    while(x>=0 && y >=0){
        if(board[x][y]=='Q')return false;
        x--,y--;
    }
    x = i,y =j;
    // upward
    while(x>=0){
        if(board[x][y]=='Q')return false;
        x--;
    }
    x = i;
     while(x>=0 && y <n){
        if(board[x][y]=='Q')return false;
        x--,y++;
    }
    return true;
}
void solve(vector<string>&board,int i,int n,vector<int>&op){
    if(i==n){
        for(int i =0;i<n;++i){
            for(int j =0;j<n;++j){
                if(board[i][j]=='Q')op.push_back(j+1);
            }
        }
        res.push_back(op);
        op.clear();
        return;
    }

    // put each in every cell
    for(int j =0 ;j<n;++j){
        if(isSafe(i,j,n,board)){ // each queen before putting it is safe or not.
            board[i][j] = 'Q';
            solve(board,i+1,n,op);
            board[i][j]= '.';
        }
    }

}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<string>board(n,string(n,'.'));
        vector<int>op;
        solve(board,0,n,op);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends