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
        printf(1,"Hiiiii");
        int parent = getpid();
        // int ttav=0, wtav=0;
        // // int *tt = &ttav;
        // // int *wt = &wtav;
        printf(1,"parent id = %d \n",parent);
        // int i;
        // for(i = 10 ; i > 0 ; i--)
        // {
        //         if (getpid()==parent){
        //                 fork();
        //         }
        // }
fork();
fork();
fork();
fork();


        int j;
        for(j = 0 ; j < 10 ; j++)
        {
                printf(1,"[%d] : [%d]\n",getpid(), j);
        }
        struct timeVariables tv = {0,0,0,0,0};
        struct timeVariables *tv1 = &tv;

        // if(getpid == parent)
        // {
        waitForChild(tv1);
        sleep(100);
        // printf(1,"[%d] finiiiiiiiiiiiiiiiiiiiiiiiiiiiiish\n",getpid());
        printf(1,"PID\tTT\tCBT\tWT\n");
        printf(1,"%d\t%d\t%d\t%d\n",getpid(),tv1->terminationTime - tv1->creationTime,tv1->runningTime, tv1->terminationTime - tv1->creationTime - tv1->runningTime );
        // ttav += tv1->terminationTime - tv1->creationTime;
        // wtav += tv1->terminationTime - tv1->creationTime - tv1->runningTime;
        if (getpid() == parent){
                // sleep(100);
                // printf(1,"average %d\t%d\n", ttav / 8 , wtav / 8);  
        }
        // else
        // {
        //         wait();
        // }
        
        exit();



}