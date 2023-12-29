#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int input=0, i=0;       //array for int//
string id[9],pw[9],email[9]; //array for signup string//
string l_id,l_pw,l_email;

//function for login menu
void loginmenu(){
    cout<<endl<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tTECHMART"<<endl<<endl;
    cout<<"1. Sign up"<<endl;
    cout<<"2. Login User"<<endl;
    cout<<"3. Login Admin"<<endl;
    cout<<"4. Exit"<<endl<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
}

//function for sign up page
void signup(){

    cout<<""<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tSIGNUP"<<endl<<endl;
    cout<<"User ID : Hello World";
    cin>> id[i];
    cout<<"Password : ";
    cin>> pw[i];
    cout<<"Email : ";
    cin>> email[i];
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    i++;
}

bool login_user(){
    cout<<""<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tLOGIN USER"<<endl<<endl;
    cout<<"User ID : ";
    cin>> l_id;
    cout<<"Password : ";
    cin>> l_pw;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;

    //check login detail
    for(int j=0;j<i;j++){
        if(id[j] == l_id && pw[j] == l_pw){
            cout<< "Login Successful!";
            return true;
        }
    } 
    cout << "Failed! Please try again!"<<endl;
    return false;
}

bool login_admin(){
    string a_id = "admin",a_pw = "admin";

    cout<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tLOGIN ADMIN"<<endl<<endl;
    cout<<"Admin ID : ";
    cin>> l_id;
    cout<<"Password : ";
    cin>> l_pw;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;

    //check login detail
    if(l_id == a_id && l_pw == a_pw){
        cout<< "Login Successful!";
        return true;
    } 
    cout << "Failed! Please try again!"<<endl;
    return false;
}

void user_page(){
    USER:
    cout<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tUSER MENU"<<endl<<endl;
    cout<<"Welcome to TechMart!!!"<<endl<<endl;
    cout<<"1. Profile"<<endl;
    cout<<"2. Categories"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Price Catalogue"<<endl;
    cout<<"5. Log out"<<endl;
    cout<<"Please enter a number (1-5)."<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cin >> input;

    switch(input){
        case 1 :

        break;

        case 2 :

        break;

        case 3 :

        break;

        case 4 :

        break;

        case 5 :
        cout<<"Thank You!"<<endl;

        break;

        default :
        cout<<"Invalid number! Please input again.";
        goto USER;
    }
}

void admin_page(){
    ADMIN:
    cout<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tADMIN MENU"<<endl<<endl;
    cout<<"Welcome to TechMart!!!"<<endl<<endl;
    cout<<"1. Shop Location"<<endl;
    cout<<"2. Modify"<<endl;
    cout<<"3. Log Out"<<endl;
    cout<<"Please enter a number (1-3)."<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cin >> input;

    switch(input){
        case 1 :

        break;

        case 2 :

        break;

        case 3 :
        cout<<"Thank You!"<<endl;

        break;

        default :
        cout<<"Invalid number! Please input again.";
        goto ADMIN;
    }

}

int main(){

    MENU:loginmenu();
    cin>>input;
    switch(input){
    case 1 :
        signup();
        goto MENU;

        break;
    
    case 2 :
        if (login_user()){
            user_page();
        }
        goto MENU;

    case 3 :
        if (login_admin()){
            admin_page();
        }
        goto MENU;

    case 4 :
        cout<< "See you again. Bye!";
        exit(0);

    default :
        cout<< "Invalid number! Please try again.";
    }
}