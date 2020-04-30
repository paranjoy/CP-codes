/*
Louise and Richard have developed a numbers game. They pick a number and check to see if it is a power of 2. 
If it is, they divide it by 2. If not, they reduce it by the next lower number which is a power of 2. 
Whoever reduces the number to 1 wins the game. Louise always starts.

Given an initial value, determine who wins the game.

Function Description
Complete the counterGame function in the editor below. It should return the winner's name, either Richard or Louise.

counterGame has the following parameter(s):
n: an integer to initialize the game counter

Input Forma
The first line contains an integer t, the number of testcases.
Each of the next t lines contains an integer n, the initial value for the game.

Constraints
1 <= t <= 10
1 <= n <= 2^64 - 1

Output Format
For each test case, print the winner's name on a new line in the form Louise or Richard.

Sample Input 0
1
6
Sample Output 0
Richard

Sample Input 1
1
132
Sample Output 1
Louise
*/

// Complete the counterGame function below.
string counterGame(long n) {
    int flag = 1;
    long num;
    long diff;

    while(1){
        if(n == 1)
            break;

        double d = log2(n);

        double d1 = floor(d);

        if(d - d1 != 0){

            num = pow(2, d1);

            diff = n - num;

            if(diff == 1)
                break;
            else{

                n = diff;

                flag = flag * -1;
            }
        }
        else{
            num = n/2;

            if(num == 1)
                break;
            else{
                n = num;
                flag = flag * -1;
            }
        }
    }
 if(flag == 1)
    return "Louise";
return "Richard";



}

