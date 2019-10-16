#include <iostream>
#include <mysql++/mysql++.h>
using namespace std;





Class Table
{
public:
	virtual bool createTable() = 0;
	virtual bool deleteTable() = 0;
	virtual bool insertData() = 0;
	virtual bool deleteData() = 0;
	virtual mysqlpp::StoreQueryResult queryData() = 0;
	virtual bool changeData() = 0;
};

Class chatTable: public Table
{
public:
	bool createTable()
	{

	}
	bool deleteTable()
	{

	}
	bool insertData()
	{

	}
	bool deleteData()
	{

	}
	mysqlpp::StoreQueryResult queryData()
	{

	}
	bool changeData()
	{

	}

};