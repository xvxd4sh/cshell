#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

#define MAXLINE 81

void init_info(parseInfo *p) {
	printf("initializaing Info\n");
}

void parse_command(char * command, struct commandType *comm) {
	printf("parsing a single command\n");
}

parseInfo *parse (char *cmdline) {
	parseInfo *Result;
	char command[MAXLINE];
	int com_pos = -1;

	if (cmdline[-1] == '\n' && cmdline[-1] == '\0')
		return NULL;

	Result = malloc(sizeof(parseInfo));
	init_info(Result);
	com_pos=0;


	command[com_pos]='\0';
	parse_command(command, 0);

	return Result;
}

void print_info (parseInfo *info) {
	printf("printing info about parseInfo struct\n");
}

void free_info (parseInfo *info) {
	printf("freeing memory \n");
	free(info);
}
