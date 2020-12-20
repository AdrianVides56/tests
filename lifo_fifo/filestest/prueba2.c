#include <stdio.h>

int main () {
   FILE *fp;
   char str[60];

   /* opening file for reading */
   fp = fopen("../monty.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
}
   printf("%s\n", str);
   while(str != NULL)
   {
	
   	if(fgets(str, 60, fp) != NULL ) 
	{
		printf("%s", str);
   	}
   }
   fclose(fp);
   
   return(0);
}
