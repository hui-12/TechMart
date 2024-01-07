#include <iostream>
#include <string>
#include <vector>
#include "admin.h"
#include "db_customer.h"
#include "db_inventory.h"
#include "db_product.h"
#include "sqlite3.h"

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

//int input;
/*
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
*/
int main(){
/*
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
    }*/

    create_db_inventory();
    create_db_product();
    create_db_customer();
}