#include <iostream>
#include <string>
#include "sqlite3.h"
using namespace std;

int main (int argc,char **argv){
    sqlite3* DB;
    int exit=0;

    exit=sqlite3_open("db_product.db", &DB);
//PRODUCT
    string sql= "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('INTEL CORE I5 10500',899,'XIXI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('INTEL CORE I7 10700K',1499,'XIXI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('INTEL CORE I9 10900X',2599,'XIXI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('AORUS PC3333',559,'HAHA TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('AORUS PC 3733',659,'HAHA TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('AORUS PC 4400',699,'HAHA TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('CYNOSA CHROMA MEMBRANE',239,'HIHI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('BLK WIDOW ULTIMATE 2016',275,'HIHI TECHNOLOGY');"

                "INSERT INTO PRODUCT (PRODUCT_NAME,PRICE,SUPPLIER_NAME)"
                "VALUES ('BLK WIDOW TE VHROMA V2 QUARTZ EDI',499,'HIHI TECHNOLOGY');"




//CATEGORY
                "INSERT INTO CATEGORY (CATEGORY_NAME)"
                "VALUE ('PROCESSOR')"

                "INSERT INTO CATEGORY (CATEGORY_NAME)"
                "VALUE ('RAM VALUE')"

                "INSERT INTO CATEGORY (CATEGORY_NAME)"
                "VALUE ('KEYBOARD')"



//SUPPLIER
                "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
                "VALUES ('XIXI TECHNOLOGY','XIXITECHNOLOGY@GMAIL.COM');"

                "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
                "VALUES ('HAHA TECHNOLOGY','HAHATECHNOLOGY@GMAIL.COM');"

                "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
                "VALUES ('HIHI TECHNOLOGY','HIHITECHNOLOGY@GMAIL.COM');"
                ;

//INVENTORY
//SHOP1
                "INSERT INTO SHOP1 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CORE I5 10500','PROCESSOR',10);"
                
                "INSERT INTO SHOP1 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('AORUS PC3333','RAM VALUE',10);"  
                
                "INSERT INTO SHOP1 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CYNOSA CHROMA MEMBRANE','KEYBOARD',);"
//SHOP2

                "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CORE I7 10700K','PROCESSOR',10);"
                
                "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('AORUS PC3733','RAM VALUE',10);"  
                
                "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('BLK WIDOW ULTIMATE 2016','KEYBOARD',10);" 
//SHOP3

                "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('CORE I9 10900X','PROCESSOR',10);"
                
                "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('AORUS PC4400','RAM VALUE',10);"  
                
                "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('BLK WIDOW TE CHROMA V2 QUARTZ EDI','KEYBOARD',10);"   

                ;   



//CUSTOMER
                
                "INSERT INTO CUSTOMER (NAME,PHONE,ORDER_HISTORY)"
                "VALUES ('LAI','0123456789','CORE I9 10900X');"
                
                "INSERT INTO CUSTOMER (NAME,PHONE,ORDER_HISTORY)"
                "VALUES ('SEE','0123456788','CORE I9 10900X');"

                "INSERT INTO CUSTOMER (NAME,PHONE,ORDER_HISTORY)"
                "VALUES ('TAN','0123456777','CORE I9 10900X');"

                
                


//ORDER
                "INSERT INTO  \"ORDER\"(PRODUCT_NAME,\"DATE\")"
                "VALUES ('CORE I9 10900X','20-05-2024');"

                "INSERT INTO  \"ORDER\"(PRODUCT_NAME,\"DATE\")"
                "VALUES ('AORUS PC4400','20-05-2024');"

                "INSERT INTO  \"ORDER\"(PRODUCT_NAME,\"DATE\")"
                "VALUES ('BLK WIDOW TE CHROMA V2 QUARTZ EDI','20-05-2024');"
                ;
}