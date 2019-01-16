#include <stdio.h>
#include <stdlib.h>
int _gcd(int a, int b){
        if (a == 0 || b == 0) 
            return 0;
        if (a == b) 
            return a; 
        if (a > b) 
            return _gcd(a-b, b); 
        return _gcd(a, b-a); 
}
int main(){
	FILE *fread, *fwrite;
	char efilename[20]={};
	char dfilename[20]={};
	int a_inv = 0;
	int flag = 0;
	int a,b, op;
	char ch;
	printf("Enter cipher key A and B:");
	scanf("%d", &a);
	scanf("%d", &b);
	if(_gcd(a,b) != 1){
		printf("Inpropriate A value. Not a coprime of 26");
		return 0;
	}
	printf("\nInput filename :");
	scanf("%s",efilename);
	printf("\nOutput filename :");
	scanf("%s",dfilename);
	if(!fopen(efilename, "r")){
		printf("File doesn't exists.\n");
		return 0;
	}
	printf("0-Enc\n1-Dec\t");
	scanf("%d", &op);
	fread = fopen(efilename, "r");
	fwrite = fopen(dfilename, "w");
	printf("Result stored in outputfile.\n");
  	while( (ch = getc(fread)) != EOF ) {
		switch(op){
		case 0:	
			if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
				putc((char)((((a * (ch - 'A'))+b) % 26) + 'A'), fwrite);
			}
			else if(ch == 10){
					break;
			}
			else{
				putc(ch, fwrite);
			}
			break;
		case 1:
		for (int i = 0; i < 26; i++){
			flag = (a * i) % 26;
			if (flag == 1)
			{ 
				a_inv = i;
			}
		}
		if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
				putc((char) (((a_inv * ((ch+'A' - b)) % 26)) + 'A'), fwrite);
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
