#include "types.h"
#include "user.h"

int main(void){
    changePolicy(0);
    int i=0;
    for (i=0;i<100;i++){
        printf(1,"a");
    }
    printf(1,"\nchangepolicy1\n");
    changePolicy(1);
    for (i=0;i<100;i++){
        printf(1,"b");
    }

    exit();
}
