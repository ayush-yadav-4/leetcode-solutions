// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         queue<vector<string>>q;
//          unordered_set<string>st(wordList.begin(),wordList.end());
//          vector<vector<string>>ans;
//          vector<string>usedOnlevel;
//          usedOnlevel.push_back(beginWord);
         
//          q.push({beginWord});
//            int level = 1;
//          while(!q.empty()){
//             vector<string>vec = q.front();
            
//             q.pop();

//             if(vec.size() > level){
//                 level++;
//                  for(string it : usedOnlevel){
//                  st.erase(it);
//                  }
                 
//             }
//             string word = vec.back();
//             if(word == endWord){
//              if(ans.size() == 0){
//                ans.push_back(vec);
//              }
//              else if(vec.size() <= ans[0].size()){
//                  ans.push_back(vec);
                
//              }
              
//             }
//               //string orig_str = word;
//             for(int i=0;i<word.size();i++){
//                char original = word[i];
              

//                for(char c = 'a';c<='z';c++){
//                  word[i] = c;
//                  if( st.find(word) != st.end()){
                   
//                     vec.push_back(word);
//                     usedOnlevel.push_back(word);
//                     q.push(vec);
//                     vec.pop_back();
//                  }
//                }

//                word[i] = original;

//             }
//          }
//          return ans;
//     }
// };





class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> graph;  // Reverse graph
        unordered_set<string> currentLevel{beginWord};
        unordered_set<string> nextLevel;
        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (const string& word : currentLevel)
                dict.erase(word);  // Remove visited words

            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (dict.count(temp)) {
                            graph[temp].push_back(word);  // reverse edge
                            nextLevel.insert(temp);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }

            swap(currentLevel, nextLevel);
            nextLevel.clear();
        }

        vector<vector<string>> ans;
        if (!found) return ans;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, graph, path, ans);
        return ans;
    }

    void dfs(string word, string& beginWord, unordered_map<string, vector<string>>& graph,
             vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        for (string& prev : graph[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, graph, path, res);
            path.pop_back();
        }
    }
};

