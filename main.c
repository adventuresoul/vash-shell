#include "main.h"

int main(int argc, char **argv){
    char *prompt = "(vash) $ ";
    char *lineptr = NULL;   
    char *lineptr_copy = NULL;
    char *token;
    int num_tokens = 0;
    const char *delim = " \n";
    size_t n = 0;
    ssize_t no_chars_read;
    int i;

    while (1){
        printf("%s", prompt);
        no_chars_read = getline(&lineptr, &n, stdin);

        // getline returns -1 if EOF or keyboard interrupt CTRL + D
        if(no_chars_read == -1){
            printf("Exiting vash.....\n");
            return -1;
        }
	
		// allocating space for copy of lineptr(later purpose), add + 1 so that it also includes null charecter
		lineptr_copy = malloc(sizeof(char) * (no_chars_read + 1));
		if(lineptr_copy == NULL){
			perror("memoryy allocation error");
			return -1;
		}
		// copy the contents from lineptr to lineptr_copy
		strcpy(lineptr_copy, lineptr);


		// Reset the num_tokens for each loop iteration
		num_tokens = 0;

		// tokenizing the lineptr to get the count of no of tokens
		token = strtok(lineptr, delim);
		while(token != NULL){
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;	// For null at end


		// allocate the space to hold array of strings and store each token in argv array, use lineptr_copy
		argv = malloc(sizeof(char*) * num_tokens);

		token = strtok(lineptr_copy, delim);
		for(i = 0; token != NULL; i++){
			argv[i] = malloc(sizeof(char) * (strlen(token) + 1)); // +1 for null terminator
			// if memory allocation error
			if(argv[i] == NULL){
				perror("Memory allocation error\n");
				// free up the already allocated space
				for(int j = 0; j < i; i++){
					free(argv[j]);
				}
			}
			// else copy the token
			strcpy(argv[i], token);
			// call subsequent strtok calls
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		// for(i = 0; i < num_tokens; i++){
		// 	printf("%s ", argv[i]);
		// }

		// execute the command
		execmd(argv);


		// freeing up the memory
		for(i = 0; i < num_tokens; i++){
			free(argv[i]);
		}
		free(lineptr);
		free(lineptr_copy);
		lineptr = NULL; // reset lineptr to NULL, else move free() call outside loop, which increases the memory overhaed
		lineptr_copy= NULL;
		n = 0;
    }
    
    
    return 0;
}
