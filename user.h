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
    Customer newuser(name, phone);
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
cout<< "Please enter your phone number.";
getline (cin, phone);
cout<< "Please confirm your information.(y/n)";
newuser.display();
cin>> input;
if (input == 'y' || input == 'Y'){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("db_customer.db", &DB);

string sql= "INSERT INTO CUSTOMER (NAME, PHONE, ORDER_HISTORY ) "
            "VALUES ('"+name+","+phone+"','');";

    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

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
5. Cart
6. Log out
-------------------------
Please enter a number (1-5).
)";

}

void profile(){

    cout<< R"(
=========================
=========================
Profile Page

)";

sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_customer.db", &DB);
    string query = "SELECT * FROM CUSTOMER WHERE ID='" +to_string(input)+ "'";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

}

void categories(){
    
    cout<< R"(
=========================
=========================
Categories

)";
sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("db_product.db", &DB);
    string query = "SELECT * FROM CATEGORY";
    
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}



void product_catalogue(){
    
    cout<< R"(
    =========================
    =========================
    Product List

)";


}

void shop1Product(){
    
    cout<< R"(
    =========================
    =========================
    Shop 1 - Product

    1. INTEL CORE I5 10500
    2. AORUS PC3333
    3. CYNOSA CHROMA MEMBRANE

    4. Return

    Please enter a number (1-4).
    =========================
    =========================
    )";
    cin >> input;

}

void shop2Product(){
    
    cout<< R"(
    =========================
    =========================
    Shop 2 - Product

    1. INTEL CORE I7 10700K
    2. AORUS PC3733
    3. BLK WIDOW ULTIMATE 2016

    4. Return

    Please enter a number (1-4).
    =========================
    =========================
    )";

}

void shop3Product(){
    
    cout<< R"(
    =========================
    =========================
    Shop 3 - Product

    1. INTEL CORE I9 10900X
    2. AORUS PC4400
    3. BLK WIDOW TE VHROMA V2 QUARTZ EDI

    4. Return

    Please enter a number (1-4).
    =========================
    =========================
    )";

}
