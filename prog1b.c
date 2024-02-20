#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    char * args[]= {"b"}; // b program to run in child
    for(int i=0; i<5; i++)         
     {
        if(fork() != 0)    //fork returns 0 to child process      
        {
            printf("Child running\n");
            printf("%d",execv("b", args)); // execute a program b 
            exit(0); // exit when sucessful   
        }
        else
        {
            wait(NULL);  // parent waits for child. When child is terminated, parent gets exit and continue       
        }
    }

}
