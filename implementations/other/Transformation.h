// Description: Transformations for common discrete grid traversals
// Pasteable: FULL

#define DIRECTION dir_four

const vector<vector<int>> dir_four = {{-1,0}, {0,1}, {1,0}, {0,-1}}; 
const vector<vector<int>> dir_eight = {{-1,0}, {-1, 1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1, -1}}; 
const vector<vector<int>> dir_knight = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {-2,1}, {2,-1}, {-2,-1}}; 
const vector<vector<int>> dir_bishop = {{-1,-1}, {1,1}, {1,-1}, {-1,1}}; 


//for (int dir = 0; dir < (int) DIRECTION.size(); dir++) {
//    int ty = y + DIRECTION[dir][0];
//    int tx = x + DIRECTION[dir][1];
//
//    if (ty >= 0 && tx >= 0 && ty < n && tx < m) {
//        
//    }
//} 