#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

class atm{
    private:
        long long account_No;
        string name;
        int Pin;
        double balance;
        string mobile_No;
    public:
        void setData(long long int account_No_a,string name_a,int Pin_a,double balance_a,string mobile_No_a){
            account_No=account_No_a;
            name = name_a;
            Pin=Pin_a;

            balance=balance_a;
            mobile_No=mobile_No_a;
        }
        long long int getAccountNo(){
            return account_No;
        }
        string getName(){
            return name;
        }
        int getPin(){
            return Pin;
        }
        double getBalance(){
            return balance;
        }
        string getMobileNo(){
            return mobile_No;
        }
        void setMobile(string mob_prev,string mob_new){
            if(mob_prev==mobile_No){
                cout<<endl<<"Succesfully Updated Mobile no.";
                _getch();
            }
            else{
                cout<<endl<<"Incorrect !!! Old Mobile No.";
                _getch();
            }
        }
        void cashWithDraw(int amount_a){
            if(amount_a > amount_a < balance){
                balance-=amount_a;
                cout<<endl<<"Please Collect Your Cash";
                cout<<endl<<"Availabel Balance:"<< balance;
                _getch();
            }
            else{
                cout<<endl<<"Invalid Input or Insufficient Balance";
                _getch();
            }
        }
};
int main(){
    int choice =0;
    int enterPin;
    long long enterAccountNo;
    system("cls"); //used to clear the screen
    atm user1;
    user1.setData(1234567,"Tim",1111,45000.90,"9889754519");
    do{
        system("cls");
        cout<<endl<< "****WELCOME TO ATM****"<<endl;
        cout<<endl<<"Enter Your Account No. ";
        cin>>enterAccountNo;
        cout<<endl<<"Enter PIN ";
        cin>>enterPin;

        if((enterAccountNo==user1.getAccountNo()) && (enterPin==user1.getPin())){
            do{
                int amount=0;
                string oldMobileNo,newMobileNo;
                system("cls");
                cout<<endl<<"****WELCOME TO ATM****"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show User Details";
                cout<<endl<<"4. Update Mobile No.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;
                switch(choice){
                    case 1:
                        cout<<endl<<"Your Bank balance is:"<<user1.getBalance();
                        _getch();
                        break;
                    case 2:
                        cout<<endl<<"Enter the amount:";
                        cin>>amount;
                        user1.cashWithDraw(amount);
                        break;
                    case 3:
                        cout<<endl<<"***User Details are:- ";
                        cout<<endl<<"-> Account No"<<user1.getAccountNo();
                        cout<<endl<<"-> Name      "<<user1.getName();
                        cout<<endl<<"-> Balance   "<<user1.getBalance();
                        cout<<endl<<"-> Mobile No."<<user1.getMobileNo();
                        _getch();
                        break;
                    case 4:
                        cout<<endl<< "Enter Old Mobile No. ";
                        cin>>oldMobileNo;
                        cout<<endl<<"Enter the New Mobile No. ";
                        cin>>newMobileNo;
                        user1.setMobile(oldMobileNo,newMobileNo);
                        break;
                    case 5:
                        exit(0);
                    default:
                        cout<<endl<<"Enter Valid Data !!!";
                }
            }while(1);
        }
        else{
            cout<<endl<<"User Details are Invalid !!!";
            _getch();
        }
    }while(1);
    return 0;
}