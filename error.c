#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH 1024

/**
* _getenv - entry
* @path: string
* Return:(0)
*/

char *_getenv(const char *path)
{

	char *contents = NULL;
	char *last_content = NULL;
	char *copy_env;
	char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
	copy_env = str_dup(environ[i]);

	if (copy_env == NULL)
	{
		free(copy_env);
		return (NULL);
	}
	contents = strtok(copy_env, "=");

	if (str_cmp(contents, path) == 0)
	{
		last_content = _strstr(environ[i], "/");
	}
	i++;
	free(copy_env);
	}
	return (last_content);
}

/**
* get_path_directories - entry
* Return:
*/

/* Get list of directories in PATH environment variable */
char **get_path_directories()
{
    char *path = getenv("PATH"); /* Get value of PATH environment variable */
    if (!path) { /* If PATH is not set, return NULL */
        writeStringToStderr("PATH variable not set\n");
        return NULL;
    }

    int num_dirs = 1;
    char *p = path;
    while (*p) { /* Count number of directories in PATH */
        if (*p == ':') {
            num_dirs++;
        }
        p++;
    }

    char **dirs = malloc((num_dirs + 1) * sizeof(char *)); /* Allocate array for directories */
    if (!dirs) { /* Check for allocation failure */
        return NULL;
    }

    int i = 0;
    char *dir = strtok(path, ":");
    while (dir) { /* Tokenize path and populate array of directories */
        dirs[i++] = str_dup(dir);
        dir = strtok(NULL, ":");
    }
    dirs[i] = NULL; /* Set last element of array to NULL */

    return dirs;
}

 

/**
 * found_function - Returns the full path of a command executable
 * @command: Command to look for
 *
 * Return: Full path of executable, or NULL if not found
 */

void found_function(char *command) {
    char **path_dirs; /* Array of directories in PATH variable */
    char *full_path;  /* Complete path to command if it exists */
    int i;            /* Counter for looping through path directories */

    /* Check if command is a file in the current directory */
    if (access(command, X_OK) == 0) {
        printf("%s is in the current directory\n", command);
        return;
    }

    struct stat st; /* Define stat outside of if statement */

    /* Check if command is in one of the directories listed in PATH variable */
    path_dirs = get_path_directories(); /* Get list of PATH directories */
    for (i = 0; path_dirs[i] != NULL; i++) {
        full_path = get_full_path(path_dirs[i], command);

        /* Check if file exists and is executable */
        if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0) {
            printf("%s is in the directory %s\n", command, path_dirs[i]);
            free(full_path); /* Free memory allocated for full_path */
            free(path_dirs); /* Free memory allocated for path_dirs */
            return;
        }

        free(full_path); /* Free memory allocated for full_path */
    }

    /* Command not found */
    writeStringToStderr("Command not found\n");
    free(path_dirs); /* Free memory allocated for path_dirs */
}

/**
 * get_full_path - Returns the full path of a command executable given a directory
 * @dir: Directory to search in
 * @command: Command to look for
 *
 * Return: Full path of executable, or NULL if not found
 */
char *get_full_path(char *dir, char *command)
{
    char *full_path;

    /*Allocate memory for full path (dir + / + command) and build it*/
    full_path = malloc((str_len(dir) + str_len(command) + 2) * sizeof(char));

    if (full_path == NULL)
    {
        writeStringToStderr("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    str_cpy(full_path, dir);
    str_cat(full_path, "/");
    str_cat(full_path, command);

    return (full_path);
}

