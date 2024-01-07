#include <iostream>
#include "sqlite3.h"

using namespace std;

char* messaggeError;

int create_db_customer(){
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
    "CUSTOMER_ID     INT PRIMARY KEY     NOT NULL AUTOINCREMENT, "
    "NAME   TEXT    NOT NULL, "
    "PHONE          TEXT  NOT NULL, "
    "ORDER_HISTORY  TEXT    NOT NULL);";

    
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);      
    
    if (exit != SQLITE_OK) {       
    cerr << "Error Create Customer Table" << std::endl;        
    sqlite3_free(messaggeError);    
    }    
    
    else{        
    std::cout << "Customer Table created Successfully" << std::endl;    
    sqlite3_close(DB);    
    
    return (0); 
    }


    string sql1 = "CREATE TABLE ORDER("
    "ORDER_ID INT PRIMARY KEY     NOT NULL AUTOINCREMENT, "
    "PRODUCT_NAME           TEXT    NOT NULL, "
    "DATE       TEXT        NOT NULL);";

    
    exit = sqlite3_exec(DB, sql1.c_str(), NULL, 0, &messaggeError);      
    
    if (exit != SQLITE_OK) {       
    cerr << "Error Create Order Table" << endl;        
    sqlite3_free(messaggeError);    
    }    
    
    else{        
    std::cout << "Order Table created Successfully" << std::endl;    
    sqlite3_close(DB);    
    
    return (0); 
    }
}

int insert_data_customer(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_customer.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql = "INSERT INTO CUSTOMER VALUES ();";

    

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error Insert Data" << endl;
        sqlite3_free(messageError);
    }

    else {
        cout << "Data inserted Successfully" << endl;
    }

    sqlite3_close(DB);

    return 0;
}


