class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v]=find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            size.push_back(i);
        }
        for(int i=0;i<edges.size();i++)
        {
            union_sets(edges[i][0],edges[i][1]);
        }
        map<int,int> unique;
        for(auto x: parent)
        {
            unique[find_set(x)]=1;
        }
        return unique.size();

    }
};