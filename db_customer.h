#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int create_db_customer(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    
    "CREATE TABLE IF NOT EXISTS CUSTOMER("
    "CUSTOMER_ID     INTEGER PRIMARY KEY     AUTOINCREMENT, "
    "NAME   TEXT    NOT NULL, "
    "PHONE          TEXT  NOT NULL, "
    "ORDER_HISTORY  TEXT    NOT NULL);"

    "CREATE TABLE IF NOT EXISTS \"ORDER\"("
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

string sql= "INSERT INTO CUSTOMER (NAME, PHONE, ORDER_HISTORY ) "
            "VALUES ('LAI','0123456789','CORE I9 10900X');"

            "INSERT INTO CUSTOMER (NAME,PHONE,ORDER_HISTORY)"
            "VALUES ('SEE','0123456788','CORE I9 10900X');"

            "INSERT INTO CUSTOMER (NAME,PHONE,ORDER_HISTORY)"
            "VALUES ('TAN','0123456777','CORE I9 10900X');";

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


int insert_data_order(){

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

string sql=     "INSERT INTO  \"ORDER\"(PRODUCT_NAME,\"DATE\")"
                "VALUES ('CORE I9 10900X','20-05-2024');"

                "INSERT INTO  \"ORDER\"(PRODUCT_NAME,\"DATE\")"
                "VALUES ('AORUS PC4400','20-05-2024');"

                "INSERT INTO  \"ORDER\"(PRODUCT_NAME,\"DATE\")"
                "VALUES ('BLK WIDOW TE CHROMA V2 QUARTZ EDI','20-05-2024');";

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
