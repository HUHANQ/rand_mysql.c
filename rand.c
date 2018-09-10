#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	MYSQL mysql;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql,"localhost","root","","rand",0,NULL,0))
	{
		fprintf(stderr,"Failed to database:Error:%s\n",mysql_error(&mysql));
		exit(1);
	}
	mysql_query(&mysql,"set names utf8");

	int i = 0;
	srand(time(NULL));
	i = rand();
	char sql[50];
	sprintf(sql,"select name from rand where id = %d",i%5 + 1);
	if(mysql_query(&mysql,sql))
	{
		fprintf(stderr,"Failed to select :Error:%s\n",mysql_error(&mysql));
	}
	else
	{
		MYSQL_RES* res;
		res = mysql_store_result(&mysql);
		MYSQL_ROW row;
		row = mysql_fetch_row(res);
		printf("%s\n",row[0]);
	}

	return 0;
}
# rand_mysql.c
