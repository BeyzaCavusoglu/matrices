#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

bool checksum(vector<vector<int>> mat1,vector<vector<int>> mat2, int rows, int cols){  //checks if the sum is in the given input file
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			if(mat1[i][j]!=mat2[i][j]){
				return false;}			
		}
	}
	return true;
}
bool inputCheck(ifstream &input0)  //checks the input file if the rowsize and colsize are suitable
{
	string line;
	getline(input0, line);
	int NumberofMatrices = stoi(line); // Converting string to integer directly, since there is only 1 number.
	getline(input0, line);
	int rowsize, colsize;
	istringstream iss(line);
	iss >> rowsize >> colsize;	
	getline(input0,line);  //first blank line after rowsize
	int RowCount=0;
	int ColCount=0;
	while ( getline(input0,line) )
	{
		if (line.length() !=0) // if the line is not empty
		{
			RowCount++;		  //count rows for checking the row size is as wished
			istringstream iss(line);
			int value = 0;
			vector<int> check;
			while( iss >> value )
			{
				check.push_back(value);				
			}
			if(colsize!=check.size())    //checks if column size is as wished
			{				
				return false;
			}
		}
		else
			RowCount = 0;      //if line is empty, dont increase number of lines
		if(RowCount>rowsize)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ifstream input0;
	string filename;
	cout<<"Please enter the input file name: ";
	cin>>filename;                  //taking program's file name.
	input0.open(filename.c_str());     //opening the file		
	while(input0.fail())    //if the file can not open the file
	{			
		cout<<"Invalid file name. Please enter again: ";
		input0.clear();		
		cin>>filename;     //taking program's file name.
		input0.open(filename.c_str());  //opening the file
	}	
	if(!inputCheck(input0))    //checks if the rowsize and colsize are suitable
	{
		cout <<"Invalid file."<<endl;
		return 0;
	}
	input0.clear();                  
	input0.seekg(0, ios::beg);	   //for returning to the beginning of file
	string line;
	getline(input0, line);
	int NumberofMatrices = stoi(line); // Converting string to integer directly, since there is only 1 number.
	getline(input0, line);
	int rowsize, colsize;
	istringstream iss(line);
	iss >> rowsize >> colsize;	
	getline(input0,line);     //first blank line after rowsize
	vector<vector<vector<int>>> bigStuff;
	vector<vector<int>> stuff;     //define vector of vector for a matrix 
	for(int n=0; n<NumberofMatrices; n++) 
	{
		for(int i=0; i<rowsize; i++)   //filling the inner vector then inserting it into the outer vector 
		{
			vector<int> temp;
			getline(input0,line);	  //read input file line by line
			if (line.length()==0)        //if there is an empty line
			{
				getline(input0,line);   //skip it							
			}
			istringstream iss2(line);
			for(int j=0; j<colsize; j++)
			{		
				int value; 
				iss2>>value;                //read the taken line one by one 
				temp.push_back(value);		 //and store the chars in temp vector			
			}
			stuff.push_back(temp);      //create the matrix vector which takes all matrices from input file
			temp.clear();	
		}		
		bigStuff.push_back(stuff);
		stuff.clear();
	}
	int k;
	cout<<"Enter k: ";    //asking the k number for making calculations
	cin>>k;
	vector<vector<int>> sum (rowsize, vector<int> (colsize,0));  //vector for sum of matrices
	bool search;
	search=false;	
	if(k==2){           //for k=2, checks all the sum combinations
		for(int i=0; i<NumberofMatrices-1;i++){
			for(int j=i+1; j<NumberofMatrices; j++){
				for(int a = 0; a < rowsize; a++){
					for(int b = 0; b< colsize; b++){
						sum[a][b] = bigStuff[i][a][b] + bigStuff[j][a][b];}}   //finding all different sum combinations
				for(int w=0; w<NumberofMatrices; w++){
					if(checksum(bigStuff[w], sum, rowsize, colsize)){    //if there is valid combination
						search=1;	
						cout<<"Matrix "<< w << " can be written as the sum of matrices "<< i << " " << j << endl;}}}}}
	if(k==3){		//for k=3, checks all the sum combinations
		for(int i=0; i<NumberofMatrices-2; i++){
			for(int j=i+1; j<NumberofMatrices-1; j++){
				for(int m=i+2; m<NumberofMatrices; m++){
					for(int a = 0; a < rowsize; a++){
						for(int b = 0;  b< colsize; b++){
							sum[a][b] = bigStuff[i][a][b] + bigStuff[j][a][b] + bigStuff[m][a][b];}}   //finding all different sum combinations
					for(int p=0; p<NumberofMatrices; p++){						
						if(checksum(bigStuff[p], sum, rowsize, colsize)){
							search=1;	
							cout<<"Matrix "<< p << " can be written as the sum of matrices "<< i << " " << j << " " << m << endl;}}}}}}
	if(k==4){     //for k=4, checks all the sum combinations
		for(int i=0; i<NumberofMatrices-3; i++){
			for(int j=i+1; j<NumberofMatrices-2; j++){
				for(int t=i+2; t<NumberofMatrices-1; t++){
					for(int s=i+3; s<NumberofMatrices; s++){
						for(int a = 0; a < rowsize; a++){
							for(int b = 0; b< colsize; b++){
								sum[a][b] = bigStuff[i][a][b] + bigStuff[j][a][b] + bigStuff[t][a][b] + bigStuff [s][a][b];
							}
							for(int x=0; x<NumberofMatrices; x++){
								if(checksum(bigStuff[x], sum, rowsize, colsize)){
									search=1;	
									cout<<"Matrix "<<x << " can be written as the sum of matrices "<<i<< " " << j << " " << t << s << endl;	}}}}}}}}
	if(!search){   //if there is no combination found by k
		cout<<"There are no valid combinations in the given input file"<<endl;
	}
	return 0;
}
