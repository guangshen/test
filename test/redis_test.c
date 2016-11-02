/* ************************************************************************
 *       Filename:  redis_test.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2016年11月02日 16时19分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "make_log.h"
#include "redis_op.h"

#define MODULE 	"test"
#define PROC 	"redis_test"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("====== please enter ./a.out key ======\n");
		exit(1);
	}
	
	int 			ret = 0;
	char 			value[1024] = { 0 };
	redisContext* 	redis_conn = NULL;
	
	redis_conn = rop_connectdb_nopwd("127.0.0.1", "6379");
	if(NULL == redis_conn)
	{
		LOG(MODULE, PROC, "redis_conn err");
		goto End;
	}
	
	ret = rop_get_string(redis_conn, argv[1], value);
	if(0 != ret)
	{
		LOG(MODULE, PROC, "rop_get_string err");
		goto End;
	}
	
	printf("value:%s\n", value);
		
End:	
	return ret;
}


