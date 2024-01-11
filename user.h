#include <iostream>
#include <string>

using namespace std;


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

    Please enter a number (1-5).
    =========================
    =========================
    )";
    cin >> input;

}

void profile(){
int input;

    cout<< R"(
    =========================
    =========================
    Profile Page

    1. Shop Location
    2. Modify
    3. Log Out

    Please enter a number (1-3).
    =========================
    =========================
    )";
    cin >> input;

}

void categories(){
    int input;
    
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
    cin >> input;

}

void supplierProfile(){
    int input;
    
    cout<< R"(
    =========================
    =========================
    Supplier Profile

    1. XIXI TECHNOLOGY
    2. HAHA TECHNOLOGY
    3. HIHI TECHNOLOGY

    4. Return

    Please enter a number (1-4).
    =========================
    =========================
    )";
    cin >> input;

}

void productList(){
    int input;
    
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
    cin >> input;

}

void shop1Product(){
    int input;
    
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
    int input;
    
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
    cin >> input;

}

void shop3Product(){
    int input;
    
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
    cin >> input;

}
