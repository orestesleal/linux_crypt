#include <stdio.h>
#include <unistd.h>
#include <crypt.h>
#include <stdlib.h>

/*
 * Orestes Leal Rodriguez, 2018
 */

int main (int argc, char *argv[])
{
   if (argc < 2)  {
      fprintf(stderr, "not enough arguments..\n");
      return 1;
   }

   /*
       salt to be used, use the Secure Hash Algorith 512bit with id=6
       and salt=A0  -> [a-zA-Z0-9]
   */
   const char salt[16] = "$6$A0$encrypted";   
  
   /*  get the password pointer from the first argument  */
   char *k = argv[1];

   const char *key = k;

   char *m;     /* pointer to the allocated memory address */

   if ((m = malloc(128)) == NULL) {
      fprintf(stderr, "malloc(3) failed\n");
      return 1;
   }
   
   if ( (m = crypt (key, salt)) == NULL) {
      fprintf(stderr, "crypt(3) failed\n");
      return 1;
   }

   printf("%s\n", m);


   return 0;
}
