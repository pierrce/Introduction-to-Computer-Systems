/* Assignment3 Alarm Program
 * by Alec Pierce, section 2
 *
 * Activates an alarm and then prints the time/date the alarm
 * went off. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {

  /*Creates a random number to for pause time.*/
  srandom(time(NULL));
  int r = random();
  r = r % 10;
  r = r*10000000;
  
  /*Keeps track of how long program pauses before alarm is caught.*/
  while(r != 0){
    r = r-1;
    if(r%10000000 == 0){
      printf(".");
    }
  }
  printf("\n");	

  /*Prints the current time/date alarm went off.*/
  time_t curtime;
  time(&curtime);
  printf("current time is %s", ctime(&curtime));

  /*Creates next alarm*/
  alarm(1);

}

int main(int argc, char** argv) {

  struct sigaction action;
  action.sa_handler = handler;

  /*Creates and catches alarm.*/
  sigaction(SIGALRM, &action, NULL);
  alarm(1);

  printf("Enter ^C to end the program:\n");

  while(1){

  }

  return(0);
}
