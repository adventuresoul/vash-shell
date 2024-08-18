#include "main.h"

int main(int argc, char **argv){
    char *prompt = "(vash) $ ";
    char *lineptr = NULL;   
    char *lineptr_copy = NULL;
    const char *delim = " \n";
    size_t n = 0;
    ssize_t no_chars_read;


    // infinite loop 
    while (1){
        printf("%s", prompt);
        no_chars_read = getline(&lineptr, &n, stdin);   //passing address of buffer, size, stream
        // getline returns -1 if EOF or keyboard interrupt CTRL + D
        if(no_chars_read == -1){
            printf("Exiting vash.....\n");
            return -1;
        }
        printf("%s", lineptr);
        
        // free up allocated memory for lineptr buffer
        free(lineptr);
        lineptr = NULL; // reset lineptr to NULL, else move free() call outside loop, which increases the memory
        n = 0;
    }
    
    
    return 0;
}