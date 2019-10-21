#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<mysql++/mysql++.h>
#include<vector>
using namespace std;

#define MYSQL_USER "root"
#define MYSQL_PASSWD "123456"
#define MYSQL_PORT 3306

#define CMD_CREATE_USER_TABLE "CREATE TABLE user ("\
	                     "user_id INT NOT NULL AUTO_INCREMENT,"\
			             "uname VARCHAR(100) NOT NULL,"\
			             "pwd VARCHAR(100) NOT NULL,"\
			             "PRIMARY KEY(user_id));"

bool judgeConnectStatus(mysqlpp::Connection& con, char* db_name, char* db_host, char* username, char* password, unsigned int port);
void createTable(string cmd, char* username, char* password, unsigned int port);
bool queryData(char* username, char* password, unsigned int port, char* db_name, char* db_host, string table_name, vector<string> data);
bool insertData(char* username, char* password, unsigned int port, char* db_name, char* db_host, string table_name, vector<string> data);

bool judgeConnectStatus(mysqlpp::Connection& con, char* db_name, char* db_host, char* username, char* password, unsigned int port)
{
	if(!con.connect(db_name, db_host, username, password, port))
	{
		char statusMessageFail[100];
	    sprintf(statusMessageFail, "connect database:%s with user %s fail! Please check parameters.", db_name, username);
		cout << statusMessageFail << endl;
	    return false;
	}
    else
	{
		char statusMessageSuccess[100];
	    sprintf(statusMessageSuccess, "connect database:%d with user %d success!", MYSQL_PORT, MYSQL_PORT);
		cout << statusMessageSuccess<< endl;
		cout << CMD_CREATE_USER_TABLE <<endl;
		return true;
	}
}

void createTable(string cmd, char* username, char* password, unsigned int port)
{
	mysqlpp::Connection con(false);
    con.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	char* db_name = (char*)"iwen";
	char* db_host = (char*)"localhost";
	if(!judgeConnectStatus(con, db_name, db_host, username, password, port))
        {
	    cout << "create table failed!"<< endl;
	}
	else
	{
	    
	    mysqlpp::Query query=con.query(cmd);
	    bool result=query.exec();
	    if(result)
	    {
	    	cout << "create table success!" << endl;
	    }
	    else
	    {
	    	cout << "create table failed!!!"<< endl;
	    }
    }
	}

bool queryData(char* username, char* password, unsigned int port, char* db_name, char* db_host, string table_name, string cmd)
{
    mysqlpp::Connection con(false);
    con.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
    if(!judgeConnectStatus(con, db_name, db_host, username, password, port))
    {
	    return false;
	}
	else
	{
	    
	    mysqlpp::Query query=con.query(cmd);
	    mysqlpp::StoreQueryResult result=query.store();
        if(nullptr==result){
            cout<<"query failed!"<<endl;
            return false;
        }
        else
        {
        	cout << "query result is:" << endl;
        	for(auto iter=result.begin();iter!=result.end();++iter){
                cout << "\t" << (*iter)[0] << endl;
            }
            return true;
        }
	}
}


bool insertData(char* username, char* password, unsigned int port, char* db_name, char* db_host, string table_name, vector<string> data)
{
	if(table_name == "user")
	{
	    mysqlpp::Connection con(false);
        con.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
        if(!judgeConnectStatus(con, db_name, db_host, username, password, port))
        {
	        return false;
	    }
	    else
	    {
	    	// query.h define some function about insert data;
	    }

	}
	else
	{
		cout << "For now, only support table user!" << endl;
	}
	return true;

}



int main()
{
	
	createTable(CMD_CREATE_USER_TABLE, (char*)MYSQL_USER, (char*)MYSQL_PASSWD, MYSQL_PORT);

}

