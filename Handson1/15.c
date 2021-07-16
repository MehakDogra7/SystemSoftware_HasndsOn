/*15. Write a program to display the environmental variable of the user (use environ).*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	extern char **environ;
	int i=0;
	while(environ[i])
	{
		printf("%s\n",environ[i++]);
	}

return 0;
}
