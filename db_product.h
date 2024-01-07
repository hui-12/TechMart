#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int create_db_product(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    "CREATE TABLE PRODUCT("
    "PRODUCT_ID     INTEGER PRIMARY KEY    AUTOINCREMENT , "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "PRICE          DOUBLE  NOT NULL, "
    "SUPPLIER_NAME  TEXT    NOT NULL);"

    "CREATE TABLE CATEGORY("
    "CATEGORY_ID INTEGER PRIMARY KEY     AUTOINCREMENT , "
    "CATEGORY_NAME           TEXT    NOT NULL);"

    "CREATE TABLE SUPPLIER("
    "SUPPLIER_ID INTEGER PRIMARY KEY    AUTOINCREMENT , "
    "SUPPLIER_NAME           TEXT    NOT NULL, "
    "EMAIL          TEXT     NOT NULL);";

    exit = sqlite3_open("db_product.db", &DB);
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

