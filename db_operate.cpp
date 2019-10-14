#include<iostream>
#include <string>
#include <cstdlib>
// #include<string>
#include<mysql++/mysql++.h>
using namespace std;


#define MYSQL_USER "root1"
#define MYSQL_PASSWD "123456"
#define MYSQL_PORT 3306


#define CMD_CREATE_USER_TABLE "CREATE TABLE USER ("\
	                     "user_id INT NOT NULL AUTO_INCREMENT,"\
			     "uname VARCHAR(100) NOT NULL,"\
			     "pwd VARCHAR(100) NOT NULL,"\
			     "PRIMARY KEY(user_id))"

bool judgeConnectStatus(mysqlpp::Connection con, char* db_name, char* db_host, char* username, char* password, unsigned int port);
void createTable(string cmd, char* username, char* password, unsigned int port);

bool judgeConnectStatus(mysqlpp::Connection con, char* db_name, char* db_host, char* username, char* password, unsigned int port)
{
	//mysqlpp::Connection con(false);
	//con.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	if(!con.connect(db_name, db_host, username, password, port))
	{
		char* statusMessageFail;
	       	sprintf(statusMessageFail, "connect database:%s with user %s fail! Please check parameters.", db_name, username);
		cout << statusMessageFail << endl;
	        return false;
	}
        else
	{
		char* statusMessageSuccess;
	       	sprintf(statusMessageSuccess, "connect database:%s with user %s success!", db_name, username);
		cout << statusMessageSuccess << endl;
		return true;
	}
}

void createTable(string cmd, char* username, char* password, unsigned int port)
{
	mysqlpp::Connection con(false);
        con.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	char* db_name = (char*)"iwen";
	char* db_host = (char*)"localhost";
	cout << "Here" << endl;
	if(judgeConnectStatus(con, db_name, db_host, username, password, port)==true)
        {
	    cout << "create table failed!"<< endl;
	}
	else
	{
	    cout << "create table success!" << endl;
	    mysqlpp::Query query=con.query(cmd);
	}

}


int main()
{
	
	createTable(CMD_CREATE_USER_TABLE, (char*)MYSQL_USER, (char*)MYSQL_PASSWD, MYSQL_PORT);

}

