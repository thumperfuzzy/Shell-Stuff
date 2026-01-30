#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 100

int main(int argc, char *argv[]){
	int fptr;
	char buffer[MAX_BUFFER_SIZE];
	
	//display usage if no file is input
	if(argc == 1){
		write(2, "Usage: wcat <filename>", 23);
		return(1);
	}

	//open file and get file pointer or display an error if file cannot be found
	fptr = open(argv[1], O_RDONLY);
	
	if(fptr == -1){
		write(2, "Invalid filename", 17);
		return(1);
	}

	//read in file contents, then display them
	ssize_t bytesRead = read(fptr, buffer, MAX_BUFFER_SIZE-1);  
	
	while(bytesRead != 0){
		write(1, buffer, bytesRead);
		bytesRead = read(fptr, buffer, MAX_BUFFER_SIZE-1);  

	}

	//close the file
	close(fptr);

	return(0);

}
