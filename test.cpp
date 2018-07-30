
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

class GlobalTest:public testing::Environment
{
public:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
};

int Abs(int x)
{
     return x > 0 ? x : -x;
}

TEST(IsAbs,HandlerTrueReturn)
{
    	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";  //ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
    	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";
    	ASSERT_FALSE(Abs(-2) == -2);  //期待结果是false
    	ASSERT_EQ(Abs(1),Abs(-1));
    	ASSERT_NE(Abs(-1),0);
    	ASSERT_LT(Abs(-1),2);
}

int main(int argc, char *argv[]){
	testing::InitGoogleTest(&argc,argv);
	testing::Environment *env = new GlobalTest();
	testing::AddGlobalTestEnvironment(env);
	int ret = RUN_ALL_TESTS();
	return ret;
}
