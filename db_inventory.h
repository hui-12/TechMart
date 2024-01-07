#include <iostream>
#include "sqlite3.h"

using namespace std;

int create_db_inventory(){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);
  
    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;         return (-1);
    }
    else{
    std::cout << "Opened Database Successfully!" << std::endl;     sqlite3_close(DB);     

    return (0);
    }

    std::string sql = "CREATE TABLE SHOP1("
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);";

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


    string sql1 = "CREATE TABLE SHOP2("
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);";

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

    std::string sql2 = "CREATE TABLE SHOP3("
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);";

    char* messaggeError;    
    
    exit = sqlite3_exec(DB, sql2.c_str(), NULL, 0, &messaggeError);      
    
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
