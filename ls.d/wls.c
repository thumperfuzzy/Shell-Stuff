#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

//Set to true to print debug messages
#define debug false


int printDir(int flags, const char * path){
	DIR *dirp; 
	struct dirent *entry;

	//decode flags passed into function
	if(debug) printf("Flag var value: %d\n", flags);
	bool listAll = flags % 10;
	flags /= 10;
	if(debug) printf("Flag var value: %d\n", flags);
	bool recursive = flags % 10;
	flags /= 10;
	if(debug) printf("Flag var value: %d\n", flags);
	bool stats = flags;

	//print whether each flag was passed into the program
	if(debug) printf("Flags: l: %d, a: %d, R: %d\n", stats ? 1 : 0, listAll ? 1 : 0, recursive ? 1 : 0);

	//open directory to read
	dirp = opendir(path);
	
	//if directory does not exist print error message and return 1
	if(!dirp){
		printf("Cannot open directory %s", path);
		return(1);
	}
	
	//read and list all entries within the folder
	errno = 0;
	entry = readdir(dirp);
	while(entry != NULL){

	//If entry does not exist print the word error
	//TODO: Update this function to show useful information
	if(entry == NULL){
		if(errno != 0){
			printf("error");
		}
	}
	
	//Print files in the folder without . and .. unless -a is specified
	if(listAll){
		printf("%s\n", entry->d_name);
	}else{
		if(strcmp(entry->d_name, "..") > 0) printf("%s\n", entry->d_name);
	}
	
	//set errno to 0 and get next file name
	errno = 0;
	entry = readdir(dirp);
	}

	return(0);

}


int main(int argc, char* argv[]){
	int res = 0;

	//TODO: implement functionality for these flags
	//-a: list everything, 
	//-l list file permissions, number of links, owner, group, size in bytes, last modification date, and name
	//-R recursively list everything
	//-h, --help list help information and exit ////DONE////

	//check for folder from user
	//if no folder location specified, list current directory
	char* path = "./";
	int unusedArgs = argc - 1;
	int flags = 0;	

	//check flags and encode the flags passed in
	if(argc > 1){
		for(int i = 0; i < argc; i++){
			if(debug) printf("argv[%d]: %s\n", i, argv[i]);
			if(!strcmp(argv[i], "-a")){
				flags += 1;
				unusedArgs--;
			}
			if(!strcmp(argv[i], "-R")){
				flags += 10;
				unusedArgs--;
			}
			if(!strcmp(argv[i], "-l")){
				flags += 100;
				unusedArgs--;
			}
		}

		


		//if -h or --help is passed print usage information and exit
		if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
			printf("Usage: wls <flags> <path_to_dir>\n");
			printf("\
Flags:\n\
	-h --help    Print this message and exit.\n\
	-l           List stats about files and directories\n\
	-a           List all files and directories in directory\n\
	-R           Recursively list all contents of directories");
			return(0);
		}
	

		//If the user specifies a path set the path to the specified path
		//otherwise set the path to the current directory		
		if(unusedArgs){
			path = argv[argc - 1];
		}
		else{
			path = ".";
		}
	}

	res = printDir(flags, path);
	return(res);
}


