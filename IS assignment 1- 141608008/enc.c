

#include <stdio.h> 
#include <stdlib.h> // For exit() 
  
int main() 
{ 
    FILE *fptr1, *fptr2; 
    char filename[100], c; 
	int i=33,j=0,ch,e=126;
    //char rev[92] = " #$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	char rev[92]="~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#";

	//char rev[92]={'~','}','|','{','z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','`','_','^',']','\','[','Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','J','I','H','G','F','E','D','C','A','B','@','?','>','=','<',';',':','9','8','7','6','5','4','3','2','1','0','/',',','.','-','+','*',')','(','&','%','$','#'};
	rev[91]='\t';

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
    //c = fgetc(fptr1); 
   	/*printf("%c",c);
ch=(int)c;
printf("%d",ch);
printf("%c",rev[91]);

printf("%c",rev[1]);*/
    while ((c=fgetc(fptr1)) != EOF) 
    { 
	ch=c;
	//printf("\n-ch = %d-\n", ch);
	if(ch == 32){
		fputc(' ', fptr2); 
		continue;
	}
	if(ch >= 0 && ch <=31){
		continue;
	}	
	j=ch-i;
	//printf("-j = %d-", j);
	c=rev[j];  
        fputc(c, fptr2); 
    } 
  
    printf("\nContents copied to %s", filename); 
  
    fclose(fptr1); 
    fclose(fptr2); 
    return 0; 
}
