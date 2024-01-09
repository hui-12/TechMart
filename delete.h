#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

void Delete(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    "DELETE FROM PRODUCT WHERE ID = 1;";

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