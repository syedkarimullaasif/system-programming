//This program creates a client
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<iostream>

int main(int argc,char* argv[]){
        /*if(argc != 2){
                std::cout << "usage: ./tcp_client <PORTNO>" << std::endl;
                return -1;
        }*/
        const char* port = "8027";
        int portno = atoi(port);
        //creates a socket
        int socketid = socket(AF_INET,SOCK_STREAM,0);
        if(socketid==-1){
                std::cout<<"Socket creation failed"<<std::endl;
                return -1;
        }
        std::cout << "Socket created successfully" << std::endl;
                               
     	//creates  server address to connect
        struct sockaddr_in serveraddr;

        //clears  structure
        memset(&serveraddr,0,sizeof(serveraddr));
 
        //sets  server address
        serveraddr.sin_family=AF_INET;
        serveraddr.sin_port=htons(portno);
        serveraddr.sin_addr.s_addr= inet_addr("127.0.0.1");

        //connects to server
        int connect_status = connect(socketid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
        if(connect_status==-1){
                std::cout<<"Connection failed"<<std::endl;
                return -1;
        }
        std::cout << "Connection successful" << std::endl;
        //sends message to server
        std::cout << "Enter the message to be sent to the server : ";
        const char* message;
        std::string m;
        getline(std::cin,m);
        message = m.c_str();
        ssize_t send_status = send(socketid,message,strlen(message),0);
        if(send_status==-1){
                std::cout<<"Message sending failed"<<std::endl;
                return -1;
        }
        std::cout << "Message sent successfully" << std::endl;

        while(1){

        //create a buffer to store the message
        char buffer[256];
        //clears  buffer
        memset(buffer,0,sizeof(buffer));

        //receives  message
        int len=sizeof(serveraddr);
        ssize_t receive_status = recv(socketid,buffer,256,0);
        if(receive_status==-1){
                std::cout<<"Message receiving failed"<<std::endl;
                return -1;
        }
        else if(receive_status==0){
                std::cout<<"Server closed the connection"<<std::endl;
                break;
        }
        std::cout << "Message received successfully" << std::endl;

        //prints message
        std::cout<<"Message received : "<<buffer<<std::endl;

        if(strcmp(buffer,"bye")==0)
        break;

        //send message to the server
        std::cout << "Enter the message to be sent to the server : ";
        const char* message;
        std::string m;
        getline(std::cin,m);
        message = m.c_str();
        ssize_t send_status = send(socketid,message,strlen(message),0);
        if(send_status==-1){
                std::cout<<"Message sending failed"<<std::endl;
                return -1;
        }
        std::cout << "Message sent successfully" << std::endl;
        if(strcmp(message,"bye")==0)
        break;
        }
        //close  socket
        close(socketid);
}
