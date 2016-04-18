#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int execute_program(char ** prog){
	
	pid_t pid, waitpid;
	int status;
	
	if((pid = fork()) < 0) {
		perror("execute_program");
		return -1;
	} else if(pid == 0){
		//in child
		if(execv(prog[0], prog) < 0){
			perror("execute_program");
			return -1;
		}
	} else {
		while(wait(&status) != pid);
		
	}
	return 1;
}

void convertline(char * line, char ** a)
{
	int i = 0;
	char * token;
	token = strtok(line, "\a\t\r\n ");
	while(token != NULL) {
		a[i] = token;
		puts(token);
		i++;
		token = strtok(NULL, "\a\t\r\n ");
	}
}


int main(int argc, char * argv[])
{
	//just for testing purposes
	/*char inputstr[81] = "./prargs.sh john\0";
	char inputstr2[] = {'.','/','v','a','l','i','d','.','s','h',' ','j','o','h','n','\0'};
	char * args[81];

	convertline(inputstr, args);
	execute_program(args);
	*/
	
    return 0;
}
