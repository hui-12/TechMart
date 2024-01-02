#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int main (int argc, char** argv){
    sqlite3* DB;
    int exit = 0;

    string sql = 

    "CREATE TABLE PRODUCTS ("
    "PRODUCT_ID        INTEGER          PRIMARY KEY     AUTOINCREMENT,"
    "CATEGORY_ID       INT          ,"
    "SHOP_ID           INT          ,"
    "PRODUCT_NAME      TEXT         NOT NULL,"
    "PRODUCT_PRICE     INT          NOT NULL,"
    "TOTAL_SALES       TEXT         ,"
    "TOTAL_QUANTITY    INT          );"


    "CREATE TABLE CATEGORIES ("
    "CATEGORY_ID     INTEGER     PRIMARY KEY    AUTOINCREMENT,"
    "CATEGORY_NAME   TEXT        );"


    "CREATE TABLE SUPPLIER ("
    "SUPPLIER_ID        INTEGER         PRIMARY KEY        AUTOINCREMENT,"
    "EMAIL_ID           INT         ,"
    "ADDRESS_ID         INT         ,"
    "COMPANY_NAME       TEXT        NOT NULL,"
    "PHONE              TEXT        NOT NULL);"


    "CREATE TABLE SHOP ("
    "SHOP_ID                    INTEGER     PRIMARY KEY    AUTOINCREMENT,"
    "ADDRESS_ID                 INT     ,"
    "PRODUCT_ID                 INT     ,"
    "SHOP_NAME                  TEXT    NOT NULL,"
    "SHOP_PRODUCT_QUANTITY      INT     NOT NULL,"
    "SALES                      INT     NOT NULL);"


    "CREATE TABLE RECORD ("
    "RECORD_ID          INTEGER     PRIMARY KEY     AUTOINCREMENT,"
    "PRODUCT_ID         INT     ,"
    "USER_ID            INT     ,"
    "TOTAL_PRICE        INT     NOT NULL,"
    "PAYMENT_METHOD     TEXT    NOT NULL);"


    "CREATE TABLE USER ("
    "USER_ID        INTEGER         PRIMARY KEY        AUTOINCREMENT,"
    "ADDRESS_ID     INT         ,"
    "EMAIL_ID       INT         ,"
    "USER_NAME      TEXT        NOT NULL,"
    "USER_PW        TEXT        NOT NULL);"


    "CREATE TABLE ADDRESS ("
    "ADDRESS_ID         INTEGER     PRIMARY KEY     AUTOINCREMENT,"
    "USER_ID            INT     ,"
    "SUPPLIER_ID        INT     ,"
    "CITY               TEXT    NOT NULL,"
    "STATE              TEXT    NOT NULL,"
    "POSTCODE           TEXT    NOT NULL,"
    "COUNTRY            TEXT    NOT NULL);"


    "CREATE TABLE EMAIL ("
    "EMAIL_ID       INTEGER     PRIMARY KEY    AUTOINCREMENT,"
    "USER_ID        INT     ,"
    "SUPPLIER_ID    INT     ,"
    "EMAIL          TEXT    NOT NULL);"


    "CREATE TABLE CREW ("
    "CREW_ID        INTEGER     PRIMARY KEY    AUTOINCREMENT,"
    "SHOP_ID        INT     ,"
    "CREW_NAME      TEXT    NOT NULL,"
    "POSITION       TEXT    NOT NULL);";


    exit = sqlite3_open("TechMart.db", &DB);
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