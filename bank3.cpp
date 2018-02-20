#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void current();
class Account{
	protected:
		string name;
		long int ID;
		double balance, depositAmount,initial;
	public:
		Account();
		void deposit();
		double checkBalance();
		void withdraw();
		
};

Account :: Account(){
	cout <<"Enter Account Holder's name :"<<endl;
    cin>>name;
	cout<<"Enter ID Number"<<endl;
	cin>>ID;
	cout<<"Insert Opening balance"<<endl;
	cin>>balance;
	if(balance < 5000){
		do{ 
			cout<<"Warning ! Opening balance must be 5k or more"<<endl;
			cin>>balance;
		}while(balance < 5000);
	}
	initial = balance;
}

void Account :: deposit(){
	cout<<"Enter Amount to deposit "<<endl;
	cin>>depositAmount;
	cout<<"You deposited :"<<depositAmount<<endl;
	balance = balance + depositAmount;
    cout<<"Your new balance is :"<<balance<<endl;
    
}
double Account :: checkBalance(){
	cout<<"The balance is "<<balance<<endl;
}
class Savings : public Account {
	protected:
		double interest, withdrawalAmount;
	public:
	   void withdraw();
	   void computeInterest();
	   void printReceipt();
};

class Current : public Account{
	protected: 
	    double Overdraft, withdrawalAmount;
	public:
		void withdraw();
};
void Savings :: printReceipt(){
	ofstream Receipt;
	Receipt.open("receipt.txt");
	
	//check if there is a file to write to
	if(Receipt.is_open()){
		Receipt
		<<"***************************************************" << endl
        << " Receipt for "<<name<<"    ID NO:"<<ID << endl
        << "***************************************************" << endl
        <<" Initial balance: "<<initial<< endl;
        //set max no of transactions to 10
        int count = 1, defaultAmount = 0;
        if(depositAmount){
        	Receipt<<count<<" +Deposit: "<<depositAmount<<endl;
        	count ++;
		}else{
			Receipt<<" +Deposit: 0"<<endl;
			count++;
		}
	
		if(withdrawalAmount){
			Receipt<<count<<" -Withdraw: "<<withdrawalAmount<<endl;
			count ++;
		}
		else if(!withdrawalAmount){
			Receipt<<count<<" -Withdraw: "<<defaultAmount<<endl;
			count ++;
		}
        Receipt<<" Your Account balance is :"<<balance<<endl;
        Receipt.close();
	}
	
}
void Savings :: withdraw(){
	cout<<"Enter amount you wish to withdraw "<<endl;
	cin>>withdrawalAmount;	
	if( withdrawalAmount > balance){
		cout<<"You dont have enough money!\n\n"<<endl;
		cout<<"Your balance is :"<<balance<<endl;
	 	do{
	       cout<<"Enter an amount lesser or equal to your balance!"<<endl;
		   cin>>withdrawalAmount;
		}while( withdrawalAmount > balance);
		
	}
	balance = balance - withdrawalAmount;
	cout<<"Your balance is :"<<balance<<endl;
}

void Savings :: computeInterest(){
	int time;
	float rate= 0.07, interest;
	cout<<"Enter length of time in years "<<endl;
	cin>>time;
	interest = balance * rate * time;
	balance = balance + interest;
	cout<<"The new balance with interest is :"<<balance<<endl;
}
void Current :: withdraw(){
	Overdraft = 2 * balance;
	cout<<"Enter amount you wish to withdraw "<<endl;
	cin>>withdrawalAmount;
	if(withdrawalAmount > Overdraft){
	do{
		cout<<"Enter Amount lesser or equal to your overdraft\n"<<endl;
		cout<<"Your overdraft is : "<<Overdraft<<endl;
		cin>>withdrawalAmount;
	} while(withdrawalAmount > Overdraft);	
	}
	balance = balance - withdrawalAmount;
	cout<<"Your balance is "<<balance<<endl;
	
}
void savings(){
int choice;
	  Savings S;
	  do{
	  cout<<"\t*****What do you want to do?******"<<endl;
	  cout<<"\t\t1. Check Balance"<<endl;
	  cout<<"\t\t2. Deposit into Account"<<endl;
	  cout<<"\t\t3. Withdraw cash"<<endl;
	  cout<<"\t\t4. Print Account balance"<<endl;
	  cout<<"\t\t5. Compute Interest "<<endl;
	  cout<<"\t\t Press 0 to Exit"<<endl;
	  cin>>choice;
	  switch(choice){
	   case 0: cout<<"Till Next Time!"<<endl;
	   case 1:  S.checkBalance();break;
	   case 2:  S.deposit();break;
	   case 3:  S.withdraw();break;
	   case 4: S.printReceipt();
	           cout<<" Check Receipt at the C:/Users/OGONYO/Documents/CS/CPP directory"<<endl;break;
	   case 5: S.computeInterest();break;
	   default:cout<<"Invalid Choice.Try Again!"<<endl; 
	           savings();      
	} }while( choice != 0);	
 };
 void current(){
 	int choice;
 	Current C;
 	do{
 	cout<<"\t******What do you want to do?**********"<<endl;
	  cout<<"\t\t1. Check Balance"<<endl;
	  cout<<"\t\t2. Deposit into Account"<<endl;
	  cout<<"\t\t3. Withdraw cash"<<endl;
	  cout<<"\t\t4. Print Account Balance"<<endl;
	  cout<<"\t\t5. Press 0 to Exit! "<<endl;
	  cin>>choice;
	  switch(choice){
	   case 1:  C.checkBalance();break;
	   case 2:  C.deposit();break;
	   case 3:  C.withdraw();break;
	   default: cout<<"Invalid Choice!";
	            current();            
	}}while(choice != 0); 	
 	
 }

int main(){
  cout<<"Create account before proceeding! "<<endl;
  int option;
  cout<<"What type of account do you want to open?"<<endl;
  cout<<"\t 1. Savings A/c"<<endl;
  cout<<"\t 2. Current A/c"<<endl;
  cin>>option;
  switch(option){
  	case 1: savings();break;
  	case 2: current();break;
  	default: cout<<"Invalid Choice!"<<endl;
  	         main();
	         return 0;
  }	    
 }
