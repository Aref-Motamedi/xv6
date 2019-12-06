#include "types.h"
#include "user.h"

int main(int num, char* arg[]){
    int parent = getpid();

    int i=0;
    int number =0;
    while (arg[1][i] != '\0'){
        number = (number *10) + arg[1][i] -48;
        i++;

    }

    fork();
    fork();

    if (getpid()==parent){
         printf(1,"%d \t %d\n",number,getCount(number));
        }

    exit();
}
