#include<stdio.h>
/*1,Declare your main like this
	argc specified the number of arguments (if no arguments are passed it's equal to 1 for the name of the program)
	argv is a pointer to an array of strings (containing at least one member - the name of the program)
	you would read the file from the command line like so: C:\my_program input_file.txt*/
int main(int argc, char* argv[])
{
	char* buffer_to_store_data_in;
/*2, Set up a file handle:*/
	FILE* file_handle;
	FILE* file_out;
/*3, Open the file_handle for reading:*/
	file_handle = fopen(argv[1], "r");

/*	fopen returns a pointer to a file or NULL if the file doesn't exist. argv1, contains the file you want to read as an argument
"r" means that you open the file for reading (more on the other modes here)
Read the contents using for example fgets:
*/
	fgets (buffer_to_store_data_in , 500 , file_handle);

/*you need a char * buffer to store the data in (such as an array of chars), the second argument specifies how much to read and the third is a pointer to a fil*/
/*4, write content to another file*/
	file_out = fopen(argv[2], "w");
	fwrite(buffer_to_store_data_in, sizeof(char), 500, file_out);
/*5, Finally close the handle*/
	fclose(file_handle);
	fclose(file_out);
	


}
