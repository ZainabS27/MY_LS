#include "../include/myls.h"

// Visible contents of directory are printed - Question 2
void show_directory(char* directory){
    struct dirent *entry;
    DIR *dir = opendir(directory);

    if(dir == NULL){
        printf("Unable to open directory: %s\n", directory);
        return;
    }

    // Read directory contents and ignore hidden files
    while((entry = readdir(dir)) != NULL){
        if(entry->d_name[0] != '.'){
            printf("%s ", entry->d_name);
        }
        printf("\n");
    }
    closedir(dir);
}

// Visible and hidden contents of directory are printed - Question 3
void show_directory_all(char* directory){
    struct dirent *entry;
    DIR *dir = opendir(directory);

    if(dir == NULL){
        printf("Unable to open directory: %s\n", directory);
        return;
    }

    // Read all contents of directory
    while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

// Check file executability
int executable(char* path){
    if(access(path, X_OK) == 0){
        return 0;
    }
    return 1;
}

// Print additional info about visible files including total number of files, if executable, and file size - Question 4/5
void show_directory_long(char* directory){
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(directory);
    int count = 0;

    if(dir == NULL){
        printf("Unable to open directory: %s\n", directory);
        return;
    }

    // Count number of visible functions in directory
    while((entry = readdir(dir)) != NULL){
        if(entry->d_name[0] != '.'){
            count++;
        }
    }
    rewinddir(dir); // Reset pointer
    printf("Total: %d\n", count);

    // List files/folders in directory with additional information including if executable and file size
    while((entry = readdir(dir)) != NULL){
        if(entry->d_name[0] != '.'){
            // Construct directory path with file name
            char path[4096];
            strcpy(path, directory);
            strcat(path, "/");
            strcat(path, entry->d_name);

            // Print * after name if executable
            if(executable(path) == 0){
                printf("%s*", entry->d_name);
            }else{
                printf("%s", entry->d_name);
            }

            if(stat(path, &file_stat) == 0){
                printf(" %lld\n", file_stat.st_size);
            }
        }
        printf("\n");
    }
    closedir(dir);
}

// Print additional info about visible and hidden files including total number of files, if executable, and file size - Question 4/5
void show_directory_long_all(char* directory){
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(directory);
    int count = 0;

    if(dir == NULL){
        printf("Unable to open directory: %s\n", directory);
        return;
    }

    // Count number of contents in directory
    while((entry = readdir(dir)) != NULL){
        count++;
    }
    rewinddir(dir); // Reset pointer
    printf("Total: %d\n", count);

    // List files/folders in directory with additional information including if executable and file size
    while((entry = readdir(dir)) != NULL){
        // Construct directory path with file name
        char path[4096];
        strcpy(path, directory);
        strcat(path, "/");
        strcat(path, entry->d_name);

        // Print * after name if executable
        if(executable(path) == 0){
            printf("%s*", entry->d_name);
        }else{
            printf("%s", entry->d_name);
        }

        if(stat(path, &file_stat) == 0){
            printf(" %lld\n", file_stat.st_size);
        }
        printf("\n");
    }
    closedir(dir);
}