//Program to send message to a message queue
#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 256
using namespace std;
struct mesg_buffer {
	long mesg_type;
	char mesg_text[MAX];
}mesg;

int main() {
	key_t key;
	int msgid;

	key = ftok("keyfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	write(1,"Enter Message to Store: ", 25);
	read(0,mesg.mesg_text,MAX);
	mesg.mesg_type = 1;
	msgsnd(msgid,&mesg,sizeof(mesg),0);
	cout << "Data Sent to Queue: " << mesg.mesg_text << endl;
}

