#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fread, *fwrite;
	char efilename[20]={};
	char dfilename[20]={};
	int i, key, op;
	char ch;
	printf("\nEnter input file name :");
	scanf("%s",efilename);
	printf("\nEnter output file name :");
	scanf("%s",dfilename);
	if(!fopen(efilename, "r")){
		printf("File doesn't exists.\n");
		return 0;
	}
	printf("\nEnter key: ");
   	scanf("%d", &key);
	printf("0 for Encryption\n1 for Decryption\t");
	scanf("%d", &op);
	fread = fopen(efilename, "r");
	fwrite = fopen(dfilename, "w");
	printf("Result is in output file.\n");
  	while( (ch = getc(fread)) != EOF ) {
		switch(op){
		case 0:	
			if(ch >= 65 && ch <= 90){
				ch += key;
				if(ch > 'Z'){
                			ch = ch - 'Z' + 'A' - 1;
            			}
				putc(ch, fwrite);
			}
			else if(ch >= 97 && ch <= 122){
				ch += key;
				if(ch > 'z'){
					ch = ch - 'z' + 'a' - 1;
				}
				putc(ch, fwrite);
			}
			else if(ch == 10){
				break;
			}
			else{
				putc(ch, fwrite);
			}
			break;
		case 1:
			if(ch >= 65 && ch <= 90){
				ch -= key;
				if(ch < 'A'){
                			ch = ch + 'Z' - 'A' + 1;
            			}
				putc(ch, fwrite);
			}
			else if(ch >= 97 && ch <= 122){
				ch -= key;
				if(ch < 'a'){
					ch = ch + 'z' - 'a' + 1;
				}
				putc(ch, fwrite);
			}
			else if(ch == 10){
				break;
			}
			else{
				putc(ch, fwrite);
			}
		break;
  	}
	
	}
	fclose(fread);
  	fclose(fwrite);
	return 0;
}
