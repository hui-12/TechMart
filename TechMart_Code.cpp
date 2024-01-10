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
#include "Database.h"

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
    cout<<"2. Login User"<<endl;
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

bool login_user(){

    ifstream name, password;

    vector <string> temp_name, temp_pw;
    string l_id, l_pw, id, pw;
    int i, n=0, p=0;

    head= new Node();


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
            return true;
        }
        temp= temp->next;
    
    }
    }
    name.close();
    password.close();

    cout << "Failed! Please try again!"<<endl;
    return false;
    
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

    int choose;

    MENU:
    loginmenu();
    cin>>input;
    switch(input){
    case 1 :
        signup();
        goto MENU;

        break;
    
    case 2 :
        if (login_user()){
            USER:
            user_page();
            cin >> input;
            switch(input){
                case 1 :
                    profile();
                    goto USER;
    
                case 2 :
                    /*if (category()){
                        user_page();
                        }*/
                    goto USER;

                case 3 :
                    /*if (price_catalogue()){
                        admin_page();
                        }*/
                    goto USER;

                case 4 :
                    //order();
                    goto USER;

                case 5 :
                    cout<< "See you again. Bye!";
                    goto MENU;
        
                default :
                    cout<< "Invalid number! Please try again.";
                    goto USER;

            }
            break;
        }

        goto MENU;

    case 3 :
        if (login_admin()){
            ADMIN :
            admin_page();
            cin >> input;
            switch(input){
                case 1 :
                    customer();
                    goto ADMIN;

                case 2 :
                    supplier();
                    goto ADMIN;

                case 3 :
                    product();
                    goto ADMIN;

                case 4 :
                CHOOSE:
                    select_shop();
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
                            
                        default:
                            cout<< "Invalid input, please try again!";
                            goto CHOOSE;
                            
                    }
                break;

                case 5 :

                break;

                case 6 :
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