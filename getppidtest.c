#include "types.h"
#include "user.h"

int main(void){
    int parent = getpid();
    int child = fork();
    if (child==0){
        printf(1,"child is here. parent %d.  %d     %d\n",parent,getpid(),getppid());
    } else {
        wait();
        printf(1,"parent is here. child %d.  %d     %d\n",child,getpid(),getppid());
    }
    exit();
}
