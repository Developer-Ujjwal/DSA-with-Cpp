#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// int lexicographic_sort(char* a, char* b) {
//     char temp[100];
//     if (strcmp(a,b) > 0) {
//                 strcpy(temp,a);
//                 strcpy(a,b);
//                 strcpy(b,temp);
//             }
// }

// int lexicographic_sort_reverse(char* a,char* b) {
// char temp[100];
//     if (strcmp(a,b) < 0) {
//                 strcpy(temp,a);
//                 strcpy(a,b);
//                 strcpy(b,temp);
//             }
// }
void sort_by_number_of_distinct_characters(char* a,char* b) {
    char temp[100];
    int counta[256]={0},countb[256]={0}; 
    int lengtha,lengthb;
    for(int i=0;i!='\0';i++)
    {
        counta[*(a+i)]++;
        countb[*(b+i)]++;
    }
    for(int i=0;i<256;i++)
        {
           if(counta[i]!=0)
           {
               lengtha++;
           } 
            if(countb[i]!=0)
           {
               lengthb++;
           }
        }
    if(lengtha>lengthb)
    {
         strcpy(temp,a);
           strcpy(a,b);
                strcpy(b,temp);
    }
    else if(lengtha==lengthb)
    {
        if (strcmp(a,b) > 0) {
                strcpy(temp,a);
                strcpy(a,b);
                strcpy(b,temp);
            }
    }
}

// int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
// }

// int sort_by_length(const char* a, const char* b) {

// }

void string_sort(char** arr,const int len,int (*cmp_func)(char* a, char* b)){
for(int i=0;i<len;i++)
{
    for(int j=i+1;j<len;j++)
    {
        cmp_func(arr[i],arr[j]);
    }
}
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}