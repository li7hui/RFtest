
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

TEST(INTERFACESTARTUP,interfacestartup1)
{
        FILE *file = fopen("testbed.csv","r");
        char rbuf[4096];
        char cbuf[1024];
	memset(rbuf,0,4096);
	fread(rbuf,4096,1,file);
	char *interfacestr = strstr(rbuf,"interfacestartup,Ethernet,");
	char *id = NULL;
	if(interfacestr != NULL){
	interfacestr += strlen("interfacestartup,Ethernet,");
	id = interfacestr;
	while(*interfacestr != '\n')
		interfacestr++;
	*interfacestr = '\0';
	}
	char *pEnd = NULL;
	int num = strtol(id,&pEnd,10);
	//printf("id:%d:\n",num);
	char interfacename[64];
	sprintf(interfacename,"Ethernet%d",num);
	printf("name:%s\n",interfacename);	
	sprintf(cbuf,"sudo config interface startup %s 2>&1",interfacename);
 	FILE *stream = popen(cbuf,"r");

	sprintf(cbuf,"show interface status|grep %s|awk -F' ' '{print $7}'",interfacename);
	stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	printf("rbuf:%s\n",rbuf);
	ASSERT_STREQ(rbuf,"up\n");	
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
