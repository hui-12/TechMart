#include <iostream>
#include <string>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}

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
4. Cart
5. Log out
-------------------------
Please enter a number (1-5).
)";

}

void profile(){

    cout<< R"(
=========================
=========================
Profile Page

1. Shop Location
2. Modify
3. Log Out
-------------------------
Please enter a number (1-7).

    )";

}

void categories(){
    
    cout<< R"(
=========================
=========================
Categories

1. Processor
2. Ram Value
3. Keyboard

4. Return

Please enter a number (1-4).
=========================
=========================
    )";

}

void supplierProfile(){
    
    cout<< R"(
=========================
=========================
Supplier Profile

1. XIXI TECHNOLOGY
2. HAHA TECHNOLOGY
3. HIHI TECHNOLOGY
4. Back
-------------------------
Please enter a number (1-7).

    )";

}

void productList(){
    
    cout<< R"(
    =========================
    =========================
    Product List

    1. INTEL CORE I5 10500
    2. INTEL CORE I7 10700K
    3. INTEL CORE I9 10900X
    4. AORUS PC3333
    5. AORUS PC3733
    6. AORUS PC4400
    7. CYNOSA CHROMA MEMBRANE
    8. BLK WIDOW ULTIMATE 2016
    9. BLK WIDOW TE VHROMA V2 QUARTZ EDI

    10. Return

    Please enter a number (1-10).
    =========================
    =========================
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
