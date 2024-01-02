#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int main (int argc, char** argv){
    sqlite3* DB;
    int exit = 0;

    string sql = 

    "CREATE TABLE PRODUCTS ("
    "PRODUCT_ID        INT          PRIMARY KEY     NOT NULL     AUTOINCREMENT,"
    "CATEGORY_ID       INT          FOREIGN KEY REFERENCES CATEGORIES(CATEGORIES_ID),"
    "SHOP_ID           TEXT         FOREIGN KEY REFERENCES SHOP(SHOP_ID),"
    "PRODUCT_NAME      TEXT         NOT NULL,"
    "PRODUCT_PRICE     INT          NOT NULL,"
    "TOTAL_SALES       TEXT         ,"
    "TOTAL_QUANTITY    INT          );"


    "CREATE TABLE CATEGORIES ("
    "CATEGORY_ID     INT         PRIMARY KEY     NOT NULL       AUTOINCREMENT,"
    "CATEGORY_NAME   TEXT        );"


    "CREATE TABLE SUPPLIER ("
    "SUPPLIER_ID        INT         PRIMARY KEY     NOT NULL        AUTOINCREMENT,"
    "EMAIL_ID           INT         FOREIGN KEY REFERENCES EMAIL(EMAIL_ID),"
    "ADDRESS_ID         INT         FOREIGN KEY REFERENCES ADDRESS(ADDRESS_ID),"
    "COMPANY_NAME       TEXT        NOT NULL,"
    "PHONE              TEXT        NOT NULL);"



    "CREATE TABLE SHOP ("
    "SHOP_ID                    INT     PRIMARY KEY     NOT NULL    AUTOINCREMENT,"
    "ADDRESS_ID                 INT     FOREIGN KEY REFERENCES ADDRESS(ADDRESS_ID),"
    "PRODUCT_ID                 INT     FOREIGN KEY REFERENCES PRODUCT(PRODUCT_ID),"
    "SHOP_NAME                  TEXT    NOT NULL,"
    "SHOP_PRODUCT_QUANTITY      INT     NOT NULL,"
    "SALES                      INT     NOT NULL);"


    "CREATE TABLE RECORD (" //CUSTOMER ORDER
    "RECORD_ID          INT     PRIMARY KEY    NOT NULL     AUTOINCREMENT,"
    "PRODUCT_ID         INT     FOREIGN KEY REFERENCES PRODUCT(PRODUCT_ID),"
    "USER_ID            INT     FOREIGN KEY REFERENCES USER(USER_ID),"
    "TOTAL_PRICE        INT     NOT NULL,"
    "PAYMENT_METHOD     TEXT    NOT NULL);"


    "CREATE TABLE USER ("
    "USER_ID        INT         PRIMARY KEY     NOT NULL        AUTOINCREMENT,"
    "ADDRESS_ID     INT         FOREIGN KEY REFERENCES ADDRESS(ADDRESS_ID),"
    "EMAIL_ID       INT         FOREIGN KEY REFERENCES EMAIL(EMAIL_ID),"
    "USER_NAME      TEXT        NOT NULL,"
    "USER_PW        TEXT        NOT NULL);"


    "CREATE TABLE ADDRESS ("
    "ADDRESS_ID         INT     PRIMARY KEY     NOT NULL     AUTOINCREMENT,"
    "USER_ID            INT     FOREIGN KEY REFERENCES USER(USER_ID),"
    "SUPPLIER_ID        INT     FOREIGN KEY REFERENCES SUPPLIER(SUPPLIER_ID),"
    "CITY               TEXT    NOT NULL,"
    "STATE              TEXT    NOT NULL,"
    "POSTCODE           TEXT    NOT NULL,"
    "COUNTRY            TEXT    NOT NULL);"


    "CREATE TABLE EMAIL ("
    "EMAIL_ID       INT     PRIMARY KEY     AUTOINCREMENT,"
    "USER_ID        INT     FOREIGN KEY REFERENCES USER(USER_ID),"
    "SUPPLIER_ID    INT     FOREIGN KEY REFERENCES SUPPLIER(SUPPLIER_ID),"
    "EMAIL          TEXT    NOT NULL);"


    "CREATE TABLE CREW ("
    "CREW_ID        INT     PRIMARY KEY     AUTO INCREMENT,"
    "SHOP_ID        INT     FOREIGN KEY REFERENCES SHOP(SHOP_ID),"
    "CREW_NAME      TEXT    NOT NULL,"
    "POSITION       TEXT    NOT NULL);"


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