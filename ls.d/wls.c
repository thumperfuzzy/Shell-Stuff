#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

void printDir(char *name, char *flags){
	DIR *dirp; 
	struct dirent *entry;

	dirp = opendir(name);
	
	if(!dirp){
		printf("Cannot open directory %s", name);
		//_exit(1);
	}
	
	do{
	errno = 0;
	entry = readdir(dirp);


	if(entry == NULL){
		if(errno != 0){
			printf("error");
		}
	}
	
	//printf("%s, %s", entry->d_type, entry->d_name);
	//char type[256] = entry->d_name;
	printf("%s", entry->d_name);
	}while(entry != NULL);

}


int main(int argc, char* argv){
	//check for some of the flags ls can use
	//TODO: implement these
	//-a: list everything, 
	//-l list file permissions, number of links, owner, group, size in bytes, last modification date, and name
	//-R recursively list everything
	//--help list help information and exit

	//check for folder from user
	//TODO: implement
	
	//if folder does not exist, print error and exit
	//TODO: implement

	//if no folder location specified, list current directory
	//TODO: implemet

	printDir("/", "");

	return(0);
}


