/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true


Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 
Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

Hint #1  
If there're only 2 points, return true.

Hint #2  
Check if all other points lie on the line defined by the first 2 points.

Hint #3  
Use cross product to check collinearity.
*/

//code snippet
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() == 2)
            return true;
        
        if(coordinates[0][0] != coordinates[1][0]){
            
            double slope = (1.0*coordinates[0][1] - 1.0*coordinates[1][1])/(1.0*coordinates[0][0] - 1.0*coordinates[1][0]);
            
            for(int  i = 2; i < coordinates.size(); i++){
                double y1 = coordinates[i][1]*1.0 - 1.0*coordinates[0][1];
                double x1 = coordinates[i][0]*1.0 - 1.0*coordinates[0][0];
                
                if( y1 != slope*x1)
                    return false;
            }
            return true;
        }
        else{
            for(int  i = 2; i < coordinates.size(); i++)
                if(coordinates[0][0] != coordinates[i][0])
                    return false;
            
            return true;
        }
    }
};
