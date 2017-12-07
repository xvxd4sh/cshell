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
    fprintf(stdout, "enter your command\n");

#ifdef UNIX
    cmdLine = readline(buildPrompt());
    if (cmdLine == NULL) {
      fprintf(stderr, "Unable to read command\n");
      continue;
    }
#endif

int history(char *hist[], int current)
{
        int i = current;
        int hist_num = 1;

        do {
                if (hist[i]) {
                        printf("%4d  %s\n", hist_num, hist[i]);
                        hist_num++;
                }

                i = (i + 1) % HISTORY_COUNT;

        } while (i != current);

        return 0;
}

int clear_history(char *hist[])
{
        int i;

        for (i = 0; i < HISTORY_COUNT; i++) {
                free(hist[i]);
                hist[i] = NULL;
        }

        return 0;
}

int main()
{
        char cmd[MAX_CMD_LEN];
        char *hist[HISTORY_COUNT];
        int i, current = 0;

        for (i = 0; i < HISTORY_COUNT; i++)
                hist[i] = NULL;

        while (1) {
                printf("user@shell # ");

                fgets(cmd, MAX_CMD_LEN, stdin);

                // get rid of the '\n' from fgets
                if (cmd[strlen(cmd) - 1] == '\n')
                        cmd[strlen(cmd) - 1] = '\0';

                free(hist[current]);
                hist[current] = strdup(cmd);
                current = (current + 1) % HISTORY_COUNT;
                if (strcmp(cmd, "history") == 0)
                        history(hist, current);
                else if (strcmp(cmd, "hc") == 0)
                        clear_history(hist);
                else if (strcmp(cmd, "quit") == 0)
                        break;
        }

        clear_history(hist);
        return 0;
}


    //parse
    info = parse(cmdLine);
    if (info == NULL){
      free(cmdLine);
      continue;
    }

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


int shell_exit(char **args)
{
  return 0;
}

    free_info(info);
    free(cmdLine);
  } // while(1)
}
