#include<stdio.h>
#include<math.h>
 
int encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
 
void encryption();    //encrypts the message
void decryption();    //decrypts the message
void getKeyMessage();    //gets key and message from user
void inverse();        //finds inverse of key matrix
int determinant();
void cofactor(float num[3][3], float f);
void transpose(float num[3][3], float fac[3][3], float r);
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
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
    
    printf("\nDecrypted string is: ");
    for(i = 0; i < 3; i++)
        printf("%c", (char)(decrypt[i][0] % 26) +97);
    
    printf("\n");
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
	float d;
    /*int i, j, k;
    float p, q;
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        } 
	}  
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];
                
            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++){
		printf(" -%d-%d- ", b[i][j],c[i][j]);
            b[i][j] = b[i][j] / c[i][i];
	
	}
    
    printf("\n\nInverse Matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%d ", b[i][j]);
        
        printf("\n");
    }*/
	  d = determinant(c, 3);

  if (d == 0)

   printf("\nInverse of Entered Matrix is not possible\n");

  else

   cofactor(c, 3);
}

int determinant()

{

	int det = 0, i, j = 1, k = 2;
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
  /*float s = 1, det = 0, b[25][25];

  int i, j, m, n, c;

  if (k == 1)

    {

     return (a[0][0]);

    }

  else

    {

     det = 0;

     for (c = 0; c < k; c++)

       {

        m = 0;

        n = 0;

        for (i = 0;i < k; i++)

          {

            for (j = 0 ;j < k; j++)

              {

                b[i][j] = 0;

                if (i != 0 && j != c)

                 {

                   b[m][n] = a[i][j];

                   if (n < (k - 2))

                    n++;

                   else

                    {

                     n = 0;

                     m++;

                     }

                   }

               }

             }

          det = det + s * (a[0][c] * determinant(b, k - 1));

          s = -1 * s;

          }

    }

 

    return (det);*/

}

 

void cofactor(float num[3][3], float f)

{

 float b[25][25], fac[25][25];

 int p, q, m, n, i, j;

 for (q = 0;q < f; q++)

 {

   for (p = 0;p < f; p++)

    {

     m = 0;

     n = 0;

     for (i = 0;i < f; i++)

     {

       for (j = 0;j < f; j++)

        {

          if (i != q && j != p)

          {

            b[m][n] = num[i][j];

            if (n < (f - 2))

             n++;

            else

             {

               n = 0;

               m++;

               }

            }

        }

      }

      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);

    }

  }

  transpose(num, fac, f);

}

/*Finding transpose of matrix*/ 

void transpose(float num[3][3], float fac[3][3], float r)

{

  int i, j;

  float b[25][25], inverse[25][25], d;

 

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

         b[i][j] = fac[j][i];

        }

    }

  d = determinant(num, r);

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

        inverse[i][j] = b[i][j] / d;

        }

    }

   printf("\n\n\nThe inverse of matrix is : \n");

 

   for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

         printf("\t%f", inverse[i][j]);

        }

    printf("\n");

     }

}
