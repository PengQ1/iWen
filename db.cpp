#include <iostream>
#include <string>
#include <cstdlib>

#include <mysql++/mysql++.h>

using namespace std;

#define MYSQL_USER "root"
#define MYSQL_PASSWD "123456"
#define MYSQL_PORT 3306

int main(){

    mysqlpp::Connection con(false);
    con.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
    if(!con.connect("test","localhost",MYSQL_USER,MYSQL_PASSWD,MYSQL_PORT)){
        cout<<"can't connect,check the user and passwd"<<endl;
        return -1;
    }
    cout<<"mysql connect successfully!"<<endl;

    mysqlpp::Query query=con.query("select * from City");
    mysqlpp::StoreQueryResult result=query.store();
    if(nullptr==result){
        cout<<"query failed!"<<endl;
        return -1;
    }

    for(auto iter=result.begin();iter!=result.end();++iter){
        cout<<"\t"<<(*iter)[0]<<endl;
    }

    return 0;
}