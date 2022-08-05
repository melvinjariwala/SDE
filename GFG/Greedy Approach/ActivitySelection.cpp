//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        int count = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mpq;
		for(int i=0;i<start.size();i++){
		    mpq.push(make_pair(end[i],start[i]));
		}
		
        auto it = mpq.top();
        int s = it.second;
        int e = it.first;
        mpq.pop();
        count++;
        
        while(!mpq.empty()){
            auto itr = mpq.top();
            mpq.pop();
            if(itr.second > e){
                s = itr.second;
                e = itr.first;
                count++;
            }
            
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends