#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int main (int argc, char** argv){
    sqlite3* DB;
    int exit = 0;

    string sql = 

//PRODUCT DATABASE
    "CREATE TABLE PRODUCTS ("
    "PRODUCT_ID        INT         PRIMARY KEY     NOT NULL,"
    "PRODUCT_NAME      TEXT                                ,"
    "CATEGORY_ID       ID                                  ,"
    "DESCRIPTION       TEXT                                ,"
    "PRICE             INT                                 ,"
    "QUANTITY_IN_STOCK INT                                 ,"
    "SUPPLIER_ID       INT                                );"

    "CREATE TABLE CATEGORIES ("
    "CATEGORY_ID     INT         PRIMARY KEY     NOT NULL,"
    "CATEGORY_NAME   TEXT                               );"

    "CREATE TABLE SUPPLIER_PROFILE ("
    "SUPPLIER_ID        INT         PRIMARY KEY     NOT NULL,"
    "COMPANY_NAME       TEXT                                ,"
    "EMAIL              TEXT                                ,"
    "PHONE              TEXT                                ,"
    "ADDRESS            TEXT                                ,"
    "LOCATION           TEXT                               );"

//INVENTORY MANAGEMENT
    "CREATE TABLE INVENTORIES ("
    "PRODUCT_ID             INT         PRIMARY KEY     NOT NULL,"
    "PRODUCT_NAME           TEXT                                ,"
    "QUANTITY_AVAILABLE     INT                                 ,"
    "UNIT_PRICE             INT                                 ,"
    "REORDER_THRESHOLD      INT                                 ,"
    "SUPPLIER_ID            INT                                );"

//CUSTOMER DATABASE
    "CREATE TABLE CUSTOMER_PROFILE ("
    "CUSTOMER_ID        INT         PRIMARY KEY     NOT NULL,"
    "FULL_NAME          TEXT                                ,"      //REAL NAME
    "EMAIL              TEXT                                ,"
    "PHONE_NUMBER       TEXT                                ,"
    "ADDRESS            TEXT                                ,"
    "USER_NAME          TEXT                                ,"      //ACCOUNT NAME
    "PASSWORD           TEXT                                ,"
    "PURCHASE_HISTORY   TEXT                               );"

    "CREATE TABLE CUSTOMER_ORDER ("
    "ORDER_ID        INT         PRIMARY KEY     NOT NULL,"
    "CUSTOMER_ID     INT                                 ,"
    "PRODUCT_ID      INT                                 ,"
    "PRODUCT_NAME    TEXT                                ,"
    "ORDER_DATE      TEXT                                ,"
    "TOTAL_AMOUNT    INT                                 ,"
    "STATUS          TEXT                               );"

//OTHERS
    "CREATE TABLE LOGIN_USER ("
    "USER_ID        INT         PRIMARY KEY     NOT NULL,"
    "USER_NAME      TEXT                                ,"
    "PASSWORD       TEXT                                ,"
    "EMAIL          TEXT                               );"

    "CREATE TABLE LOGIN_ADMIN ("
    "USER_ID        INT         PRIMARY KEY     NOT NULL,"
    "USER_NAME      TEXT                                ,"
    "PASSWORD       TEXT                                ,"
    "EMAIL          TEXT                               );"

    "CREATE TABLE SHOP_INFORMATION ("
    "SHOP_ID            INT         PRIMARY KEY     NOT NULL,"
    "SHOP_NAME          TEXT                                ,"
    "ADDRESS_ID         TEXT                                ,"
    "PRODUCT_ID         INT                                 ,"
    "PRODUCT_NAME       TEXT                                ,"
    "ORDER_DATE         TEXT                                ,"
    "TOTAL_AMOUNT       INT                                 ,"
    "STATUS             TEXT                               );"

    "CREATE TABLE REPORT ("
    "REPORT_ID          INT         PRIMARY KEY     NOT NULL,"
    "REPORT_DATE        TEXT                                ,"
    "REPORT_CONTENT     TEXT                                ,"
    "REPORT_STATUS      TEXT                               ),";


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