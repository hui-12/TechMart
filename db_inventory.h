#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int create_db_inventory(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    "CREATE TABLE IF NOT EXISTS SHOP1("
    "SHOP1_PRODUCT_ID   INTEGER PRIMARY KEY AUTOINCREMENT, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "CATEGORY   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);"

    "CREATE TABLE IF NOT EXISTS SHOP2("
    "SHOP2_PRODUCT_ID   INTEGER PRIMARY KEY AUTOINCREMENT, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "CATEGORY       TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);"

    "CREATE TABLE IF NOT EXISTS SHOP3("
    "SHOP3_PRODUCT_ID   INTEGER PRIMARY KEY AUTOINCREMENT, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "CATEGORY   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);"
    
    "CREATE TABLE IF NOT EXISTS TOTAL_SALES("
    "PRODUCT_ID     INT     NOT NULL,"
    "PRODUCT_NAME   TEXT    NOT NULL,"
    "CATEGORY       TEXT    NOT NULL,"
    "SHOP_NAME      TEXT    NOT NULL,"
    "TOTAL_SALES    INT     NOT NULL);";

    exit = sqlite3_open("db_inventory.db", &DB);
    char* messageError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK){
        cerr << "Error Create Database, " << sqlite3_errmsg(DB) << endl;
        return (-1);
    } else {
    cout << "Database Create Successfully, " << endl;
    sqlite3_close(DB);
    return (0);
    }
}


int insert_data_shop1(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql=     "INSERT INTO SHOP1 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CORE I5 10500','PROCESSOR',10);"
                
                "INSERT INTO SHOP1 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('AORUS PC3333','RAM VALUE',10);"  
                
                "INSERT INTO SHOP1 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CYNOSA CHROMA MEMBRANE','KEYBOARD',10);";

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


int insert_data_shop2(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql=     "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CORE I7 10700K','PROCESSOR',10);"
                
                "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('AORUS PC3733','RAM VALUE',10);"  
                
                "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('BLK WIDOW ULTIMATE 2016','KEYBOARD',10);";

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


int insert_data_shop3(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql=     "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CORE I9 10900X','PROCESSOR',10);"
                
                "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('AORUS PC4400','RAM VALUE',10);"  
                
                "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('BLK WIDOW TE CHROMA V2 QUARTZ EDI','KEYBOARD',10);";

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