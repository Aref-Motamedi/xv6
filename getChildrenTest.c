#include "types.h"
#include "user.h"

int main(void){
    int parent = getpid();

    int n = fork();
    if (n==0){
        wait();
    }
    n = fork();
    if (n==0){
        wait();
    }

    printf(1,"Process ID: %d. Parent process ID: %d. \n\n",getpid(),getppid());

    if (getpid()==parent) {
        
        printf(1,"Output of getChildren Systemcall with input number of %d is %d.\n",parent,getChildren(getpid()));
    }
    exit();
}
