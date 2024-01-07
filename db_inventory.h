#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int create_db_inventory(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    "CREATE TABLE SHOP1("
    "SHOP1_PRODUCT_ID   INTEGER PRIMARY KEY AUTOINCREMENT, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "CATEGORY   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);"

    "CREATE TABLE SHOP2("
    "SHOP2_PRODUCT_ID   INTEGER PRIMARY KEY AUTOINCREMENT, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "CATEGORY       TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);"

    "CREATE TABLE SHOP3("
    "SHOP3_PRODUCT_ID   INTEGER PRIMARY KEY AUTOINCREMENT, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "CATEGORY   TEXT    NOT NULL, "
    "QUANTITY       INT     NOT NULL);";

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
