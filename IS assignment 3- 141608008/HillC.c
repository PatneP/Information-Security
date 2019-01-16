#include<stdio.h>
#include<math.h>
 
int encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
 
void encryption();    //encrypts the message
void decryption();    //decrypts the message
void getKeyMessage();    //gets key and message from user
void inverse();        //finds inverse of key matrix
void main() {
    getKeyMessage();
    encryption();
    decryption();
}
 
void encryption() {
    int i, j, k;
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
    
    printf("\nEncrypted string is: ");
    for(i = 0; i < 3; i++){
        printf("%c", (char)(encrypt[i][0] % 26) + 97);
 	}
}
 
void decryption() {
    int i, j, k;
    
    inverse();
    
    /*for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
    
    printf("\nDecrypted string is: ");
    for(i = 0; i < 3; i++)
        printf("%c", (char)(decrypt[i][0] % 26) +97);
    
    printf("\n");*/
}
 
void getKeyMessage() {
    int i, j;
    char msg[3];
 
    printf("Enter 3x3 matrix for key (It should be inversible):\n");
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            c[i][j] = a[i][j];
        }
    
    printf("\nEnter a 3 letter string: ");
    scanf("%s", msg);
    
    for(i = 0; i < 3; i++){
        mes[i][0] = msg[i] - 97;
	}
}
 
void inverse() {
	int det = 0, i, j = 1, k = 2, min[3][3], m, n;
	for(i = 0;i<3;i++){
		if(i == 0)
			det += c[0][i] * (c[1][j] * c[2][k] - c[2][j] * c[1][k]);
		if(i==1){
			j--;
			det -= c[0][i] * (c[1][j] * c[2][k] - c[2][j] * c[1][k]);
		}
		if(i == 2){
			k--;
			det += c[0][i] * (c[1][j] * c[2][k] - c[2][j] * c[1][k]);
		}
	}
	printf("\ndet : %d", det);

	i = 0, m = 1, n = 2;
	for(j = 0; j<3; j++){
			if(j == 1)
				m--;
			if(j == 2)
				n--;
			min[i][j] = c[m][m] * c[n][n] - c[m][n] * c[n][m];
		}
	i = 1, m = 0, n = 2;
	for(j = 0; j<3; j++){
		if(j == 0)
			min[i][j] = c[m][m+1] * c[n][n] - c[m][n] * c[n][n-1];
		if(j == 2)
			min[i][j] = c[m][m]* c[n][n-1] - c[m][m+1] * c[n][m];
		min[i][j] = c[m][m] * c[n][n] - c[m][n] * c[n][m];
	}		
	i = 2, m = 1, n = 2;
	for(j = 0; j<3; j++){
		if(j == 0)
			min[i][j] = c[m-1][m] * c[m][n] - c[m-1][n] * c[m][m];
		if(j == 2){
			m = 0;
			min[i][j] = c[m][m]* c[m+1][n] - c[m+1][m] * c[m][n];
		}
		else{
			m=0, n=1;
			min[i][j] = c[m][m] * c[n][n] - c[m][n] * c[n][m];
		}
	}	
	for(i = 0; i<3; i++){
		printf("\n");
		for(j = 0; j<3; j++){
			printf("%d\t", min[i][j]);
		}
		
	}	
}

