
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

TEST(STPSTATE,stpstate1)
{
        char rbuf[4096];
        char cbuf[1024];
	memset(rbuf,0,4096);
	sprintf(cbuf,"brctl show|grep -A 1 'STP enabled'|tail -n 1|awk -F' ' '{print $3}' ");
        FILE *stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	printf("stp status:%s:",rbuf);

#if 0
	char mac[128];
	sprintf(mac,"%s",rbuf);
	//printf("%s",mac);
	sprintf(cbuf,"show mac");
	stream = popen(cbuf,"r");
        memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	char *p = strstr(rbuf,mac);
	printf("1:%s:",rbuf);
	if(p == NULL){
	ASSERT_FALSE(1==1);
	}
#endif
}
