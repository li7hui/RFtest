
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

TEST(SHOWMAC,ShowMac1)
{
        FILE *stream = NULL;
        char rbuf[4096];
        char cbuf[1024];
       
	sprintf(cbuf,"show mac 2>&1");
        stream = popen(cbuf,"r");
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	char *p = strstr(rbuf,"MacAddress");
	if(p == NULL){
	ASSERT_FALSE(1==1);
	return;
	}
	//p[strlen("Platform")] = 0;
	//sprintf(cbuf,"Platform");
	//ASSERT_STREQ(p,cbuf);
}
