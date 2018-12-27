#ifndef LINUX_GETCH_H
#define LINUX_GETCH_H

#include <termios.h>
#include <stdio.h>

static struct termios old, newOne;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  newOne = old; /* make new settings same as old settings */
  newOne.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      newOne.c_lflag |= ECHO; /* set echo mode */
  } else {
      newOne.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &newOne); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

#endif