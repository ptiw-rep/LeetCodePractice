class Solution {
public:
    
    // The idea is simple, if we go on and simulate the process,
    // We have 2 parameters that are in consideration
    // 1 Direction
    // 2 Position
    // The key to slve the problem is that the instructions are repeated infinitely.
    // So if the direction after "Once" it has been done, is not north, we clearly know that it is stuck in a circle
    // Now, what happens if direction doesn't changes.
    // Consider "RGL" 
    // We can see that here position is not 0,0 after we processed it "Once"
    // So this is the second case that we will deal that if it is not back at the origin we know that it 
    // will go on infinitely
    bool isRobotBounded(string instructions) {
        // Direction ratios if we get G in a particular dir in order N W S E
        vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        int i =0 , x= 0, y = 0; // x and y are coords, i is for direction
        for( int idx=0;idx<instructions.length();idx++) {
            if( instructions[idx]=='G' ){
                // Move in that direction
                x += dir[i][0];
                y += dir[i][1];
            }
            else {
                // if left, we move 1 step ahead in dir
                // if right, we move 1 step backward in circular fashion, so 3 steps ahead
                i = instructions[idx]=='L' ? (i+1)%4 : (i+3)%4;
            }
        }
        return ( x==0 && y==0 || i!=0 );
    }
};