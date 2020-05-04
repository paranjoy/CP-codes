/*
Given a map of Hackerland and the transmission range, determine the minimum number of transmitters so that every house 
is within range of at least one transmitter. Each transmitter must be installed on top of an existing house.

For example, assume houses are located at [1,2,3,5,9]  and the transmission range k = 1.  
antennae at houses 2 and 5 and 9 would provide complete coverage.  
Ranges of coverage,[1,2,3] are ,[5] , and [9].

Function Description
Complete the hackerlandRadioTransmitters function in the editor below. It must return an integer that denotes 
the minimum number of transmitters to install.

hackerlandRadioTransmitters has the following parameter(s):

x: integer array that denotes the locations of houses
k: an integer that denotes the effective range of a transmitter

Constraints
1 <= n,k <= 10^5
1 <= x[i] <= 10^5
There may be more than one house at the same location

Sample Input 0
5 1
1 2 3 4 5
Sample Output 0
2

Sample Input 1
8 2
7 2 4 6 5 9 12 11 
Sample Output 1
3
*/
// Complete the hackerlandRadioTransmitters function below.
int hackerlandRadioTransmitters(vector<int> x, int k) {

    sort(x.begin(), x.end());

    int c = 0; 
    int i = 0;

    while(i < x.size()){
        c++;

        int tr = x[i] + k;
        while( i < x.size() && x[i] <= tr)
            i++;
        
        i = i - 1;

        tr = x[i] + k;

        while(i < x.size() && x[i] <= tr)
            i++;
    }
    return c;
}
