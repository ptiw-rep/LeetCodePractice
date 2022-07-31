class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int len = 1;
        while( !q.empty() ) {
            int k = q.size();
            for( int i=0;i<k;i++ ) {
                string curr = q.front();
                q.pop();
                if( curr==endWord ) {
                    return len;
                }
                s.erase(curr);
                // generate all 1 difference words 
                for( int i =0;i<curr.size();i++) {
                    char org = curr[i];
                    for(int j=0;j<26;j++) {
                        curr[i] = 'a' + j;
                        if( s.find(curr)!=s.end() ){
                            q.push(curr);
                        }
                    }
                    curr[i] = org;
                }
            }
            len++;
        }
        return 0;
    }
};