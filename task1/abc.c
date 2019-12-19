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
    int p1[2];
    int p2[2];
    if (pipe(p1)<0 || pipe(p2)<0){
        printf("failed to pipe\n");
        return 0;
    }

    pid_t pid = fork();
    
    if (pid==0){

        close(p1[1]); //close the write side of pipe 1

        char str[1024];
        read(p1[0],str,1024); // getting the number from parent
        
        int number = babyfunc(str); // getting the sum of even digits
        
        char newstr[128] = "The sum of even digits in the input number: ";

        // *** concatenating ***
        int numSize = 0;
        int i = 0;
        int tmp = number;
        while(tmp > 0)
        {
            numSize++;
            tmp /= 10; 
        }
        
        int newstrSize = strlen(newstr);
        char numberString[numSize];
        if(number == 0)
        {
        newstr[newstrSize] = 0 + '0'; 
        }
        tmp = number;
        for(i = numSize-1  ; i >= 0 ; i--)
        {
            int numBit;
            int temp = tmp / 10;
            temp *= 10;
            numBit = tmp - temp;
            tmp /= 10;
            
            numberString[i] = numBit + '0'; 
        }
        int j = 0;
       for(j = 0 ; j < numSize ; j++)
       {
            newstr[newstrSize] = numberString[j];
           newstrSize++;
       }
        int k = 0;
        newstrSize = strlen(newstr);
        int strSize = strlen(str);
        str[strSize] = ' ';
        strSize++;

        for(k = 0 ; k < newstrSize ; k++)
        {
            str[strSize] = newstr[k];
            strSize++;
            if(k == newstrSize - 1)
            str[strSize] = '\0';

        }        
        close(p2[0]); // close the read side of pipe 2
        write(p2[1],str,128); // passing the result
        close(p2[1]); // close the write side of pipe 2
        
        return 0;
        
    }else if (pid>0){
        
        // parent process

        char number[1024];
        scanf("%s", number);
        
        close(p1[0]); // closing the read side of pipe 1
        
        write(p1[1], number, strlen(number)+1); // sending number
        close(p1[1]); // closing the write side of pipe 1
        

        close(p2[1]); // closing the write side of pipe 2

        char str[128];
        read(p2[0],str,128); // getting the result from child
        
        close(p2[0]); //closing the read side of pipe 2
        
        printf("%s\n",str);

        return 0;  
    }
}

