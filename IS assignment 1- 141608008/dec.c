

#include <stdio.h> 
#include <stdlib.h> // For exit() 
  
int main() 
{ 
    FILE *fptr1, *fptr2; 
    char filename[100], c; 
	int i=34,j=0,ch,e=126;
    //char rev[92] = "#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	//char rev[92]="~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLJIHGFEDCAB@?>=<;:9876543210/.-,+*)('&%$#";
	char rev[92]=" ~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#";
	rev[0]=' ';
//char p='\\';
	//printf("%c",rev[59]);
//printf("%c",rev[33]);*/
    printf("Enter the filename to open for reading \n"); 
    scanf("%s", filename); 
  
    // Open one file for reading 
    fptr1 = fopen(filename, "r"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
  
    printf("Enter the filename to open for writing \n"); 
    scanf("%s", filename); 
  
    // Open another file for writing 
    fptr2 = fopen(filename, "w"); 
    if (fptr2 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr1); 
   	/*printf("%c",c);
ch=(int)c;
printf("%d",ch);
printf("%c",rev[91]);

printf("%c",rev[1]);*/
    while (c != EOF) 
    { 
	ch=(int)c;	
	if(ch==32)
	{
		fputc(' ',fptr2);
	}
	//j=e-ch;
	j = ch-i;
	j=j+2;
	//printf("\n- %d - \n", j);
	c=rev[j];  
        fputc(c, fptr2); 
        c = fgetc(fptr1); 
 	
	
    } 
  
    printf("\nContents copied to %s", filename); 
  
    fclose(fptr1); 
    fclose(fptr2); 
    return 0; 
}
