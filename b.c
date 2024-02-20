#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
 /* the execution prog when prog1b calls. */  
int main () {
	printf("I am the grandchild"); // prints the grandchild
	return 1;
}
