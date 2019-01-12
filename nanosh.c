/* 
 CS 3100 Lab 2 - by YOUR NAME HERE
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void cmdExit(int argc, char **argv) {
}

// getParameters returns the argc, the number of words found in cmd
//  while populating argv with pointers to each word
int getParameters(char *cmd, char **argv) {
	char *token;
	int argc = 0;
	token = strtok(cmd, " \t\n");
	while (token != NULL) {
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;		// set last + 1 argument to NULL
	return argc;
}

int main(int argc, char **argv) {

	char cmd[1024];
	char *rc;
	int myArgc = 0;
	char *myArgv[1000];

	while (1) {
		printf("nanosh: ");
		fflush(stdout);
		rc = fgets(cmd, sizeof(cmd), stdin);
		if (rc == NULL) {
			exit(0);
		}
		myArgc = getParameters(cmd, myArgv);

		// if no words typed: restart loop
		if (myArgc == 0) {			
			continue;
		}

		// if the first word is "exit", terminate the program
		if (strcmp(myArgv[0], "exit") == 0) {
			cmdExit(myArgc, myArgv);
			continue;
		}

		// add if statements here for the other internal commands
		//   and a default action that calls a function to fork()
		//   and exec() while the parent issues waitpid()
	}

	return 0;
} 
