#include <iostream>
#include <string>

using namespace std;

int input;

void admin_page(){
    ADMIN:
    cout<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tADMIN MENU"<<endl<<endl;
    cout<<"Welcome to TechMart!!!"<<endl<<endl;
    cout<<"1. Shop Location"<<endl;
    cout<<"2. Customer"<<endl;
    cout<<"3. Store"<<endl;
    cout<<"4. Crew"<<endl;
    cout<<"5. Supplier"<<endl;
    cout<<"6. Log Out"<<endl;
    cout<<"Please enter a number (1-6)."<<endl;
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

        break;

        case 6 :
            cout<<"Thank You!"<<endl;

        break;

        default :
        cout<<"Invalid number! Please input again.";
        goto ADMIN;
    }

}

