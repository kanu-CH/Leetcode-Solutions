class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int k) {
        if(V==1) return 0; int mintime = 0;
        //create adjacency list
        vector<vector<int>> adj[V];
        for(int i = 0 ;i<times.size();i ++){
            vector<int> v;
            v.push_back(times[i][1]-1); //add the vertex/node
            v.push_back(times[i][2]); //add the time/edgeweight
            adj[times[i][0]-1].push_back(v);   
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        //mark every distance as infinite
        for(int i = 0; i< V;i++) dist[i] = 1e+9;
        dist[k-1] = 0;
        pq.push({0,k-1});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                //check for an existing shorter path
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i = 0 ; i< V ; i++){
            //if node is not reachable
            if(dist[i] == 1e+9) return -1;
            mintime = max(dist[i], mintime);
        }
        return mintime;
    }
};
