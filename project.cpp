
#include<bits/stdc++.h> 
#include "windows.h" // for Sleep function
using namespace  std; 
#define endl '\n'; 
#define ll long long int 
#define llu unsigned long long int 
  

class BankAccount {
    public:
        string account_holder, address, email, phone;
        int age, account_number;
       
    protected: 
        int balance;
    private: 
        string  password; 
    public:  
       BankAccount(string account_holder, string address, int age, string password, string emial, string phone);
        int show_balance(string password); 
        void add_money(string password, int amount); 
        void withdraw_money(string password, int amount);  
        int get_rand(); 
        void my_balance(string password);
        bool check_password(string password); 
        bool check_age(int age);
        bool check_mail(const string &email); 
        bool check_phone(const string &phone);
        void submit_button(); 

        friend class MyCash;  // to access private component.. 
       
};



class MyCash {
    protected: 
        int balance; 
    public:  
        MyCash() {        
            this->balance = 0;
        }

        void add_money_from_bank(BankAccount *myAccount, string password, int amount);
        int get_balance();
}; 


int MyCash :: get_balance()  {
    return balance;
}


// Deposite money from Bank...
void add_money_from_bank(MyCash *myCash, BankAccount *myAccount) {
        string password; 
        int amount; 
        cout<< "Add Money From Bank" << endl; 
        cout<<"Enter Your Password: "; cin>> password; 
        cout<<"Enter Your Amount: "; cin>> amount; 
        myCash->add_money_from_bank(myAccount, password, amount);
    //    cout<<"Your Balance is: "<< myAccount->show_balance(password) << endl;
       cout << "MyCash Balance is: " << myCash->get_balance() << endl;

} 


void MyCash :: add_money_from_bank(BankAccount *myAccount, string password, int amount)  { 
     if(amount <= 0) {
        cout<<"Invalid Amount!!" << endl;  
        this->balance = 0;
        return;
     }


     if(myAccount->balance < amount) {
        cout<< "Insufficient Balance!!" << endl;
     }

     if(myAccount->password == password) {
                this->balance += amount; 
                myAccount->balance -= amount; 
                cout << "Add Money From Bank Successful" << endl;
    }
    
    else {
        cout<< "Your Password Didn't Match!!"<< endl; 
    }
    
     
}



//*********************************
/// Bank Account classs functions..   
//*********************************
 
//Create Bank account function....
BankAccount *create_account() {
    string account_holer, password, address, email, phone; 
    int age; 
    string village, Uni, thana, distr, nid;
    
    cout<< "\t\t\t Welcome To Teach Army Bank.\t\t\t";
    cout<<"\t\t\t ===========================\t\t\t"; 
    cout<< endl;
    
//==================================================
// Login  function.. 
//==================================================
    int choice,i,exit=0;
    string usn,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    
    while(exit==0)
    {
        cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this).\n2. SignUp/Register(press 2 to select this).\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username:";
            cin>>usn;
            cout<<"Enter your password:";
            cin>>psd;
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
                cout<<"User-name:"<<usern<<endl;
                cout<<"Name:"<<line<<endl;
                getline(filei,line);
                // cout<<"Bio:"<<line<<endl;
                // filei.close();
            }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
                    
            // cout<< "****Create Your Account***" << endl ;
            cout<<"Enter Account Holder Full Name: ";  
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin, account_holer);
            cout<<"Please Give Your Present Address" << endl;  
            
            cout<< "\t1. Enter your Village: "; cin>> village;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\t2. Enter your Union: " ; cin>> Uni; 
            cout<<"\t3. Enter Your Thana: "; cin>> thana;
            cout<< "\t4. Enter Your Distr: "; cin>> distr;  
            cout<<"\t5. Enter Your NID: "; cin>> nid;
        
            cout<< "Enter Your Age: "; cin >> age; 
            cout<< "Enter Your E-mail: "; 
            cin>> email; 
            cout<<"Enter Your phone number:  "; 
            cin.ignore();
            cin>> phone;  
            cout<<"Enter Your Password(4-8 character): "; cin>> password; 
            BankAccount *myAccount = new BankAccount(account_holer, address, age, password, email, phone); 
            return myAccount;
           
        }
        else
        {
            exit=1;
        }
    }
  
}

 
// Generate the 8 digit random num for account number...
int BankAccount :: get_rand()  {

    // init rand speed..  
    srand(time(nullptr)); 
    for(int i=0; i<10; i++) {
        this->account_number = 0; 
        for(int j=0; j<8; j++) { 
            int currDigit = rand() %10;
            currDigit *= pow(10, j);
            this->account_number += currDigit;
        }
    }

    return this->account_number;

}
 

//Money deposite to bank...
void add_money(BankAccount *myAccount) { 
    string password; 
    int amount; 

    cout<< "Add Money" << endl;  
    cout<<"Enter Your Password: "; cin>> password; 
    cout<<"Enter Your Amount: "; cin>> amount; 

    myAccount->add_money(password, amount);
    // cout<<"Your Balance is: "<< myAccount->show_balance(password) << endl;

}


void BankAccount :: add_money(string password, int amount)  {
    if(amount <= 0)  {
        cout<< "Invaild amount!!"<< endl; 
        return;
    }

    if(this->password == password) {
        this->balance += amount;
        
        cout <<"Progreessing......" << endl;
        Sleep(2000); // dealy for 2000 ms or 2 seconds..
        cout<< "Add Money Successful"<< endl;
    } 
    else {
         cout<< "Your Password Didn't Match!!"<< endl; 
    }
        
}



