#include "main.h"

/**
 * displayPrompt - a function that displays the prompt feature
 *
 * Return : NULL
 */

void displayPrompt(void);
{
	printf("myshell$ ")
}
int main(void)
{

	char *input = NULL;	/** Pointer to store user input */
	size_t len = 0;	/** Initial size of the buffer */
	ssize_t read;	/** Number of characters read */

	while (1)
	{
		displayPrompt();

		read = getline(&input, &len, stdin);
		/** Read a line of input using getline */
		if (read == -1) /** Handle Ctrl+D or error (end of file or input failure) */
		{
			if (feof(stdin))
			{
			printf("Goodbye!\n");
			}
			else
			{
				perror("Error reading input");
			}
			break;
		}
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}

		if (strchr(input, ' ') != NULL)
			/** checks if the input contains any spaces */
		{
			printf("Error: Command should be a single word without spaces. \n");
			continue; /** Prompt the user again */
		printf("You entered: %s\n", input);
		/** Now, you can process the user's input or execute commands */
	}

	free(input);
	return (0);
}

