class Solution {
public: 
    vector<vector<int>> adj;
    vector<int> ris;
    vector<bool> vis;
    void dfs(int pos,int p)
    {
        vis[pos]=true;
        for(auto x: adj[pos])
        {
            if(!vis[x])
                dfs(x,pos);
        }
        ris.push_back(pos);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        vis.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
                dfs(i,-1);
        }
        reverse(ris.begin(),ris.end());
        vis.assign(numCourses,false);
        for(int i=0;i<ris.size();i++)
        {
            vis[ris[i]]=true;
            for(auto x: adj[ris[i]])
            {
                if(vis[x])
                    return {};
            }
        }
        return ris;
    }
};
