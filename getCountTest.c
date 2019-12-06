#include "types.h"
#include "user.h"

int main(int num, char* arg[]){
    int parent = getpid();

    // int counter=0;
    // while (str[counter] != ''){
    //     printf(1,"%d\n",(int)str[counter]);
    //     counter++;
    // }
    fork();
    fork();

    if (getpid()==parent){
        // printf(1,"%d\n",getCount());
        // printf(1,"%d",n);
    }

    exit();
}

// int convert(char str[]){

//     int num;
    

//     return null;
// }
