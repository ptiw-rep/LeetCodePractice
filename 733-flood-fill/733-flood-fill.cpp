class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool isValid(int i, int j , int m, int n) {
        if( i<0 || j<0 || i>=m || j>=n )
            return false;
        else
            return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(), n=image[0].size();
        int srcCol = image[sr][sc];
        if( srcCol == color )
            return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while( !q.empty() ) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            image[x][y] = color;
            for(int d=0;d<4;d++) {
                int i= x+dx[d], j = y+dy[d];
                if( isValid(i,j,m,n) && image[i][j]==srcCol ) {
                    q.push({i,j});
                }
            }
        }
        return image;
    }
};