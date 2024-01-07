#include <iostream>
#include "sqlite3.h"

using namespace std;

int create_db(){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_customer.db", &DB);
  
    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;         return (-1);
    }
    else{
    std::cout << "Opened Database Successfully!" << std::endl;     sqlite3_close(DB);     

    return (0);
    }

    std::string sql = "CREATE TABLE CUSTOMER("
    "CUSTOMER_ID     INT PRIMARY KEY     NOT NULL, "
    "NAME   TEXT    NOT NULL, "
    "PHONE          DOUBLE  NOT NULL, "
    "ORDER_HISTORY  TEXT    NOT NULL);";

    char* messaggeError;    
    
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);      
    
    if (exit != SQLITE_OK) {       
    cerr << "Error Create Table" << std::endl;        
    sqlite3_free(messaggeError);    
    }    
    
    else{        
    std::cout << "Table created Successfully" << std::endl;    
    sqlite3_close(DB);    
    
    return (0); 
    }


    string sql1 = "CREATE TABLE ORDER("
    "ORDER_ID INT PRIMARY KEY     NOT NULL, "
    "PRODUCT_NAME           TEXT    NOT NULL, "
    "DATE       TEXT        NOT NULL);";

    char* messaggeError;    
    
    exit = sqlite3_exec(DB, sql1.c_str(), NULL, 0, &messaggeError);      
    
    if (exit != SQLITE_OK) {       
    std::cerr << "Error Create Table" << std::endl;        
    sqlite3_free(messaggeError);    
    }    
    
    else{        
    std::cout << "Table created Successfully" << std::endl;    
    sqlite3_close(DB);    
    
    return (0); 
    }

}
