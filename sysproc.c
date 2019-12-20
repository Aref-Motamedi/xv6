#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"



int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// get parent pid
int
sys_getppid(void)
{
  return getppid();
}
// get children's id
int
sys_getChildren(void)
{
  int procid;
  argint(0,&procid);
  
  return getChildren(procid);
}

// get number of times the referenced system call was invoked by the calling process.
int
sys_getCount(void)
{
  int sysid;
  argint(0,&sysid);
  
  return getCount(sysid);
}
// change priority
int
sys_changePriority(void)
{
  int pro;
  argint(0,&pro);
  return changePriority(pro);
}
// change policy
int
sys_changePolicy(void)
{
  int num;
  argint(0,&num);
  
  return changePolicy(num);
}

int
sys_waitForChild(void){
  // struct timeVariables tv ={0,0,0,0,0};
  struct timeVariables *tv1;
  argptr(0,(void*)&tv1,sizeof(*tv1));
  return waitForChild(tv1);
}
