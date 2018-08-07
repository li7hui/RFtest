
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

TEST(LACPSTATE,lacpstate1)
{
        FILE *file = fopen("testbed.csv","r");
        char rbuf[4096];
        char cbuf[1024];
	memset(rbuf,0,4096);
	fread(rbuf,4096,1,file);
	char *lacpstatestr = strstr(rbuf,"lacpstate,PortChannel,");
	char *id = NULL;
	if(lacpstatestr != NULL){
	lacpstatestr += strlen("lacpstate,PortChannel,");
	id = lacpstatestr;
	while(*lacpstatestr != '\n')
		lacpstatestr++;
	*lacpstatestr = '\0';
	}
	char *pEnd = NULL;
	int num = strtol(id,&pEnd,10);
	printf("id:%d:\n",num);
#if 0
	char lacpstatename[64];
	sprintf(lacpstatename,"PortChannel%d",num);
	printf("name:%s\n",lacpstatename);	
	sprintf(cbuf,"sudo config lacpstate shutdown %s 2>&1",interfacename);
 	FILE *stream = popen(cbuf,"r");

	sprintf(cbuf,"show lacpstate status|grep %s|awk -F' ' '{print $7}'",interfacename);
	stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	printf("rbuf:%s\n",rbuf);
	ASSERT_STREQ(rbuf,"down\n");	
#endif
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
	printf("2:%s:",mac);
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
