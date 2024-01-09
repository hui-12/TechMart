#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int Update(){
    sqlite3* DB;
    int exit = 0;
    char* messageError;

    string sql = "UPDATE SHOP1 set QUANTITY = 8 where ID = 1"
                 "UPDATE SHOP2 set QUANTITY = 5 where ID = 2"
                 "UPDATE SHOP3 set QUANTITY = 9 where ID = 3";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK){
        cerr << "Error delete product, " << sqlite3_errmsg(DB) << endl;
        return(-1);
    } else {
    cout << "Product create successfully, " << endl;
    sqlite3_close(DB);
    return(0);
    }
}