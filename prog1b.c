#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// CODE FOR PART 1B
int main(int argc, char **argv)
{
  int res;
  int max = 10;    //# of processes created
  int i = 0;
  //loop to create child processes
  while(i < max)
    { 
      res = fork();  //fork it up
      if (res < 0)
	{
	  //forking error case
	  perror("fork");
	  exit(1);
	}
      else if (res == 0)
	{
	  //this case is for the children.
	  //initialise args to execute the other program.
	  printf("Child Running %d \n",getpid());
	  char *args[] = {"./prog1be", NULL};
	  //call the other program using execve.
	  res = execve(args[0], args, NULL);
	  //after the execve call, this will never be reached unless there
	  //is an error.
	  exit(1);
	}
      else 
	{
	  //increment the loop and wait for the children to call the 
	  //external commands
	  i++;
	  int child_pid = res;
	  waitpid(child_pid, NULL, 0);
	}
    }
  return 0;
}
