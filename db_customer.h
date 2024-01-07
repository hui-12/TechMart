#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int create_db_customer(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    
    "CREATE TABLE CUSTOMER("
    "CUSTOMER_ID     INTEGER PRIMARY KEY     AUTOINCREMENT, "
    "NAME   TEXT    NOT NULL, "
    "PHONE          TEXT  NOT NULL, "
    "ORDER_HISTORY  TEXT    NOT NULL);"

    "CREATE TABLE \"ORDER\"("
    "ORDER_ID INTEGER PRIMARY KEY    AUTOINCREMENT, "
    "PRODUCT_NAME           TEXT    NOT NULL, "
    "\"DATE\"       TEXT        NOT NULL);";

    exit = sqlite3_open("db_customer.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0,&messaggeError);


    if (exit != SQLITE_OK){
        cerr << "Error Create Database, " << sqlite3_errmsg(DB) << endl;
        return (-1);
    } else {
    cout << "Database Create Successfully, " << endl;
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

string sql = "INSERT INTO CUSTOMER VALUES (Hui, 011111111, no);";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error Insert Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data inserted Successfully" << endl;
    }

    sqlite3_close(DB);

    return 0;
}

