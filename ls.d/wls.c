#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


int printDir(const char *args, int numArgs){
	DIR *dirp; 
	struct dirent *entry;

	bool listAll = false;
	bool recursive = false;
	bool stats = false;

	char* path;
	int unusedArgs = numArgs-1;
	printf("%d", unusedArgs);

	// TODO: Fix errors. What's wrong, idk yet.
		//			passing flags[i] to strcmp is trying to convert to int‽
	//check flags
	for(int i = 1; i <= numArgs; i++){
		printf("%s\n", &args[i]);
		if(!strcmp(&args[i], "-a")){
			listAll = true;
			unusedArgs--;
		}
		if(!strcmp(&args[i], "-R")){
			recursive = true;
			unusedArgs--;
		}
		if(!strcmp(&args[i], "-l")){
			stats = true;
			unusedArgs--;
		}
	}

	if(unusedArgs){
		path = &args[numArgs - 1];
	}
	else{
		path = ".";
	}
	
	printf("Flags: l: %d, a: %d, r: %d\n", stats ? 1 : 0, listAll ? 1 : 0, recursive ? 1 : 0);

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


	if(entry == NULL){
		if(errno != 0){
			printf("error");
		}
	}
	

	if(strcmp(entry->d_name, "..") > 0){
		printf("%s\n", entry->d_name);
	}
	errno = 0;
	entry = readdir(dirp);
	}

	return(0);

}


int main(int argc, char* argv[]){
	int res = 0;

	//check for some of the flags ls can use
	//TODO: implement these
	//-a: list everything, 
	//-l list file permissions, number of links, owner, group, size in bytes, last modification date, and name
	//-R recursively list everything
	//-h, --help list help information and exit

	//check for folder from user
	//if no folder location specified, list current directory
	if(argc > 1){
		if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
			printf("Usage: wls <flags> <path_to_dir>");
			return(0);
		}
	}
	res = printDir(*argv, argc);
	return(res);
}


