#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//CODE TO BE CALLED BY PART 1B

int main(int argc, char **argv)
{
  //this code is called from the main code for part 1b using execve
  //this code just states it is the grandchild process
  printf("I am the grandchild %d \n",getpid());
  return 0;
}

