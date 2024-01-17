#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "admin.h"
#include "user.h"
#include "db_customer.h"
#include "db_inventory.h"
#include "db_product.h"
#include "sqlite3.h"
#include "edit.h"
using namespace std;

string temp;

struct Node {
    string data;
    struct Node* next;
};

Node* head=NULL;


string printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        temp= n->data;
        n = n->next;
    }
    return 0;
}

//function for login menu
void loginmenu(){
    cout<<endl<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tTECHMART"<<endl<<endl;
    cout<<"1. Sign up"<<endl;
    cout<<"2. Login User "<<endl;
    cout<<"3. Login Admin"<<endl;
    cout<<"4. Exit"<<endl<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
}

//function for sign up page
void signup(){

    ofstream name, password;
    name.open("name.txt",ios::app);
    password.open("pw.txt",ios::app);
if (!name | !password){
        cout<< "File not created!";
    }
    else {
        cout<< "File  created succesdfully!";
    }

    string id, pw, email;

    cout<<""<<endl;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    cout<<"\tSIGNUP"<<endl<<endl;
    cout<<"User ID : ";
    cin>> id;
    name<< id<< endl;
    cout<<"Password : ";
    cin>> pw;
    password<< pw<< endl;
    cout<<"Email : ";
    cin>> email;
    cout<<"========================="<<endl;
    cout<<"========================="<<endl;
    
    name.close();
    password.close();
    
}

void push_back(string newElement) {
  
  Node* newNode = new Node();
  
  newNode->data = newElement;
  
  newNode->next = NULL; 
  
  if(head == NULL) {
    head = newNode;
  } else {
    Node* temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    
    temp->next = newNode;
  }    
}

int login_user(){

    ifstream name, password;

    vector <string> temp_name, temp_pw;
    string l_id, l_pw, id, pw;
    int i, n=0, p=0;

    head= new Node();

    LOGIN :
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

    name.open("name.txt",ios::in);
    
    for(n=0;n<21;n++){
        while (getline (name, id)){
            temp_name.push_back(id);
        }
    }
    /*
    for (auto i:temp_name){
        cout<< i << " ";
    }
    */   

    password.open("pw.txt",ios::in);

    for(p=0;p<21;p++){
    while (getline (password, pw)){
        push_back(pw);
        }
    }

    Node* temp = head->next;
    //check login detail
    while (temp != NULL){
    for( i=0;i<n;i++){
        if(temp_name[i] == l_id && temp->data == l_pw){
            cout<< "Login Successful!";
            return 0;
        }
    }
        temp= temp->next;
    }
    name.close();
    password.close();

    cout << "Failed! Please try again!"<<endl;
    goto LOGIN;
    
}

/*string printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        temp= n->data;
        n = n->next;
    }
    return 0;
}*/

