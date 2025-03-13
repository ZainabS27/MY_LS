#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Lists visible files in a directory
void show_directory(char* directory);

// Lists visible and hidden files in a directory
void show_directory_all(char* directory);

/* Lists visible files in a directory with additional info: 
 * total number of contents of directory
 * if executable, * is printed after file name
 * size of file in bytes
*/
void show_directory_long(char* directory);

/* Lists visible  and hidden files in a directory with additional info:
 * total number of contents of directory
 * if executable, * is printed after file name
 * size of file in bytes
*/
void show_directory_long_all(char* directory);

