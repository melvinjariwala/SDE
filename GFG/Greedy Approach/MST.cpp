//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	vector<vector<int>> edgelist;
	int find(int i, int parent[]){
	    if(parent[i]==-1){
	        return i;
	    }
	    return parent[i]=find(parent[i],parent);
	}
	int unite(int x, int y, int parent[], int rank[]){
	    int s1=find(x,parent);
	    int s2=find(y,parent);
	    if(s1!=s2){
	        if(rank[s1]<rank[s2]){
	            parent[s1]=s2;
	            rank[s2]+=rank[s1];
	        }
	        else{
	            parent[s2]=s1;
	            rank[s1]+=rank[s2];
	        }
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int res=0;
        int parent[V];
        int rank[V];
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
                edgelist.push_back({itr[1],i,itr[0]});  
            }
        }
        
        for(int i=0;i<V;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        sort(edgelist.begin(),edgelist.end());
        
        for(auto edge:edgelist){
            if(find(edge[1],parent)!=find(edge[2],parent)){
                unite(edge[1],edge[2],parent,rank);
                res+=edge[0];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends