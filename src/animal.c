/** 
 * Prints text files (preferably of animals) to Unix terminal
 * 
 * @author drender
 * @date 2020/09/24
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "animal.h"

int main(int argc, char *argv[])
{
    if(!hasCommand(argv[1]))
    {
        printf("The zoo currently does not contain %s at this time.\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *parent_directory = NULL;
    char *path             = NULL;

    if(!getParentDirectory(&parent_directory)) return EXIT_FAILURE;

    path = malloc((strlen(parent_directory) + strlen(DRAWING_FOLDER) + strlen(argv[1]) + strlen(EXTENSION) + 1)*sizeof(char));

    sprintf(path, "%s%s%s%s", parent_directory, DRAWING_FOLDER, argv[1], EXTENSION);

    free(parent_directory);

    FILE *myanimal = fopen(path, "r");
    
    if(myanimal == NULL)
    {
        printf("Missing file: %s\n", path);
        return EXIT_FAILURE;
    }

    free(path);

    char next_char;

    while( (next_char = fgetc(myanimal)) != EOF) printf("%c", next_char);

    fclose(myanimal);

    return EXIT_SUCCESS;
}

bool hasCommand(char* str)
{
    for(int i=0; i<LIST_SIZE; i++)
    {
        if(!strcmp(str, COMMAND_LIST[i])) return true;
    }

    return false;
}

bool getParentDirectory(char** directory)
{
    if(*directory != NULL) printf("Warning: potential memory leak on parent_directory!\n");

    *directory = getcwd(*directory, 0);

    if(*directory == NULL) 
    {
        printf("Failure retrieving directory.\n");
        return false;
    }

    int i = strlen(*directory) - strlen(SOURCE_FOLDER);

    for(; i<strlen(*directory); i++) *(*directory + i) = '\0';

    return true;
}