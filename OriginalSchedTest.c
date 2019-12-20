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
        changePolicy(1);
        int parent = getpid();
         int ttav=0, wtav=0, cbtav=0;

        printf(1,"parent id = %d \n",parent);

        struct timeVariables tv = {0,0,0,0,0};
        struct timeVariables *tv1 = &tv;

        int k;
        for(k = 10 ; k > 0 ; k--)
        {
                if (getpid() == parent){
                      fork();
                }
      
        }
        int j;
        for(j = 0 ; j < 1000 ; j++)
        {
                printf(1,"[%d] : [%d]\n",getpid(), j);
        }
        
        
 
        if (getpid() == parent){
                   sleep(4000);
                
                for (j=0;j<10;j++){
                        waitForChild(tv1);
                        printf(1,"-------------------------------------------------\n");
                        printf(1,"TurnAround Time\tCBT\tWaiting Time\n");
                        printf(1,"%d\t\t%d\t%d\n",tv1->terminationTime - tv1->creationTime,tv1->runningTime, tv1->terminationTime - tv1->creationTime - tv1->runningTime );
                        ttav += tv1->terminationTime - tv1->creationTime;
                        cbtav+= tv1->runningTime;
                        wtav += tv1->terminationTime - tv1->creationTime - tv1->runningTime;
                }
                //sleep(100);
                printf(1,"Average TurnAround Time: %d\t\tCBT: %d\t\tWaitingtime: %d\n", ttav / 10 ,cbtav /10, wtav / 10);  
        }
        exit();
}