bool login_admin(){
    string a_id = "admin",a_pw = "admin";
    string l_id, l_pw;

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


int main(){

    int choose, id, select;
    char user;
/*
    create_db_customer();
    create_db_inventory();
    create_db_product();
    insert_data_category();
    insert_data_product();
    insert_data_shop1();
    insert_data_shop2();
    insert_data_shop3();
    insert_data_total_sales();
    insert_data_supplier();
*/

    MENU:
    loginmenu();
    cin>>input;
    switch(input){
    case 1 :
        signup();
        goto MENU;

        break;
    
    case 2 :
            login_user();
            NEW :
            cout<< endl<<"Are you is a new user?(y/n)"<<endl;
            cin.clear();
            cin.ignore(9999,'\n');
            cin>> user;
            if (user == 'y' || user == 'Y'){
                new_user();
                
            }
            else if ( user == 'n' || user == 'N'){
                select_id();
                cout<< "Please select your ID."<<endl;
                cin.clear();
                cin.ignore(9999,'\n');
                cin>> id;
            }
            else{
                cout<<"Invalid input, please try again";
                goto NEW;
            }
            USER:
            user_page();
            cin.clear();
            cin.ignore(9999,'\n');
            cin >> input;
            switch(input){
                case 1 :
                    profile(id);
                    goto USER;
    
                case 2 :
                CATEGORY :
                    category();
                    cout<< "Please enter a number:";
                    cin.clear();
                    cin.ignore(9999,'\n');
                    cin>> input;
                    categoryProduct(input);
                    insert_order(id);
                    CONFIRM :
                    cout<< "Are you want to continue?(y/n)"<<endl;
                    cin>> user;
                    if (user == 'y' || user == 'Y'){
                        goto CATEGORY;
                    }
                    else if (user == 'n' || user == 'N'){
                        goto USER;
                    }
                    else{
                        cout<< "Invalid input, please try again."<<endl;
                        cin.clear();
                        cin.ignore(9999,'\n');
                        goto CONFIRM;
                    }

                case 3 :
                    CATALOGUE :
                    price_catalogue();
                    insert_order(id);
                    CONFIRM1 :
                    cout<< "Are you want to continue?(y/n)"<<endl;
                    cin>> user;
                    if (user == 'y' || user == 'Y'){
                        goto CATALOGUE;
                    }
                    else if (user == 'n' || user == 'N'){
                        goto USER;
                    }
                    else{
                        cout<< "Invalid input, please try again.";
                        goto CONFIRM1;
                    }
                    goto USER;

                case 4 :
                    select_shop();
                    cin.clear();
                    cin.ignore(9999,'\n');
                    cin>> input;
                    shopProduct(input);
                    insert_order(id);
                    CONFIRM2 :
                    cout<< "Are you want to continue?(y/n)"<<endl;
                    cin>> user;
                    if (user == 'y' || user == 'Y'){
                        goto CATALOGUE;
                    }
                    else if (user == 'n' || user == 'N'){
                        goto USER;
                    }
                    else{
                        cout<< "Invalid input, please try again.";
                        goto CONFIRM2;
                    }
                    goto USER;

                case 5 :
                    cart(id);
                    goto USER;

                case 6 :
                    cout<< "See you again. Bye!";
                    goto MENU;
        
                default :
                    cout<< "Invalid number! Please try again.";
                    goto USER;

            }
            break;
        
        goto MENU;

    case 3 : //goto admin page
        if (login_admin()){
            ADMIN :
            admin_page();
            cin >> input;
            switch(input){
                case 1 : // goto customer view
                    customer();
                    goto ADMIN;

                case 2 : // goto supplier view
                    supplier();
                    goto ADMIN;

                case 3 : // goto product view
                    product();
                    goto ADMIN;

                case 4 : // try to see the shop store
                CHOOSE:
                    select_shop();
                    cin.clear();
                    cin.ignore(9999,'\n'); //avoid looping error
                    cin>> choose;
                    switch (choose){
                        case 1 :
                            shop1();
                            goto ADMIN;

                        case 2 :
                            shop2();
                            goto ADMIN;

                        case 3 :
                            shop3();
                            goto ADMIN;

                        case 4 :
                            goto ADMIN;
                            
                        default:
                            cout<< "Invalid input, please try again!";
                            goto CHOOSE;
                            
                        }
                        break;

                case 5 : // edit page
                EDITPAGE:
                    select_edit();
                    cin>> input;
                    switch (input){
                        case 1 : // edit supplier
                            EDITACTION1 :
                            edit_action(); // select how to edit
                            cin>> input;
                            switch (input){
                                case 1 : // add function
                                    add_supplier();
                                    goto EDITPAGE;

                                case 2 : // update function
                                    supplier();
                                    update_supplier();
                                    goto EDITPAGE;

                                case 3 : // delete function
                                    supplier();
                                    delete_supplier();
                                    goto EDITPAGE;

                                case 4 :
                                    goto EDITPAGE;

                                default :
                                    cout<< "Invalid number! Please input again.";
                                    goto EDITACTION1;
                            }

                        case 2 : // edit product
                            EDITACTION2 :
                            edit_action(); // select how to edit
                            cin>> input;
                            switch (input){
                                case 1 : // add function
                                    add_product();
                                    goto EDITPAGE;

                                case 2 : // update function
                                    product();
                                    update_product();
                                    goto EDITPAGE;

                                case 3 : // delete function
                                    product();
                                    delete_product();
                                    goto EDITPAGE;

                                default :
                                    cout<< "Invalid number! Please input again.";
                                    goto EDITACTION2;
                            }

                        case 3 : // edit shop
                            EDITACTION3 :
                            edit_action(); // select how to edit
                            cin>> input;
                            switch (input){
                                case 1 : // add function
                                    SELECT1 :
                                    select_shop(); // select where the shop want edit
                                    cin>> input;
                                    switch (input){
                                        case 1 :
                                            add_shop(input);
                                            goto EDITPAGE;
                                        
                                        case 2 :
                                            add_shop(input);
                                            goto EDITPAGE;

                                        case 3 :
                                            add_shop(input);
                                            goto EDITPAGE;

                                        default:
                                            cout<< "Invalid number! Please input again.";
                                            goto SELECT1;

                                    }

                                case 2 : // update function
                                    SELECT2 :
                                    select_shop(); // select where the shop want edit
                                    cin>> input;
                                    switch (input){
                                        case 1 :
                                            shop1();
                                            update_shop(input);
                                            goto EDITPAGE;
                                        
                                        case 2 :
                                            shop2();
                                            update_shop(input);
                                            goto EDITPAGE;

                                        case 3 :
                                            shop3();
                                            update_shop(input);
                                            goto EDITPAGE;

                                        default:
                                            cout<< "Invalid number! Please input again.";
                                            goto SELECT2;

                                    }

                                case 3 : // delete function
                                SELECT3 :
                                    select_shop(); // select where the shop want edit
                                    cin>> input;
                                    switch (input){
                                        case 1 :
                                            shop1();
                                            delete_shop(input);
                                            goto EDITPAGE;
                                        
                                        case 2 :
                                            shop2();
                                            delete_shop(input);
                                            goto EDITPAGE;

                                        case 3 :
                                            shop3();
                                            delete_shop(input);
                                            goto EDITPAGE;

                                        default:
                                            cout<< "Invalid number! Please input again.";
                                            goto SELECT3;

                                    }

                                default :
                                    cout<< "Invalid number! Please input again.";
                                    goto EDITACTION3;

                            }

                        case 4:
                            goto ADMIN;

                        default:
                            goto EDITPAGE;
                    }

                case 6 : //report function
                    report();
                    goto ADMIN;

                case 7 :
                    cout<< "Thank You!"<< endl;

                break;

                default :
                cout<< "Invalid number! Please input again.";
                goto ADMIN;
                        }
                break;
        }
        goto MENU;

    case 4 :
        cout<< "See you again. Bye!";
        exit(0);

    default :
        cout<< "Invalid number! Please try again.";
        goto MENU;
    }

}