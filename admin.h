#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int input;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        if (argv[i]) {
            printf("%s = %s\n", azColName[i], argv[i]);
        } else {
            printf("%s = NULL\n", azColName[i]);
        }
    }
    printf("\n");
    return 0;
}

void admin_page(){
    cout<< R"(

=========================
=========================
ADMIN MENU

Welcome to TechMart!!!
1. Customer
2. Supplier
3. Product
4. Shop
5. Edit
6. Report
7. Log Out
-------------------------
Please enter a number (1-7).

)";
    
}

static int customer(){
    cout<< R"(
    
=========================
=========================
Customer Information

    )";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_customer.db", &DB);
    string query = "SELECT * FROM CUSTOMER;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}

static int supplier(){
    cout<< R"(
    
=========================
=========================
Supplier Information

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);
    string query = "SELECT * FROM SUPPLIER;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}

static int product(){
    cout<< R"(
    
=========================
=========================
Product Information

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);
    string query = "SELECT * FROM PRODUCT;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}

void select_shop(){
    cout<< R"(
=========================
=========================
Chooese a shop.

1. Shop 1
2. Shop 2
3. Shop 3
4. Back
-------------------------
Please enter 1 - 4 to see more information.

)";
}

static int shop1(){
    cout<< R"(
    
=========================
=========================
Shop 1 Information

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_inventory.db", &DB);
    string query = "SELECT * FROM SHOP1;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}

static int shop2(){
    cout<< R"(
    
=========================
=========================
Shop 2 Information

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_inventory.db", &DB);
    string query = "SELECT * FROM SHOP2;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}

static int shop3(){
    cout<< R"(
    
=========================
=========================
Shop 3 Information

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_inventory.db", &DB);
    string query = "SELECT * FROM SHOP3;";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
    return (0);
}

int report(){
    cout<< R"(
=========================
=========================
There is the thread of our product.

)";

sqlite3* DB;
    int exit = sqlite3_open("your_inventory.db", &DB);

    string query = "SELECT MAX(TOTAL_SALES) FROM TOTAL_SALES;";

    char* messageError;
    exit = sqlite3_exec(DB, query.c_str(), callback, 0, &messageError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error executing query: " << messageError << std::endl;
        sqlite3_free(messageError);
    }

    sqlite3_close(DB);

}