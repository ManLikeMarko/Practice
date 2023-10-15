#include "main.h"
/**
 * executeCommand - a function that executes external commands
 *
 * Return: void
 */

void executeCommand(const char *command)
{
	pid_t pid = fork();
	/** a child process has been created */
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");/** fork error handled */
		exit(1);
	}
	if (pid == 0)
		/** child process is initiated*/
		if (execvp(command, args) == -1)
		{
			perror("execvp");
			exit(1);
		}
}
else
{
	waitpid(pid, &status, 0); /**Parent process*/
}
free(args[0]); /**Free memory allocated for strdup*/
