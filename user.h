#include <iostream>
#include <string>

using namespace std;

int input;

void user_page(){
    USER:
    cout<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tUSER MENU"<<endl<<endl;
    cout<<"Welcome to TechMart!!!"<<endl<<endl;
    cout<<"1. Profile"<<endl;
    cout<<"2. Categories"<<endl;
    cout<<"3. Price Catalogue"<<endl;
    cout<<"4. Cart"<<endl;
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

void profile(){
    cout<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tProfile Page"<<endl<<endl;
    cout<<"Welcome to TechMart!!!"<<endl<<endl;
    cout<<"1. Shop Location"<<endl;
    cout<<"2. Modify"<<endl;
    cout<<"3. Log Out"<<endl;
    cout<<"Please enter a number (1-3)."<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cin >> input;

}