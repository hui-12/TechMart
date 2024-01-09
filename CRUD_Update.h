#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int Delete(){
    sqlite3* DB;
    int exit = 0;
    char* messageError;

    string sql = ""

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