#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//character array to hold input from the user
	char inp[100];
	
	//clear input buffer, read input, and execute command
	while(true){
		memset(&inp[0], 0, sizeof(inp));	
		write(1, "# ", 2);
		read(0, inp, 99);
		//exit the program when the user sends the exit command
		if(!strcmp(inp, "exit\n")){
			break;
		}
		system(inp);	
	}
	return(0);
}
