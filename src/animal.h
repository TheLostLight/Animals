#include <stdbool.h>

const char *COMMAND_LIST[] = { "dog",
                               "monkey"
                              };
                    
const int LIST_SIZE = 2;

const char *SOURCE_FOLDER    = "src";

const char *DRAWING_FOLDER   = "drawings/";

const char *EXTENSION = ".txt";

bool hasCommand(char*);

bool getParentDirectory(char**);