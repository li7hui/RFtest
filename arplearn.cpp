
#include <iostream>
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

TEST(ARPLEARN,ArpLearn1)
{
	FILE *file = fopen("testbed.csv","r");
        FILE *stream = NULL;
        char rbuf[4096];
        char cbuf[1024];
	memset(rbuf,0,4096);
	fread(rbuf,4096,1,file);
	char *ipstr = strstr(rbuf,"server,");
	char *ip = NULL;
	if(ipstr != NULL){
	ipstr += strlen("server,");
	ip = ipstr;
	while(*ipstr != '\n')
		ipstr++;
	*ipstr = '\0';
	}
	sprintf(cbuf,"sshpass -p roothello ssh root@%s ifconfig |grep ether|awk -F' ' '{print $2}'|line -n 1 2>&1",ip);
        stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
        int len = fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	for(int i = 0; i<len; i++){
	rbuf[i] = toupper(rbuf[i]); 
	}
	char mac[128];
	sprintf(mac,"%s",rbuf);
	//printf("%s",mac);
	sprintf(cbuf,"show mac");
	stream = popen(cbuf,"r");
        memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	char *p = strstr(rbuf,mac);
	printf("1:%s:",rbuf);
	printf("2:%s:",mac);
	if(p == NULL){
	ASSERT_FALSE(1==1);
	}
#if 0
	char *p = strstr(rbuf,"Platform");
	if(p == NULL){
	ASSERT_FALSE(1==1);
	return;
	}
	p[strlen("Platform")] = 0;
	sprintf(cbuf,"Platform");
	ASSERT_STREQ(p,cbuf);
#endif
}
