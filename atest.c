#include "types.h"
#include "user.h"

int main(void){
    changePolicy(0);
    fork();
    
    
    int i=0;
    for (i=0;i<100;i++){
        printf(1,"a%d",getpid());
    }
    changePriority(14);
    for (i=0;i<100;i++){
        printf(1,"b%d",getpid());
    }

    exit();
}
