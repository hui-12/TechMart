#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

void select_edit(){
    cout<<R"(
=========================
=========================
Edit

1. Supplier
2. Product
3. Shop
4. Back
-------------------------
Please enter 1 - 4.
)";
}

void edit_action(){
    cout<< R"(
=========================
=========================
Edit Action

1. Add
2. Edit
3. Delete
4. Back
-------------------------
Please enter 1 - 4.
)";
}

int add_supplier(){

    string supplier_name, supplier_email;

    cout<< R"(
=========================
=========================
Add Supplier

Please enter supplier name:
)";
cin.clear();
cin.ignore(9999,'\n');
getline (cin,supplier_name);
cout<< "Please enter supplier email:";
getline (cin, supplier_email);

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

string sql=     "INSERT INTO SUPPLIER (SUPPLIER_NAME,EMAIL)"
                "VALUES ('" + supplier_name + "','" + supplier_email + "');";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error added Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data added Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int add_product(){

    string product_name, category, supplier_name;
    double price;
    
    cout<< R"(
=========================
=========================
Add Product

Please enter product name:
)";
cin.clear();
cin.ignore(9999,'\n');
getline (cin,product_name);
cout<< "Please enter price:";
cin>> price;
cin.clear();
cin.ignore(9999,'\n');
cout<< "Please enter category:";
getline (cin, category);
cout<< "Please enter supplier name:";
getline (cin, supplier_name);
//cout<< product_name<<" "<<price<<" "<<category<<" "<<supplier_name;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

string sql =    "INSERT INTO PRODUCT (PRODUCT_NAME, PRICE, CATEGORY, SUPPLIER_NAME) "
                "VALUES ('"+product_name+"',"+to_string(price)+",'"+category+"','"+supplier_name+"');";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error added Data"  << sqlite3_errmsg(DB)<< endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data added Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int add_shop(int input){

    string product_name, category;
    int quantity;

    cout<< R"(
=========================
=========================
Add Shop Item

Please enter product name:
)";
cin.clear();
cin.ignore(9999,'\n');
getline (cin,product_name);
cout<< "Please enter category:";
getline (cin, category);
cout<< "Please enter the quantity:";
cin>> quantity;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

string sql=     "INSERT INTO SHOP" + to_string(input) + " (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('" + product_name + "','" + category + "'," + to_string(quantity) + ");";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error added Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data added Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int add_shop2(){

    string product_name, category;
    string quantity;

    cout<< R"(
=========================
=========================
Add Shop Item

Please enter product name:
)";
getline (cin,product_name);
cout<< "Please enter category:";
getline (cin, category);
cout<< "Please enter the quantity:";
cin>> quantity;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

string sql=     "INSERT INTO SHOP2 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('" + product_name + "," + category + "," + quantity + "');";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error added Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data added Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int add_shop3(){

    string product_name, category;
    string quantity;

    cout<< R"(
=========================
=========================
Add Shop Item

Please enter product name:
)";
getline (cin,product_name);
cout<< "Please enter category:";
getline (cin, category);
cout<< "Please enter the quantity:";
cin>> quantity;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

string sql=     "INSERT INTO SHOP3 (PRODUCT_NAME,CATEGORY,QUANTITY)"
                "VALUES ('" + product_name + "," + category + "," + quantity + "');";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error added Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data added Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int update_supplier(){

    string supplier_name, supplier_email;

    cout<< R"(
=========================
=========================
Edit Supplier Detail

Please enter supplier ID:
)";
cin.clear();
cin.ignore(9999,'\n');
cin>> input;
int id=input;
cin.ignore(9999,'\n');
cout<< "Please enter supplier name: ";
getline (cin,supplier_name);
cout<< "Please enter supplier email: ";
getline (cin, supplier_email);

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

    string sql=     "UPDATE SUPPLIER SET SUPPLIER_NAME = '"+supplier_name+"', EMAIL = '"+supplier_email+"' "
                "WHERE SUPPLIER_ID = '"+to_string(id)+"'";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error updated Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data updated Successfully" << endl;
    }
    sqlite3_close(DB);
    return 0;
}

int update_product(){

    string product_name, category, supplier_name;
    double price;
    cout<< R"(
=========================
=========================
Edit Product Detail

Please enter product ID:
)";
cin.clear();
cin.ignore(9999,'\n');
cin>> input;
cin.clear();
cin.ignore(9999,'\n');
cout<< "Please enter product name: ";
getline (cin,product_name);
cout<< "Please enter price: ";
cin>> price;
cin.clear();
cin.ignore(9999,'\n');
cout<< "Please enter product category: ";
getline (cin, category);
cout<< "Please enter supplier name: ";
getline (cin, supplier_name);

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

string sql=     "UPDATE PRODUCT SET PRODUCT_NAME = '"+product_name+"', PRICE = '"+to_string(price)+"', CATEGORY = '"+category+"', SUPPLIER_NAME = '"+supplier_name+"' "
                "WHERE PRODUCT_ID = '"+to_string(input)+"'";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error updated Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data updated Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int update_shop(int shop){

    string product_name, category;
    int quantity;
    cout<< R"(
=========================
=========================
Edit Shop Item

Please enter product ID:
)";
cin.clear();
cin.ignore(9999,'\n');
cin>> input;
cout<< "Please enter product name";
getline (cin,product_name);
cin.clear();
cin.ignore(9999,'\n');
cout<< "Please enter category:";
getline (cin, category);
cout<< "Please enter product quantity:";
cin>> quantity;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);
string sql = "UPDATE SHOP" + to_string(shop) + " SET PRODUCT_NAME = '"+product_name+"', CATEGORY = '"+category+"', QUANTITY = '"+to_string(quantity)+"' "
             "WHERE SHOP"+to_string(shop)+"_PRODUCT_ID = '"+to_string(input)+"'";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error updated Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data updated Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int delete_supplier(){

    int input;

    cout<< R"(
=========================
=========================
Delete Supplier

Please enter supplier ID:
)";
cin.clear();
cin.ignore(9999,'\n');
cin>> input;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

string sql = "DELETE FROM SUPPLIER WHERE SUPPLIER_ID = '"+to_string(input)+"'";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error Deleted Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data Deleted Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int delete_product(){

    int input;

    cout<< R"(
=========================
=========================
Delete Product

Please enter product ID:
)";
cin.clear();
cin.ignore(9999,'\n');
cin>> input;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_product.db", &DB);

string sql = "DELETE FROM PRODUCT WHERE PRODUCT_ID = '"+to_string(input)+"'";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error Deleted Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data Deleted Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

int delete_shop(int shop){

    int input;

    cout<< R"(
=========================
=========================
Delete Shop Item

Please enter product ID:
)";
cin.clear();
cin.ignore(9999,'\n');
cin>> input;

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_inventory.db", &DB);

string sql = "DELETE FROM SHOP"+to_string(shop)+" WHERE SHOP"+to_string(shop)+"_PRODUCT_ID = '"+to_string(input)+"'";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error Deleted Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Data Deleted Successfully" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

void test() {
    cin.clear();
    cin.ignore(9999, '\n');
    cin >> input;
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);
    string query = "SELECT * FROM SUPPLIER WHERE SUPPLIER_ID = '" + to_string(input) + "'";

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}