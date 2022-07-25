#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// dtr's suggestion on hackmud's discord community. MSGID 1000959883627212920


char *likes(size_t n, const char *const names[n]) {
  char* _likes = NULL;

  if (n == 0L)
  {
    asprintf(&_likes, "no one likes this");
  }
  else if (n == 1L)
  {
    //"<[NAME]> likes this"
    asprintf(&_likes, "%s likes this", names[0]);
  }
  else if (n == 2L)
  {
    //"<[NAME] ><and>< [NAME] like<-s> this"
    asprintf(&_likes, "%s and %s like this", names[0], names[1]);
  }
  else if (n == 3L)
  {
    //"<[NAME],>< [NAME] ><and>< [NAME]> like<-s> this"
    asprintf(&_likes, "%s, %s and %s like this", names[0], names[1], names[2]);
  }
  else if (n >= 4L)
  {
    //"<[NAME],>< [NAME] ><and>< [NUMBER]>< others> like<-s> this"
    asprintf(&_likes, "%s, %s and %lu others like this", names[0], names[1], n-2);

  }
  
   return _likes;
}