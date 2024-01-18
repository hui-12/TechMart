#include <iostream>
#include <string>

using namespace std;

class Customer{
    public:
        string name , phone;

        Customer(string customerName, string customerPhone)
        : name(customerName), phone(customerPhone) {}

        void setName(string newname){
            name = newname;
        }

        void setPhone(string newphone){
            phone = newphone;
        }

        void display() const {
        cout << "Name: " << name << "\nPhone: " << phone << endl;
}
};

void new_user(){

    string name, phone;
    char input;

    NEW1 :
cout<< R"(
=========================
=========================
Information

Please enter your name.
)";
cin.clear();
cin.ignore(9999,'\n');
getline (cin,name);
cout<< "Please enter your phone number."<<endl;
getline (cin, phone);
cout<< "Please confirm your information.(y/n)"<<endl;
Customer newuser(name, phone);
newuser.display();
cin>> input;
if (input == 'y' || input == 'Y'){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_customer.db", &DB);

string sql= "INSERT INTO CUSTOMER (NAME, PHONE) "
            "VALUES ('"+name+"','"+phone+"');";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    int id = sqlite3_last_insert_rowid(DB);

    if (exit != SQLITE_OK) {
        cerr << "Error Insert Data" << endl;
        sqlite3_free(messaggeError);
    }

    else {
        cout << "Register Successfully" << endl;
    }
    sqlite3_close(DB);
    }
else{
    goto NEW1;
    }
}

void user_page(){

    int input;

    USER:
    cout<< R"(
=========================
=========================
USER MENU

Welcome to TechMart!!!
1. Profile
2. Categories
3. Price Catalogue
4. Shop
5. Order
6. Log out
-------------------------
Please enter a number (1-6).
)";

}

void select_id(){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_customer.db", &DB);
    string query = "SELECT * FROM CUSTOMER ";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}

void profile(int id){

    cout<< R"(
=========================
=========================
Profile Page

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_customer.db", &DB);
    string query = "SELECT * FROM CUSTOMER WHERE CUSTOMER_ID='" +to_string(id)+ "'";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK) {
        cerr << "Error executing query" << endl;
        sqlite3_free(messaggeError);
    }
    sqlite3_close(DB);

}

void category(){
    
    cout<< R"(
=========================
=========================
Category

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);
    string query = "SELECT * FROM CATEGORY";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}

void price_catalogue(){
    
    cout<< R"(
    =========================
    =========================
    Product List

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);
    string query = "SELECT * FROM PRODUCT";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}

void shopProduct(int shop){
    
    cout<< R"(
=========================
=========================
)";
cout<< "Shop"<<shop<<" Product"<<endl;
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_inventory.db", &DB);
    string query = "SELECT * FROM SHOP"+to_string(shop)+"";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}

void categoryProduct(int cate){

sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);

    string select = "SELECT CATEGORY_NAME FROM CATEGORY WHERE CATEGORY_ID = "+to_string(cate);

    sqlite3_stmt* stmtCategory;
    if (sqlite3_prepare_v2(DB, select.c_str(), -1, &stmtCategory, NULL) == SQLITE_OK) {
        if (sqlite3_step(stmtCategory) == SQLITE_ROW) {
            string categoryName = reinterpret_cast<const char*>(sqlite3_column_text(stmtCategory, 0));

            string selectProducts = "SELECT * FROM PRODUCT WHERE CATEGORY = '" + categoryName + "'";

cout<< R"(
=========================
=========================
Product of )"<<categoryName<<R"(

)";
sqlite3_exec(DB, selectProducts.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
        }
    }
}

void insert_order(int id) {
    int select;
    string date;

    cout << "Please enter product id:";
    cin >> select;
    cin.ignore();
    cout << "Please enter the date:";
    getline(cin, date);

    char* messageError;
    sqlite3* DB_c;
    sqlite3* DB_i;
    sqlite3* DB_p;  

    int exit_c = sqlite3_open("db_customer.db", &DB_c);
    int exit_i = sqlite3_open("db_inventory.db", &DB_i);
    int exit_p = sqlite3_open("db_product.db", &DB_p); 

    string product_name_query = "SELECT PRODUCT_NAME, SHOP FROM PRODUCT WHERE PRODUCT_ID = " + to_string(select) + ";";

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(DB_p, product_name_query.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            string product_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            string shop_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

            // Update the quantity
            string update_product_quantity = "UPDATE " + shop_name + " SET QUANTITY = QUANTITY - 1 WHERE PRODUCT_NAME = '" + product_name + "';";
            if (sqlite3_exec(DB_i, update_product_quantity.c_str(), NULL, 0, &messageError) != SQLITE_OK) {
                cerr << "Error updating product quantity: " << messageError << endl;
            }
            else{
                                cout<<"update shop";

            }
            string update_total_sale = "UPDATE TOTAL_SALES SET TOTAL_SALES = TOTAL_SALES + 1 WHERE PRODUCT_NAME = '" + product_name + "';";
            if (sqlite3_exec(DB_i, update_total_sale.c_str(), NULL, 0, &messageError) != SQLITE_OK) {
                cerr << "Error updating total sales: " << messageError << endl;
            }
            else{
                                cout<<"update report";

            }
            // Insert into the ORDER table
            string insert_order_query = "INSERT INTO \"ORDER\" (USER_ID, PRODUCT_NAME, \"DATE\") "
                                        "VALUES ('" + to_string(id) + "', '" + product_name + "', '" + date + "');";
            if (sqlite3_exec(DB_c, insert_order_query.c_str(), NULL, 0, &messageError) != SQLITE_OK) {
                cerr << "Error inserting order: " << messageError << endl;
            } else {
                cout << "Product added successfully" << endl;
            }
        } else {
            cerr << "Product not found" << endl;
        }

        sqlite3_finalize(stmt);
    } else {
        cerr << "Error preparing statement" << sqlite3_errmsg(DB_p) << endl; 
    }

    sqlite3_close(DB_c);
    sqlite3_close(DB_i);
    sqlite3_close(DB_p);
}

void cart(int id){
    
    cout<<R"(
=========================
=========================
Order

)";

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_customer.db", &DB);

    string query = "SELECT * FROM \"ORDER\" WHERE USER_ID = " + to_string(id) + ";";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

}

/*void check(){
    for (int id=0;id<?;id++){
    if (int input!= to_string(input)){
        cout<< "no id";
    }
    }
}*/
