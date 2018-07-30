
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

TEST(VLANCONFIG,AddVlan1)
{
	int vlan_id = 1;
	ASSERT_GT(vlan_id,0);

        FILE *stream = NULL;
        char rbuf[4096];
        char cbuf[1024];
       
	sprintf(cbuf,"sudo config vlan add %d 2>&1",vlan_id);
        stream = popen(cbuf,"r");
        fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	sprintf(cbuf,"sudo config vlan member add %d Ethernet2 2>&1",vlan_id);
	stream = popen(cbuf,"r");
	fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	sprintf(cbuf,"show vlan config|grep Vlan%d|awk -F' ' '{print $2}'",vlan_id);
	stream = popen(cbuf,"r");
	memset(rbuf,0,sizeof(rbuf));
	fread(rbuf,sizeof(char),sizeof(rbuf),stream);

	char *pEnd = NULL;
	int val = -1;
	char *p = rbuf;

	while(1){
	val = strtol(p,&pEnd,10);
	if(val == vlan_id){
	break;
	}
	if(val == 0 && pEnd==p){
	ASSERT_FALSE(1==1);
	break;
	}
	memset(cbuf,0,sizeof(cbuf));
	sprintf(cbuf,"%d\n",val);
	p += strlen(cbuf);	
	}
	//sprintf(cbuf,"%d\n",vlan_id);
	//ASSERT_STREQ(cbuf,rbuf);
}

