#include <stdio.h>
#include <string.h>
#include <iostream>
int main()
{
   int i, j, n;
   char str[25][25], temp[25];
   std::cout << ("How many strings you are going to enter?: ");
   std::cin >> n;

   puts("Enter Strings one by one: ");
   for (i = 0; i <= n; i++)
   {
      gets(str[i]);
   }

   for (i = 0; i <= n; i++)
      for (j = i + 1; j <= n; j++)
      {
         if (strcmp(str[i], str[j]) > 0)
         {
            strcpy(temp, str[i]);
            strcpy(str[i], str[j]);
            strcpy(str[j], temp);
         }
      }
   printf("Order of Sorted Strings:");
   for (i = 0; i <= n; i++)
      puts(str[i]);

   return 0;
}