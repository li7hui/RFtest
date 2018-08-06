
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

TEST(MACFLAPPING,MacPlapping1)
{
        char rbuf[40960];
        char cbuf[1024];
	memset(rbuf,0,4096);
	char *ipstr = strstr(rbuf,"server,");
	char *ip = NULL;

	sprintf(cbuf,"show mac|grep 'Total number of entries'");
        FILE *stream = popen(cbuf,"r");
	memset(rbuf,0,40960);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	char *p = rbuf+strlen("Total number of entries");
	char *pEnd = NULL;
	int num = strtol(p,&pEnd,10);

	sprintf(cbuf,"show mac");
	stream = popen(cbuf,"r");
	fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	for(int s = 0; s<num; s++){
		char mac[128];
		memset(mac,0,128);
		sprintf(cbuf,"show mac|grep [0-9]|head -n 24|tail -n 1|awk -F' ' '{print $3}'");
		stream = popen(cbuf,"r");
		fread(mac,sizeof(char),sizeof(mac),stream);
		printf("id:%d mac:%s:\n",s,mac);
		char *p = strstr(rbuf,mac);
		p+= strlen(mac);
		if(strstr(p,mac)!=NULL)
			ASSERT_FALSE(1==1);
	}
}
