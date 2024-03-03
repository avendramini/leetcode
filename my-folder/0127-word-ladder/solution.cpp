class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> visited;
        for (auto w : wordList) {
            visited.insert(w);
        }
        if (!visited.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                string popped = q.front();
                q.pop();
                if (popped == endWord)
                    return res;
                visited.erase(popped);
                for (int i = 0; i < popped.size(); i++) {
                    char c = popped[i];
                    for (int j = 0; j < 26; j++) {
                        char replace = j + 'a';
                        popped[i] = replace;
                        if (visited.count(popped)) {
                            q.push(popped);
                            visited.erase(popped);
                        }
                        popped[i] = c;
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
