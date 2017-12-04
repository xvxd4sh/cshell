#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unist.h>


enum BUILTIN_COMMANDS { NO_SUCH_BUILTIN=0, EXIT,JOBS};

char *
buildPrompt()
{
  return  "%";
}

int
isBuiltInCommand(char * cmd){

  if ( strncmp(cmd, "exit", strlen("exit")) == 0){
    return EXIT;
  }
  return NO_SUCH_BUILTIN;
}


int
main (int argc, char **argv)
{
  char * cmdLine;
  parseInfo *info;
  struct commandType *com;
  fprintf(stderr, "Press ctrl-c to exit\n");
#ifdef UNIX

    fprintf(stdout, "UNIX version\n");
#endif

#ifdef WINDOWS
    fprintf(stdout, "WINDOWS version\n");
#endif

  while(1){
    fprintf("promt\n");//place for the prompt code

#ifdef UNIX
    cmdLine = readline(buildPrompt());
    if (cmdLine == NULL) {
      fprintf(stderr, "Unable to read command\n");
      continue;
    }
#endif

    //place for history and !x !-x code

    //parse calling
    info = parse(cmdLine);
    if (info == NULL){
      free(cmdLine);
      continue;
    }
    //prints the info struct
    print_info(info);

/*
    com=&info->CommArray[0];
    if ((com == NULL)  || (com->command == NULL)) {
      free_info(info);
      free(cmdLine);
      continue;
    }
*/

/*
    if (isBuiltInCommand(com->command) == EXIT){
      exit(1);
    }
*/
    //Start function here

    free_info(info);
    free(cmdLine);
  } // while(1)
}
