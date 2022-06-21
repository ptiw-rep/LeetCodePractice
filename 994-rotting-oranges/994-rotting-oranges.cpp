class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if( grid.size() == 0 )
            return 0;
        // m*n grid
        queue<pair<int,int>> q;
        int m = grid.size(),n = grid[0].size(), total= 0 , count = 0, i, j, k, time = 0 ;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if( grid[i][j]!=0 )
                    total++;
                if( grid[i][j]==2 )
                    q.push({i,j});   
            }
        }
        int dx[4] = { 1,0,-1,0 };
        int dy[4] = { 0,1,0,-1 };
        
        while( !q.empty() )
        {   
            k = q.size();
            count+=k;
            while( k-- ) {
                int x = q.front().first, y =q.front().second, nx, ny;
                q.pop();
                for( i = 0 ; i < 4 ; i++ )
                {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if( nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1 )
                        continue;
                    grid[nx][ny] = 2 ;
                    q.push( {nx,ny} );
                }  
            }
         if( !q.empty() )
             time++;
        }
        return count==total?time:-1;   
    }
};