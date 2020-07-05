/*
Ted is a pro coder , but today he is very busy in doing college assignments . He needs your help to complete a task . 
The task is as follow:-
Given two positive integers A and B denoting numerator and denomenator of a fraction . 
You need to count the length of repeated pattern of digits in decimal part of A/B .

Input:
First line of input contains an integer T denoting number of test cases . For each test case , there will be two space seperated positive integers A and B .

Output:
For each test case print the length of repeated pattern of digits in decimal part of A/B.

Task:
This is a functional problem , you don't need to take input just complete the function findCount() which accepts two integers A and B as parameters 
and return the length of repeated pattern of digits in decimal part of A/B.

Constraints:
1 <= T <= 100
1 <= A , B <= 10000

Example:
Input:
3
1 2
22 7
8 4
Output:
0
6
0

Explanation:
Testcase1: 1/2 = 0.5 since there is no repetition in decimal part of 1/2 therefore ans is 0.
Testcase2: 22/7 = 3.142857142857142857.... length of repeating pattern in decimal part is 6 .
Testcase3: 8/4 = 2 , since 4 completly divides 8 there is no decimal part.
*/

int findRepeat(int p , int q){

    // checking if p is perfectly divisible by q
	  if(p % q == 0)
		    return 0;
		
	  // performing basic division method (which we do manually ) and mapping remainders with their position	
	  map<int,int>mapp;
	  int initial_rem , i , rem , curr_dividend, temp , newRem = -1;
	  initial_rem = p % q;
	  curr_dividend = p % q;
	  mapp[initial_rem] = 0;
	  int z = 0;
	  
    while(7){
	    i=0;
	    
      while(curr_dividend < q){
			    if(i == 0)
					  curr_dividend *= 10;
			    else{
				    curr_dividend *= 10;
					  z++;
				  }
			    
          i++;		
		  }
	    
      temp = curr_dividend / q;
	    newRem = curr_dividend % q;
	    z++;
	    
      //checking if current remainder is already present in map if not present then adding it into map 
	    if(mapp.find(newRem) == mapp.end())
			    mapp[newRem] = z;
	    // if remainder is already present then returning the length (current position - initial position)	
      else
			    return z-mapp[newRem] ;
	    
      curr_dividend = newRem;
	    
      // case when remainder is zero
	    if(newRem == 0)
			    return 0;
	}

}
