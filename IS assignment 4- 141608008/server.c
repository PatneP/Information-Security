// Server side

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8081
char buffer1[1024] = {0}; 
char buffer2[1024] = {0}; 

void cipher(int x){
	int i = 0, n;
	char *p;
	char tmp;

	if(x == 1)
		p = buffer1;
	else
		p = buffer2;
	
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
	while(i < n/2){
		tmp = p[n-1-i];
		p[n-1-i] = p[i];
		p[i] = tmp;
		i++;
	}
}


int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char un[1024] = "abcde"; 
    char pwd[1024] = "xyz123"; 
    char success[1024] = "Logged in successfully"; 
    char failure[1024] = ""; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    valread = read( new_socket , buffer1, 1024); 
    printf("cipher username: %s\n", buffer1); 
	cipher(1);
    printf("username: %s\n", buffer1); 
    
    valread = read( new_socket , buffer2, 1024);
    printf("cipher pwd: %s\n", buffer2); 
	cipher(2);
    printf("pwd: %s\n", buffer2); 

	if((strcmp(un, buffer1) == 0) && (strcmp(pwd, buffer2) == 0)){
		send(new_socket , success , strlen(success) , 0 ); 
	}
	else{
		send(new_socket , failure , strlen(failure) , 0 ); 
	}
    printf("Response sent\n"); 

    return 0; 
} 

