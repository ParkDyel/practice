#include <stdio.h>
#include <stdlib.h>

int main( void)
{
   int   *ptr_int1;
   int   *ptr_int2;
   int    ndx;

   ptr_int1  = (int *)malloc( 50 *sizeof( int));
   ptr_int2  = (int *)calloc( 50, sizeof( int));

   for ( ndx= 0; ndx < 5; ndx++)
   {
      ptr_int1[ndx]   = 2007 +ndx;
      ptr_int2[ndx]   = 2007 +ndx;
   }

   for ( ndx= 0; ndx < 5; ndx++)
   {
      printf( "%d %d\n", ptr_int1[ndx], ptr_int2[ndx]);
   }

   free( ptr_int1);
   free( ptr_int2);

  for ( ndx= 0; ndx < 5; ndx++)
   {
      printf( "%d %d\n", ptr_int1[ndx], ptr_int2[ndx]);
   }

   ptr_int1  = NULL;
   ptr_int2  = NULL;

   return 0;
}