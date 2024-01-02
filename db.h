#include <iostream> 
#include "sqlite3.h"

int main(int argc, char** argv)
{
    sqlite3* DB;

     std::string sql =
     
    "CREATE TABLE USER("
    "USER_ID        INT     PRIMARY KEY     NOT NULL    AUTOINCREMENT, "
    "EMAIL_ID       INT     FOREIGN KEY REFERENCES EMAIL(EMAIL_ID), "
    "ADDRESS_ID     INT     FOREIGN KEY REFERENCES ADDRESS(ADDRESS_ID), "
    "USER_NAME      TEXT    NOT NULL, "
    "USER_PW        TEXT    NOT NULL );";

    "CREATE TABLE EMAIL("
    "EMAIL_ID       INT     PRIMARY KEY     NOT NULL    AITOINCREMENT, "
    "USER_ID        INT     FOREUGN KEY REFERENCES USER(USER_ID), "
    "SUPLIER_ID     INT     FOREIGN KEY REFERENCES SUPPLIER(SUPPLIER_ID), "
    "EMAIL          TEXT    NOT NULL );";

    "CREATE TABLE ADDRESS("
    "ADDRESS_ID     INT     PRIMARY KEY     NOT NULL    AUTOINCREMENT, "
    "USER_ID        INT     FOREIGN KEY REFERENCES  USER(USER_ID), "
    "SUPLIER_ID     INT     FOREIGN KEY REFERENCES SUPPLIER(SUPPLIER_ID), "
    "CITY           TEXT    NOT NULL, "
    "STATE          TEXT    NOT NULL, "
    "COUNTRY        TEXT    NOT NULL );";

    "CREATE TABLE SUPPLIIER("
    "SUPPLIER_ID    INT     PRIMARY KEY     NOT NULL    AUTOINCREMENT, "
    "EMAIL_ID       INT     FOREIGN KEY REFERENCES EMAIL(EMAIL_ID), "
    "ADDRESS_ID     INT     FOREIGN KEY REFERENCES ADDRESS(ADDRESS_ID), "
    "COMPANY_NAME   TEXT    NOT NULL, "
    "PHONE          LONG    NOT NULL );";

    "CREATE TABLE SHOP("
    "SHOP_ID        INT     PRIMARY KEY     NOT NULL    AUTOINCREMENT, "
    "PRODUCT_ID     INT     FOREIGN KEY REFERENCES PRODUCT(PRODUCT_ID), "
    "ADDRESS_ID     INT     FOREIGN KEY REFERENCES ADDRESS(ADDRESS_ID), "
    "SHOP_NAME      TEXT    NOT NULL, "
    "SALES          INT     NOT NULL, "
    "SHOP_PRODUCT_QUANTITY  INT NOT NULL );";

    "CREATE TABLE PRODUCT("
    "PRODUCT_ID     INT     PRIMMARY KEY    NOT NULL    AUTOINCREMENT, "
    "SHOP_ID        INT     FOREIGN KEY REFERENCES SHOP(SHOP_ID) "
    "CATEGORIES_ID  INT     FOREIGN KEY REFERENCES  CATEGORIES_ID, "
    "PRODUCT_NAME   TEXT    NOT NULL, "
    "PRODUCT_QUANTITY   INT NOT NULL"
    "TOTAL_SALES    INT     NOT NULL" )"
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
                                               
     else
        std::cout << "Opened Database Successfully!" << std::endl;
        sqlite3_close(DB);
                                                                
        return (0);
}