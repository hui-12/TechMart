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