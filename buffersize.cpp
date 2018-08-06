
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

TEST(BUFFERSIZE,buffersize1)
{
        FILE *stream = NULL;
        char rbuf[4096];
        char cbuf[1024];
	memset(rbuf,0,4096);
	sprintf(cbuf,"show processes cpu|grep 'KiB Mem'|awk -F',' '{printf $1}'|awk -F' ' '{print $3}' 2>&1");
        stream = popen(cbuf,"r");
	memset(rbuf,0,4096);
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);
	printf("buffer size:%s",rbuf);
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
