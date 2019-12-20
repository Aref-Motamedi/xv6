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
        printf(1,"parent id = %d \n",parent);
        int i;
        for(i = 10 ; i > 0 ; i--)
        {
                if (getpid()==parent){
                        fork();
                }
        }
        int j;
        for(j = 0 ; j < 50 ; j++)
        {
                printf(1,"[%d] : [%d]\n",getpid(), j);
        }
        struct timeVariables tv = {0,0,0,0,0};
        // if(getpid == parent)
        // {
        waitForChild(&tv);
        printf(1,"PID\tTT\tCBT\tWT\n");
        printf(1,"%d\t%d\t%d\t%d\n",getpid(),tv.terminationTime - tv.creationTime,tv.runningTime, tv.terminationTime - tv.creationTime - tv.runningTime );

        // }
        // else
        // {
        //         wait();
        // }
        




}