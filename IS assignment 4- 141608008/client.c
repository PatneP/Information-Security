// Client side 

#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8081
char un[1024] = {0}; 
char pwd[1024] = {0}; 

void cipher(int x){
	int i = 0, n;
	char *p;
	char tmp;

	if(x == 1)
		p = un;
	else
		p = pwd;
	
	n = strlen(p);		
	while(i < n){
		if (p[i] >= 65 && p[i] <= 90){		//capital.....convert to small and inverse among capitals (eg A->z, B->y, ... , Z->a)
			p[i] = ((90 - p[i]) + 65) + 32;
		}
		else if(p[i] >= 97 && p[i] <= 122){		//smalls.....convert to capital and inverse among smalls (eg a->Z, b->Y, ... , z->A)
			p[i] = ((122 - p[i]) + 97) - 32;
		}
		else{
			p[i] = p[i];		//other charasecondTexters......keep as it is
		}	
		i++;
	}

	//now reverse the whole string
	i = 0;
	i = 0;
	while(i < n/2){
		tmp = p[n-1-i];
		p[n-1-i] = p[i];
		p[i] = tmp;
		i++;
	}
}
	

   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char response[1024] = {0}; 

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

	printf("Enter username : ");
	scanf("%s",un);
	cipher(1);
    send(sock , un , strlen(un) , 0 ); 
    printf("Username sent\n"); 

	printf("Enter Password : ");
	scanf("%s",pwd);
	cipher(2);
    send(sock , pwd , strlen(pwd) , 0 ); 
    printf("Password sent\n"); 

    valread = read( sock , response, 1024); 

    
    printf("%s\n", response); 
   
    
    return 0; 
} 

