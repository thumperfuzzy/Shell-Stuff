# A simpler version of the linux ls command

This is a slow work in progress, as I am finding that ls is more complicated than I realized.     
Currently it will display files within a specified directory or in the current directory if a directory is not supplied.

## Features currently in progress:
* Do not show hidden files by default
* -a to show all files including hidden files
* -l to show stats about all files and directories
* -R to recursively list all files within the directory and all sub directories

## Features that may get implemented:
* Combining flags (for example -al or -lR). Currently each flag must be separate or it will not recognize them
* List more than one name per line
* Colors

## Features that I do not plan to add at the moment:
* The rest of the flags supported by ls