// money withdraw from bank....
void withdraw_money(BankAccount *myAccount) { 
    string password; 
    int amount; 
    cout<<"Withdraw Money" << endl; 
    cout<<"Enter Your Password: "; cin>> password; 
    cout<<"Enter Your Amount: "; cin>> amount; 
    myAccount->withdraw_money(password, amount); 
    //   cout<<"Your Balance is: "<< myAccount->show_balance(password) << endl;
}


void BankAccount :: withdraw_money(string password, int amount) {
    if(amount <= 0) {
        cout<< "Invalid Amount!!" << endl; 
        this->balance = 0;
        return; 
    }


    if(this->balance < amount) {
        cout<< "Insufficient Balance!!" << endl; 
        return;
    }

  
    if(this->password == password) {
        this->balance -= amount;  
        
        cout <<"Progreessing......" << endl;
        Sleep(2000); // dealy for 3000 ms or 3 seconds..
        cout<<"Withdraw Successful" << endl;
    } 
    else 
        cout<<"Your Password Didn't Match!!!" << endl;
}


// check password valid or not...
bool BankAccount :: check_password(string password) {
    if(!((password.length() >=4) && (password.length() <= 8) || (password.find(" ") != string :: npos)))  
        return false;
    
    return true;
    // to check space... 
    // if(password.find(" ") != string :: npos) return false; 

}


// check age valid or not..
bool BankAccount :: check_age(int age) {
    return (!(age >=18)) ?  false : true;
}
 

// check mail valid or not...
bool BankAccount :: check_mail(const string &email) {
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  
    // Match the string pattern
    // with regular expression
    return regex_match(email, pattern);
}


// check phone number valid or not...
bool BankAccount :: check_phone(const string &phone) {
    const regex pattern("(0|1)?[3-9][0-9]{9}"); 
    return regex_match(phone, pattern);

}
 



// Bank Account functon...(check all authentication function)...
BankAccount ::  BankAccount(string account_holder, string address, int age, string password, string emial, string phone) { 
    this->account_holder = account_holder; 
    this->address = address; 
    this->age = age; 
    this->email = emial;
    this->phone = phone; 
    this->password = password; 
    this->balance = 0;

    if(!(check_age(this->age))) {
        cout<<"You are under 18. You can't create account!!" << endl;
        cout<<"Please Enter Your valid Age: "; 
        cin>> this->age;
        
    }

    if(!(check_mail(this->email))) {
        cout<<"Invalid E-mail!!" << endl;
        cout<<"Please Enter Your Valid E-mail: "; 
        cin>> this->email; 
    }

    if(!(check_phone(this->phone))) {
        cout<<"Invalid Phone Number!!" << endl;
        cout << "Please Enter Your Valid Phone Number: ";
        cin>> this->phone;
    }

    if(!(check_password(this->password)))  {
        cout<<"Invalid Password!!!"<< endl;  
        cout<<"Please Enter Your Valid Password: ";
         cin>> this->password;
         
    } 
    
    // loggedIn();
    submit_button();
   
 
}

 
 
// Show bank account balance...
int BankAccount :: show_balance(string password)  {
        if(this->password == password)  
            return this->balance; 
        else return 0; 
}




void BankAccount :: my_balance(string password) {
     if(this->password == password) {
             cout<<"Your courrent Balance: " << this->balance << endl;
     } 
     else 
        cout<<"Your Password Didn't Match!!!"<< endl;
}


// show myCash balance...
void my_balance(BankAccount *myAccount) {
    string password; 
    cout<<"Enter Your Password: "; cin>> password;
    myAccount->my_balance(password);
    
}


// submit function...
void BankAccount :: submit_button() {
    cout<<"Submit: " << endl; 
    string str; 
    cout<<"\t1. Yes"<< endl;
    cout<<  "Please Enter (Yes or yes) to Submit: ";  
    cin>> str;

    if(str == "Yes" || str == "yes")  {
         cout<<"\n\nCongratulatoins! Your Account Successfully Created."<< endl;
         cout<< "Your Account Number is: 22" <<this->get_rand() << endl; 
    } 

    else {
            cout<<"Didn't Find Your Account"<< endl;
            return;
    }


}

 

int main() {
    
    
    BankAccount *myAccount = create_account();  
    MyCash *myCash = new MyCash();
    // add_money(myAccount);
    // deposit_money(myAccount); 
    // add_money_from_bank(myCash, myAccount); 
    // myAccount->submit_button();
      
    while(true) {
        cout<<"\n\nSelect Your Option: "<< endl; 
        cout<<"\t1. Add Money to Bank" << endl; 
        cout<<"\t2. Withdraw Money From Bank" << endl;  
        cout<< "\t3 Add Money to MyCash From Bank" << endl; 
        cout<<"\t4. My Balance" << endl;
        cout<<"\t5. Exit" << endl;  

        int option; cin>>option; 
        if(option == 1) 
            add_money(myAccount);
        else if(option == 2)  
            withdraw_money(myAccount);
        else if(option == 3) 
            add_money_from_bank(myCash, myAccount);
        else if(option == 4) 
               my_balance(myAccount);
        else if(option == 5)  
            cout << "Exit\n"; 
        else 
         cout <<"Invalid Option" << endl;

    }
     

    return 0;


}
