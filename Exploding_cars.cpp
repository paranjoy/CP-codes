/*
You are given an array cars[] of integers in a sequential order representing a car on a number line. For each car, its sign represent its direction
( + for the right direction and - for the left direction ) and its magnitude represents its power to explode the other car.     
All cars are moving with the same speed and if two cars hit each other than the car with more power explodes the car with less power. 
An explosion does not slow down the speed of the car and it continues to travel with the same speed. 
So if any 2 cars are moving in the same direction they do not hit each other.
Find the final state of the cars after all collisions between the cars have taken place. 

Note: There will be no car with magnitude zero and if two cars with same magnitude collide then both of them will explode.

Input:
The first line of the input contains T denoting the number of testcases. The first line of each test case contains the size of array cars[] N and
the second line of each test case contains elements of array cars[].

Output:
For each test case, on a new line, print the final state of the array cars[ ].

Your Task :
You don't have to take input. Complete the function final() that takes the parameter, N as the no. of cars, cars[] which contain power of the ith car and 
returns an array of the final state of the cars[]. 

Constraints:
1 <= T <= 100
1 <= N<= 105
-105 <= cars[i] <= 105

Example:
Sample Input-
2
3
100 10 -2
5 
3 -9 8 -8 9

Sample Output-
100 10
-9 9

Explanation-
In testcase 1, 10 and -2 cars hit each other and -2 car gets explodes by 10 .10 and 100 are in the same direction so they do not hit each other.
Similarly, in testcase 2, 8 collides with -8 and 3 collides with -9.
*/

// User function Template for C++

vector<int> final(int cars[], int n) {
    // code here
    vector<int> res;
    
    for(int i = 0; i < n; i++){;
        if(cars[i] < 0){
            int j = i - 1;
            while(j >= 0){
                if(cars[j] != INT_MIN && cars[j] < 0)
                    break;
                
                if(cars[j] != INT_MIN && cars[j] < abs(cars[i]))
                    cars[j] = INT_MIN;
                else if(cars[j] != INT_MIN && cars[j] > abs(cars[i])){
                    cars[i] = INT_MIN;
                    break;
                }
                else if(cars[j] == abs(cars[i])){
                    cars[j] = INT_MIN;
                    cars[i] = INT_MIN;
                    break;
                }
                j--;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        if(cars[i] != INT_MIN)
            res.push_back(cars[i]);
    
    return res;
}
