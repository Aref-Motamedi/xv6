#include "types.h"
#include "user.h"

struct timeVariables
{
  int creationTime;           // Time process created
  int terminationTime;        // Time process terminated
  int sleepingTime;           // Amount of time process is sleeped
  int readyTime;              // Amount of time process is ready
  int runningTime;            // Amount of time process is running
};



int main(void){
    changePolicy(2);
    int parent = getpid();
    int ttav=0, wtav=0, cbtav=0;
    int ttgroup[5]={0,0,0,0,0}, wtgroup[5]={0,0,0,0,0}, cbtgroup[5]={0,0,0,0,0};

    printf(1,"parent id = %d \n",parent);
    int i;
    for(i = 25 ; i > 0 ; i--)
    {
        if (getpid() == parent) {
            fork();
        }
        else{
            if (i>20)
                changePriority(5);
            else if (i>15)
                changePriority(4);
            else if (i>10)
                changePriority(3);
            else if (i>5)
                changePriority(2);
            else
                changePriority(1);
        int j;
        for(j = 0 ; j < 500 ; j++)
        {
        printf(1,"[%d] : [%d]\n",getpid(), j);
         }
         exit();

        }
        
    }
    
    struct timeVariables tv = {0,0,0,0,0};
    struct timeVariables *tv1 = &tv;

    if(getpid() == parent)
    {
    int childid=0;
                
    sleep(5500);
    for (i=0;i<25;i++){
        childid = waitForChild(tv1);
    
        
        printf(1,"------------------------------------------------------------\n");
        printf(1,"TT\t\tCBT\t\tWT\n");
        printf(1,"%d\t\t%d\t\t%d\n",tv1->terminationTime - tv1->creationTime,tv1->runningTime, tv1->terminationTime - tv1->creationTime - tv1->runningTime );
        ttav += tv1->terminationTime - tv1->creationTime;
        cbtav += tv1->runningTime;
        wtav += tv1->terminationTime - tv1->creationTime - tv1->runningTime;
        if (childid == -1){
            printf(1,"Child Killed\n");
        } else if (childid <= 8){
            ttgroup[1] += tv1->terminationTime - tv1->creationTime;
            cbtgroup[1] += tv1->runningTime;
            wtgroup[1] += tv1->terminationTime - tv1->creationTime - tv1->runningTime;

        } else if (childid <= 13){
            ttgroup[2] += tv1->terminationTime - tv1->creationTime;
            cbtgroup[2] += tv1->runningTime;
            wtgroup[2] += tv1->terminationTime - tv1->creationTime - tv1->runningTime;

        } else if (childid <= 18){
            ttgroup[3] += tv1->terminationTime - tv1->creationTime;
            cbtgroup[3] += tv1->runningTime;
            wtgroup[3] += tv1->terminationTime - tv1->creationTime - tv1->runningTime;

        } else if (childid <= 23){
            ttgroup[4] += tv1->terminationTime - tv1->creationTime;
            cbtgroup[4] += tv1->runningTime;
            wtgroup[4] += tv1->terminationTime - tv1->creationTime - tv1->runningTime;

        } else if (childid <= 28){
            ttgroup[0] += tv1->terminationTime - tv1->creationTime;
            cbtgroup[0] += tv1->runningTime;
            wtgroup[0] += tv1->terminationTime - tv1->creationTime - tv1->runningTime;

        }  

    }
    printf(1,"\nAverage Priority 1 TurnAround Time: %d\t\t CBT: %d\t\t Waiting Time: %d\n", ttgroup[0] / 5 ,cbtgroup[0] /5, wtgroup[0] / 5);  
    printf(1,"\nAverage Priority 2 TurnAround Time: %d\t\t CBT: %d\t\t Waiting Time: %d\n", ttgroup[4] / 5 ,cbtgroup[4] /5, wtgroup[4] / 5);  
    printf(1,"\nAverage Priority 3 TurnAround Time: %d\t\t CBT: %d\t\t Waiting Time: %d\n", ttgroup[3] / 5 ,cbtgroup[3] /5, wtgroup[3] / 5);  
    printf(1,"\nAverage Priority 4 TurnAround Time: %d\t\t CBT: %d\t\t Waiting Time: %d\n", ttgroup[2] / 5 ,cbtgroup[2] /5, wtgroup[2] / 5);  
    printf(1,"\nAverage Priority 5 TurnAround Time: %d\t\t CBT: %d\t\t Waiting Time: %d\n", ttgroup[1] / 5 ,cbtgroup[1] /5, wtgroup[1] / 5);  
    
    printf(1,"\nAverage TurnAround Time: %d\t\t CBT: %d\t\t Waiting Time: %d\n", ttav / 25 ,cbtav /25, wtav / 25);  
    }

    
    exit();



}