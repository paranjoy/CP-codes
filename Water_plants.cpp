/*
A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions for attaching water sprinklers at every partition. 
A sprinkler with range x at partition i can water all partitions from i-x to i+x.

Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power==-1 indicates no sprinkler attached), 
return the minimum number of sprinklers that need to be turned on to water the complete gallery.

If there is no possible way to water the full length using the given sprinklers, print -1.

Input:
First line of input holds the number of test cases t, then t test cases follow. In each test case, first line holds the integer n. 
Second line of test case holds the n space separated integers representing the array gallery[ ].

Output:
Output should hold the minimum number of sprinklers that need to be turned on to water the complete length.

Your task:
Your task is to complete the function min_sprinklers() which takes the array gallery[ ] and the integer n as input parameters and returns the value to be printed.

Constraints:
T <= 500
n <= 1000
gallery[i] <= 50

Example:
Input:
3
6
-1 2 2 -1 0 0
9
2 3 4 -1 2 0 0 -1 0
9
2 3 4 -1 0 0 0 0 0
Output:
2
-1
3
Explanation:
Testcase 1:
Sprinklers at index 2 and 5 can water the full gallery, span of sprinkler at index 2 = [0,4] and span of sprinkler at index 5 = [5,5]
Testcase 2:
No sprinkler can throw water at index 7. Hence all plants cannot be watered.
Testcase 3:
Sprinkler at indexes 2, 7 and 8 together can water all plants.
*/
/*
Make a list/vector of all sprinklers and sort them wrt the starting point of their span.
Now set the target at the start of the gallery and select the sprinkler which covers the target and reaches the furthest possible point (end of span).
Now, the target point moves one unit ahead of the end of span of the previously selected sprinkler. 
Repeat this process of selecting sprinklers till the complete gallery is covered.
*/


//C++

int min_sprinklers(int gallery[], int n)
{
    vector<pair<int,int>> sprinklers;
    for(int i=0; i<n; i++)
        if(gallery[i] > -1)
            sprinklers.push_back( pair<int,int> ( i-gallery[i], i+gallery[i] ) );
    
    sort(sprinklers.begin(), sprinklers.end());
    
    int target=0, sprinklers_on=0, i=0;
    while(target<n)
    {
        if(i==sprinklers.size() || sprinklers[i].first>target)
            return -1;
        
        int max_range = sprinklers[i].second;
        while( i+1<sprinklers.size() && sprinklers[i+1].first<=target )
        {
            i++;
            max_range = max( max_range,  sprinklers[i].second );
        }
        if(max_range<target)
            return -1;
        
        sprinklers_on++;
        target = max_range +1;
        i++;
    }
    
    return sprinklers_on;
}
