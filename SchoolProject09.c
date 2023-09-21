#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

   //variables
   FILE* file = NULL;
   char title[50];
   char header1[50];
   char header2[50];
   char input[50];
   char* tempString = NULL;
   char* header = NULL;
   char* number = NULL;

   if((file = fopen("myfile.txt", "w")) == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1;
   } else {

      //title
      printf("Enter a title for the data:\n");
      fgets(title, 50, stdin);
      printf("You entered: %s\n", title);

      //header 1
      printf("Enter the column 1 header:\n");
      fgets(header1, 50, stdin);
      printf("You entered: %s\n", header1);

      //header 2
      printf("Enter the column 2 header:\n");
      fgets(header2, 50, stdin);
      printf("You entered: %s\n", header2);

      //loop starter
      printf("Enter a data point (-1 to stop input):\n");
      fgets(input, 50, stdin);

      //variables for input
      int len;
      int orig;
      int i;
      int j;

      //input loop
      while(strcmp(input, "-1") != 0) {
         if(strchr(&input, ',') == NULL) {
            printf("Error: No comma in string.\n\nEnter a data point (-1 to stop input):\n");
            fgets(input, 50, stdin);
            continue;
         } else {
            tempString = strchr(input, ',');
            tempString = strchr(tempString, ' ');
            if(strchr(tempString, ',') != NULL) {
               printf("Error: Too many commas in input.\n\nEnter a data point (-1 to stop input):\n");
               fgets(input, 50, stdin);
               continue;
            } else {
               bool a = true;
               for(int i = 1; i < strlen(tempString) - 1; i++) {
                  if(isdigit(tempString[i]) == 0) {
                     a = false;
                  }
               }
               if(a == false) {
                  printf("Error: Comma not followed by an integer.\n\nEnter a data point (-1 to stop input):\n");
                  fgets(input, 50, stdin);
                  continue;
               } else {
                  header = (char*)malloc(sizeof(char)*30);
                  number = (char*)malloc(sizeof(char)*30);
                  orig = strlen(input) - 1;
                  len = strlen(tempString = strchr(input, ',')) - 1;
                  for(i = 0; i < orig-len; i++) {
                     header[i] = input[i];
                  }
                  header[i+1] = "\0";
                  for(i = orig-len+2, j = 0; i < orig; i++, j++) {
                     number[j] = input[i];
                  }
                  number[j+1] = "\0";
                  fprintf(file, "%s, %s\n", header, number);
                  // fprintf(file, "");
                  printf("Data string: %s\n", header);
                  printf("Data integer: %s\n", number);
                  free(header);
                  free(number);
                  printf("\nEnter a data point (-1 to stop input):\n");
                  fgets(input, 50, stdin);
               }
            }
         }
      }//end while
      fclose(file);

      //chart
      if((file = fopen("myfile.txt", "r")) == NULL) {
         printf("Could not open file myfile.txt.\n");
         return -1;
      } else {
         printf("\n%33s", title);
         printf("%-20.*s|%23.*s\n", strlen(header1) - 1, &header1, strlen(header2) - 1, &header2);
         printf("--------------------------------------------\n");
         char temp[50];
         fgets(temp, 50, file);
         while(!feof(file)) {
            orig = strlen(temp) - 1;
            len = strlen(tempString = strchr(temp, ',')) - 1;
            header = (char*)malloc(sizeof(char)*(orig-len));
            number = (char*)malloc(sizeof(char)*(len));
            for(i = 0; i < (orig-len); i++) {
               header[i] = temp[i];
            }
            header[orig-len] = "\0";
            for(i = orig-len+2, j = 0; i < orig; i++, j++) {
               number[j] = temp[i];
            }
            number[len] = "\0";
            printf("%-20.*s|%23.*s\n", strlen(header)-1, header, strlen(number), number);
            fgets(temp, 50, file);
         }//end while
      }
      fclose(file);

      printf("\n");
      //histogram
      if((file = fopen("myfile.txt", "r")) == NULL) {
         printf("Could not open file myfile.txt.\n");
         return -1;
      } else {
         int tempSum = 0;
         char temp[50];
         fgets(temp, 50, file);
         while(!feof(file)) {
            orig = strlen(temp) - 1;
            len = strlen(tempString = strchr(temp, ',')) - 1;
            header = (char*)malloc(sizeof(char)*(orig-len));
            number = (char*)malloc(sizeof(char)*(len));
            for(i = 0; i < (orig-len); i++) {
               header[i] = temp[i];
            }
            header[orig-len] = "\0";
            for(i = orig-len+2, j = 0; i < orig; i++, j++) {
               number[j] = temp[i];
            }
            number[len] = "\0";
            tempSum = atoi(number);
            printf("%20.*s ", strlen(header)-1,header);
            for(i=0;i<tempSum;i++) {
               printf("*");
            }
            printf("\n");
            free(number);
            free(header);
            fgets(temp, 50, file);
         }//end while-
      }
      fclose(file);
   }
   return 0;
}
