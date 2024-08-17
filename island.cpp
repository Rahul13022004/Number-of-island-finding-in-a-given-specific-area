class Solution {
public:
//Time Complexity: O(m * n)
// Space Complexity: O(m * n)
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0'){//it is a water body
                    continue;
                }
                //New unvisited land piece found
                result++;
                grid[i][j]='0';//Mark it visited
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                     auto curr=q.front();
                     q.pop();
                     int currrow=curr.first;
                     int currcol=curr.second;
                     //check up
                     if(currrow-1>=0 and grid[currrow-1][currcol]=='1'){
                         q.push({currrow-1,currcol});
                         grid[currrow-1][currcol]='0';
                     }
                     //check down
                     if(currrow+1<m and grid[currrow+1][currcol]=='1'){
                         q.push({currrow+1,currcol});
                         grid[currrow+1][currcol]='0';
                     }
                     //check right
                     if(currcol+1<n and grid[currrow][currcol+1]=='1'){
                         q.push({currrow,currcol+1});
                         grid[currrow][currcol+1]='0';
                     }
                     //check left
                      if(currcol-1>=0 and grid[currrow][currcol-1]=='1'){
                         q.push({currrow,currcol-1});
                         grid[currrow][currcol-1]='0';
                     }

                }
            }
        }
        return result;
    }
};