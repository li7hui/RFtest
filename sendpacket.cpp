
#include<iostream>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

using namespace std; 
#include<gtest/gtest.h>

TEST(SENDPACKET,SendPacket1)
{

	printf("send packet to Ethernet2\n");

        FILE *stream = NULL;
        char rbuf[4096];
        char cbuf[1024];
       
	sprintf(cbuf,"sudo config interface ip add Ethernet2 30.2.1.1/16 2>&1");
        stream = popen(cbuf,"r");
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	sprintf(cbuf,"sudo iperf -s 2>&1 &");
	stream = popen(cbuf,"r");
	fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	sprintf(cbuf,"iperf -c 30.2.1.1 -t 1");
	stream = popen(cbuf,"r");
	memset(rbuf,0,sizeof(rbuf));
	fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	char *p1 = strstr(rbuf,"GBytes");
	if(p1 == NULL){
	ASSERT_FALSE(1==1);
	return;
	}
	p1 += strlen("GBytes");
	//printf(":%s:\n",p1);
	char *pEnd = NULL;
	double gb = strtod(p1,&pEnd);
	printf("Bandwidth:%.3lf Gbits/sec\n",gb);
	//char *p = strstr(rbuf,"64 bytes from 30.2.1.1: icmp_seq=1 ttl=64");
	//p[strlen("64 bytes from 30.2.1.1: icmp_seq=1 ttl=64")] = 0;
	//sprintf(cbuf,"64 bytes from 30.2.1.1: icmp_seq=1 ttl=64");
	//ASSERT_STREQ(p,cbuf);
}
