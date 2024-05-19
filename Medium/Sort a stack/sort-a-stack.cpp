//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void solve(stack<int>&st,int k){
    if(st.empty() || st.top()<=k){
        st.push(k);
        return ;
    }
    int temp = st.top();
    st.pop();
    solve(st,k);
    st.push(temp);
}
void rec(stack<int>&st){
    if(st.empty())return;
    int k = st.top();
    st.pop();
    rec(st);
    solve(st,k);
}
void SortedStack :: sort()
{
   rec(s);
   
}