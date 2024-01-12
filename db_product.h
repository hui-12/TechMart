#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int create_db_product(){
    sqlite3* DB;
    int exit = 0;

    string sql = 
    "CREATE TABLE IF NOT EXISTS PRODUCT("
    "PRODUCT_ID     INTEGER PRIMARY KEY    AUTOINCREMENT , "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "PRICE          DOUBLE  NOT NULL, "
    "SUPPLIER_NAME  TEXT    NOT NULL);"

    "CREATE TABLE IF NOT EXISTS CATEGORY("
    "CATEGORY_ID INTEGER PRIMARY KEY     AUTOINCREMENT , "
    "CATEGORY_NAME           TEXT    NOT NULL);"

    "CREATE TABLE IF NOT EXISTS SUPPLIER("
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

int insert_data_supplier(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql= "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
            "VALUES ('XIXI TECHNOLOGY','XIXITECHNOLOGY@GMAIL.COM');"

            "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
            "VALUES ('HAHA TECHNOLOGY','HAHATECHNOLOGY@GMAIL.COM');"

            "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
            "VALUES ('HIHI TECHNOLOGY','HIHITECHNOLOGY@GMAIL.COM');";

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


int insert_data_product(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql=     "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('INTEL CORE I5 10500',899,'PROCESSOR','XIXI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('INTEL CORE I7 10700K',1499,'PROCESSOR','XIXI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('INTEL CORE I9 10900X',2599,'PROCESSOR','XIXI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('AORUS PC3333',559,'RAM VALUE','HAHA TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('AORUS PC3733',659,'RAM VALUE','HAHA TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('AORUS PC4400',699,'RAM VALUE','HAHA TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('CYNOSA CHROMA MEMBRANE',239,'KEYBOARD','HIHI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('BLK WIDOW ULTIMATE 2016',275,'KEYBOARD','HIHI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,CATEGORY,SUPPLIER_NAME)"
                "VALUES ('BLK WIDOW TE VHROMA V2 QUARTZ EDI',499,'KEYBOARD','HIHI TECHNOLOGY');";

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


int insert_data_category(){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl;
        return (-1);
    }
    else {
        cout << "Opened Database Successfully!" << endl;
    }

string sql=     "INSERT INTO CATEGORY (CATEGORY_NAME)"
                "VALUE ('PROCESSOR')"

                "INSERT INTO CATEGORY (CATEGORY_NAME)"
                "VALUE ('RAM VALUE')"

                "INSERT INTO CATEGORY (CATEGORY_NAME)"
                "VALUE ('KEYBOARD')";

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
