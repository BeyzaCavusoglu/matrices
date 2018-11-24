# matrices
Practice on matrices (2 dimensional arrays/vectors)


//The aim is practice on matrices (two dimensional arrays/vectors) and file input/output. I implemented a program which detects a combination of matrices which add up to a single matrix, given a pool of matrices. The details will be explained in the following sections below.

**************************************
Input 

The program prompts for the input file name. Then, it reads the file name from the standard input. The first line of the input file contains a single integer stating the number of matrices (N) in the given file. The second line of the input file contains two integers stating the number of rows and columns of all the matrices in the file.  Next, the rest of the file contains the actual matrices. Between two matrices there will be an empty line. A sample input file can be as follows:

2
3 3

2 3 4
1 5 9
2 7 9

3 8 2
4 1 3
7 2 9

Assumed that the file will only contain integers. Also assumed that the given file will contain N matrices all the time. However, the sizes of all the matrices in the input file should be controlled. In other words, check if the given row and column numbers match with the given matrices. 

After reading the file, I stored all the matrices in a vector. Since the definition of a matrix is done by vector<vector<int>>, the vector containing all the matrices can be defined as vector<vector<vector<int>>>. 
  
***********************************************
Program Flow

The task is to find k matrices in the input file such that when they are added up the result is also a matrix in the input file. The number k will be a standard input. Assume that N < 10 and k < 5 will always be satisfied. With these in mind, the flow of the program will be as following:

Prompt for the input file name and perform an input check. If an invalid file name is entered, ask again until a correct file name is entered.
Read the value of N from the file. Store all the matrices in the given input file into a vector. If the size of any matrix does not satisfy the given row and column numbers, print an error message and end the execution.
Prompt for k.
Check if any k matrices add up to a single matrix in the file. (Hint: check all  (N¦k) combinations of matrices to find the result.)
When a combination that gives a desired result is found, print an output.
If a desired result is not found, print an appropriate error message.
  
************************************************************
Sample Outputs 

Below you can find sample outputs for my program:

input.txt

5
3 3

1 2 3
4 5 6
7 8 9

9 8 7
6 5 4
3 2 1

2 1 2
1 2 1
2 1 2

10 10 10
10 10 10
10 10 10

5 1 9
2 8 3
4 2 9

Case 1:

Please enter the input file name: in.txt
Invalid file name. Please enter again: input.txt
Enter k: 2
Matrix 3 can be written as the sum of matrices 0 1
Press any key to continue . . .

Case 2:
Please enter the input file name: input.txt
Enter k: 3
There are no valid combinations in the given input file
Press any key to continue . . .
******************************
input2.txt

3
4 4


1 2 3 4
3 2 1 3
2 3 1 5
3 2 1 3



1 1 1 1
2 2 2 2 2
3 3 3 3
4 4 4 4




9 2 3 2
2 2 4 2
7 2 3 4
2 3 2 4



Case 3:
Please enter the input file name: what.txt
Invalid file name. Please enter again: input2.txt
Invalid file.
Press any key to continue . . .



