class Solution {
public:
    vector<vector<int> >adj;
    vector<bool> vis;
    vector<int> ris;
    void dfs(int pos)
    {
        vis[pos]=true;
        for(auto x: adj[pos])
        {
            if(!vis[x])
                dfs(x);
        }
        ris.push_back(pos);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vis.assign(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        reverse(ris.begin(),ris.end());
        vis.assign(numCourses,false);
        for(auto x: ris)
        {
            vis[x]=true;
            for(auto j: adj[x])
            {
                if(vis[j])
                    return false;
            }
        }
        return true;
    }
};
