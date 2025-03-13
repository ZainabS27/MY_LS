#include "myls.c"

int main(int argc, char* argv[]){
    char* directory = ".";
    int a_flag = 0;
    int l_flag = 0;

    // Increment through command line arguments to check if they contain a flag, directory, both, or none
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--all") == 0){ // Check if only print all flag was inputted
            a_flag = 1;
        }else if(strcmp(argv[i], "-l") == 0){ // Check if only print long flag was inputted
            l_flag = 1;
        }else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0){ // Check if print version flag was inputted
            printf("my_ls v.1.0 by Zainab Spall\n");
            return 0;
        }else if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){ // Check if print help flag was inputted
            printf("MY_LS\n");
            printf("USAGE\n");
            printf("\tmy_ls [OPTION]... [FILE]...\n");
            printf("DESCRIPTION\n");
            printf("\tLists contents of directory(current by default), such as files and folders contained inside, their sizes in bytes, and if they are executable.\n");
            printf("FLAGS\n");
            printf("\t-a, --all\n");
            printf("\t\tshows hidden files (beginning with .) as well as visible files\n");
            printf("\t-l\n ");
            printf("\t\tshows long list with the file size in bytes of each file\n");
            printf("\t-v, --version\n");
            printf("\t\tshows version information\n");
            printf("\t-h, --help\n ");
            printf("\t\tdisplays this man page\n");
            printf("OUTPUT VALUES\n");
            printf("\t0 if ok\n");
            printf("\t1 if errors\n");
            printf("AUTHOR\n");
            printf("\tZainab Spall\n");
            return 0;
        }else if(argv[i][0] == '-'){ // Check if any flag was specified and assume it is known 
            int known_flag = 1;
            for(int j = 1; argv[i][j] != 0; j++){ // Stop looping at end of string (null terminator reached)
                // Checking argument for al or la flag
                if(argv[i][j] == 'a'){
                    a_flag = 1;
                }else if(argv[i][j] == 'l'){
                    l_flag = 1;
                }else{
                    printf("Unknown flag: %s\n", argv[i]);
                    return 1;
                }
            }
        }else{
            directory = argv[i]; // If no flags given, its a directory
        }
    }

    // Call correct function given input
    if(a_flag && l_flag){
        show_directory_long_all(directory);
    }else if(a_flag){
        show_directory_all(directory);
    }else if(l_flag){
        show_directory_long(directory);
    }else{
        show_directory(directory);
    }
    return 0;
}