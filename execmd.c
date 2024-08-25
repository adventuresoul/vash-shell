#include "main.h"

void execmd(char **argv){
    pid_t pid;
    char *command = NULL;

    // create child
    pid = fork();

    if(pid == -1){
        perror("Child creation unsucessful\n");
    }
    if(pid == 0){
        if(argv){
            command = argv[0];
            // execute the command with execve
            if(execve(command, argv, NULL) == -1){
                perror("Error:");
            }
        }
    }
    else{
        wait(NULL);
    }
    
}