#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 


int main()
{
    pid_t pid = fork();
    if (pid==0){
        // wait ta baba bede

    }else if (pid>0){
        int number;
        scanf("%d",&number);
        // numbero bede bache
        //wait ta bache bede
    }
    return 0;
}

int babyfunc(int number){
    
    return sumeven
}