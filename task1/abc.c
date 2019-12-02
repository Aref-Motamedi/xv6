#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include<string.h>

int babyfunc(char number[]){
        int sumeven = 0;
        int i;
    for(i = 0 ; i < strlen(number) ; i++)
    {
        if(number[i] % 2 == 0)
        sumeven = sumeven + number[i]-48;
        
    }

    return sumeven;
}

int main()
{
    pid_t pid = fork();
    int p1[2];
    pipe(p1);
    if (pid==0){
        // wait ta baba bede
      // printf("sum even digits is = %d",babyfunc(number));


    }else if (pid>0){
        char number[1024];
        scanf("%s", number);
        // numbero bede bache
        //wait ta bache bede

    return 0;
}
}

