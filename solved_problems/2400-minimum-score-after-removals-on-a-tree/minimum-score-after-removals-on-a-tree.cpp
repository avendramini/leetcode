class Solution {
public:
    vector<int> score;
    vector<vector<int>> adj;
    vector<int> nums;
    vector<vector<int>> edges_list;
    vector<int> in_time, out_time;
    int timer = 0;

    void dfs(int node, int parent) {
        in_time[node] = timer++;
        score[node] = nums[node];
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            edges_list.push_back({node, nei});  // archi orientati dal padre al figlio
            dfs(nei, node);
            score[node] ^= score[nei];
        }
        out_time[node] = timer++;
    }

    bool isAncestor(int u, int v) {
        return in_time[u] < in_time[v] && out_time[v] < out_time[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        this->nums = nums;
        score.assign(n, 0);
        adj.assign(n, {});
        in_time.assign(n, 0);
        out_time.assign(n, 0);
        edges_list.clear();
        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        int total = score[0];
        int res = INT_MAX;

        for (int i = 0; i < edges_list.size(); ++i) {
            for (int j = i + 1; j < edges_list.size(); ++j) {
                int u1 = edges_list[i][1];
                int u2 = edges_list[j][1];

                int a, b, c;

                if (isAncestor(u1, u2)) {
                    // u2 is in subtree of u1
                    a = score[u2];
                    b = score[u1] ^ score[u2];
                    c = total ^ score[u1];
                } else if (isAncestor(u2, u1)) {
                    // u1 is in subtree of u2
                    a = score[u1];
                    b = score[u2] ^ score[u1];
                    c = total ^ score[u2];
                } else {
                    // disjoint subtrees
                    a = score[u1];
                    b = score[u2];
                    c = total ^ a ^ b;
                }

                int maxi = max({a, b, c});
                int mini = min({a, b, c});
                res = min(res, maxi - mini);
            }
        }

        return res;
    }
};
