#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


int printDir(int flags, const char * path){
	DIR *dirp; 
	struct dirent *entry;
	//int flags = flagArg;
  
	printf("%d\n", flags);
	bool listAll = flags % 10;
	flags /= 10;
	printf("%d\n", flags);
	bool recursive = flags % 10;
	flags /= 10;
	printf("%d\n", flags);
	bool stats = flags;

	
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
	char* path = "./";
	int unusedArgs = argc - 1;
	int flags = 0;	

	//check flags
	if(argc > 1){
		for(int i = 0; i < argc; i++){
			printf("%s\n", argv[i]);
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
		printf("%d", unusedArgs);
		if(unusedArgs){
			path = argv[argc - 1];
		}
		else{
			path = ".";
		}


		if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
			printf("Usage: wls <flags> <path_to_dir>");
			return(0);
		}
	}
	res = printDir(flags, path);
	return(res);
}


