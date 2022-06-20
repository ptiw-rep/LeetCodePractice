class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int mxVal = releaseTimes[0];
        for( int i=1;i<releaseTimes.size();i++ ) {
            if( releaseTimes[i]-releaseTimes[i-1] > mxVal || (releaseTimes[i]-releaseTimes[i-1] == mxVal && keysPressed[i]>ans)  ) {
                mxVal= releaseTimes[i]-releaseTimes[i-1];
                ans = keysPressed[i];
            }
        }
        return ans;
    }
};