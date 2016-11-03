/* Assignment1 Sample Program
 * by Alec Pierce, section 2
 *
 * This program takes two numbers, chosen by the user, and divides them. It
 * then returns the answer as well as the remainder. If the user divides by
 * 0 or exits the program with ^C, the program handles and exits properly.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int count;

void counter(int sig) {

  printf("\n%d successful operations.\n", count);
  exit(0);

}

void handler(int sig) {

  printf("Divide by 0 operation was attempted, program will now exit.\n");
  exit(0);

}

int main(int argc, char** argv) {

  /* Stores string rep of user-provided ints.*/
  char strOne[80];
  char strTwo[80];

  /* Stores itn rep of user-provided ints.*/
  int x;
  int y;

  struct sigaction action;

  printf("Enter ^C to exit.\n");

  
  while(1) {

    /*Gets first user-provided int.*/
    printf("Enter first integer: ");
    x = atoi(fgets(strOne, 10, stdin));

    /*Gets second user-provided int.*/
    printf("Enter second integer: ");
    y = atoi(fgets(strTwo, 10, stdin));

    /*Divides and prints the answer and remainder.*/
    printf("%d / %d is %d with a remainder of %d\n", x, y, x/y, x%y);

    /*Handles divide by 0.*/
    action.sa_handler = handler;
    sigaction(SIGFPE, &action, NULL);

    /*Handles closing the program.*/
    action.sa_handler = counter;
    sigaction(SIGINT, &action, NULL);

    /*Keeps track of successful equations.*/
    count++;

  }

  return(0);
}