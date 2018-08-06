
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

TEST(MTUDEFAULT,mtudefault1)
{
	
        char rbuf[4096];
        char cbuf[1024];
	memset(rbuf,0,4096);
	sprintf(cbuf,"show interfaces summary|grep -A 3 '^Vlan'|grep MTU:|awk -F':' '{print $2}'|awk -F' ' '{print$1}'|head -n 1 2>&1");
        FILE *stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	printf("ip mtu:%s:",rbuf);

	sprintf(cbuf,"show interfaces summary|grep -A 3 '^Ethernet'|grep MTU:|awk -F':' '{print $2}'|awk -F' ' '{print$1}'|head -n 1 2>&1");
	stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
	fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	printf("port mtu:%s:",rbuf);

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
