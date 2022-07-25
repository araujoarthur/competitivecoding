#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite
const int least_chars = 16; // " likes this\0"

int digitCount(int a)
{
    int counter = 0;
    while(a != 0)
    {
        counter++;
        a = a/10;
    }

    return counter;
}

char *likes(size_t n, const char *const names[n]) {
  int required_chars = least_chars;
  char* _likes = NULL;
  printf("%lu\n", n);
  if (n == 0L)
  {
    required_chars += 6; //"no one"
    _likes = malloc(required_chars*sizeof(char));
    snprintf(_likes, required_chars, "no one likes this");
  }
  else if (n == 1L)
  {
    //"<[NAME]> likes this"
    required_chars += strlen(names[0]);
    _likes = malloc(sizeof(char)*required_chars);
    snprintf(_likes, required_chars, "%s likes this", names[0]);
  }
  else if (n == 2L)
  {
    //"<[NAME] ><and>< [NAME] like<-s> this"
    required_chars += strlen(names[0]) + strlen(names[1]) + 4;
    _likes = malloc(sizeof(char)*required_chars);
    snprintf(_likes, required_chars, "%s and %s like this", names[0], names[1]);
  }
  else if (n == 3L)
  {
    //"<[NAME],>< [NAME] ><and>< [NAME]> like<-s> this"
    required_chars += strlen(names[0]) + strlen(names[1]) + strlen(names[2]) + 6;
    _likes = malloc(sizeof(char)*required_chars);
    snprintf(_likes, required_chars, "%s, %s and %s like this", names[0], names[1], names[2]);
  }
  else if (n >= 4L)
  {
    //"<[NAME],>< [NAME] ><and>< [NUMBER]>< others> like<-s> this"
    required_chars += strlen(names[0]) + strlen(names[1]) + 15 + digitCount(n-2);
    _likes = malloc(sizeof(char)*required_chars);
    snprintf(_likes, required_chars, "%s, %s and %lu others like this", names[0], names[1], n-2);

  }
  
   return _likes;
}