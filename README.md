# matrices
Practice on matrices (2 dimensional arrays/vectors)


//The aim is practice on matrices (two dimensional arrays/vectors) and file input/output. I implemented a program which detects a combination of matrices which add up to a single matrix, given a pool of matrices. The details will be explained in the following sections below.

**************************************
Input added as a word file.

******************************************
Program Flow

The task is to find k matrices in the input file such that when they are added up the result is also a matrix in the input file. The number k will be a standard input. Assume that N < 10 and k < 5 will always be satisfied. With these in mind, the flow of the program will be as following:

Prompt for the input file name and perform an input check. If an invalid file name is entered, ask again until a correct file name is entered.
Read the value of N from the file. Store all the matrices in the given input file into a vector. If the size of any matrix does not satisfy the given row and column numbers, print an error message and end the execution.
Prompt for k.
Check if any k matrices add up to a single matrix in the file. (Hint: check all  (N¦k) combinations of matrices to find the result.)
When a combination that gives a desired result is found, print an output.
If a desired result is not found, print an appropriate error message.
  
************************************************************
Sample Outputs added as a word file.
