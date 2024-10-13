#include<iostream>
using namespace std;


class Customer{
	public:
		int customer_id;
		string customer_name;
		string customer_email;
		
		
		Customer()
		{
			customer_id=0;
			customer_name='\0';
			customer_email='\0';
		}
		Customer(int id, string name, string email)
		{
			customer_id=id;
			customer_name= name;
			customer_email=email;
		}
		//displaying the data related to customer
		void display()
		{
			cout<<"customer ID:"<<customer_id<< endl;
			cout<<"customer Name:"<<customer_name<< endl;
			cout<<"customer Email:"<<customer_email<< endl;
		}
};


//transaction class -->> if customer wants to withdraw of deposit or want to see his balance in the account
class transaction{
	private:
		double balance=0;
	public:
		transaction()
		{
            balance= 0.0; 			
		}
		transaction(double bal)
		{
			balance = bal;
		}
		void deposit(double amount)
		{
		if (amount > 0) 
		{
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } 
		else 
		{
            cout << "Deposit amount must be positive." << endl;
        }
		}
		
		
	    void withdraw(double amount) 
		{
        if (amount > 0 && amount <= balance) 
		{
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } 
		else 
		{
            cout << "Withdrawal amount must be positive." << endl;
        }
        }
        
//tranfer amount        
void transfer(transaction &to_account, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            to_account.deposit(amount);
            cout << "Transferred: " << amount << " to another account. New Balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance for transfer!" << endl;
        } else {
            cout << "Transfer amount must be positive." << endl;
        }
    }
        //display funstion        
        void display(){
        	cout<<"Balance is:"<<balance <<endl;
		}

};

int main()
{
	Customer acc1(1001, "Najam Irfan", "najamb124@gmail.com");
	Customer acc2(1327, "Abu Huraira", "ebuhuraira@gmail.com");


    //DEPOSIT
	transaction t1(100000.00); //amount deopist to account 1
	transaction t2(5000.00);   // amount deposit to account 2
    
    cout<<"\t\tAccount Details\n";
	acc1.display();
	t1.display();
	cout<<"\n";
	acc2.display();
	t2.display();
	
		
	//WITHDRAW
	cout<<"\t\tWithdrawfrom account 1:\n";
    t1.withdraw(2000.00);//withdraw amount from account 1
    cout<<"\t\tWithdrawfrom account 2:\n";
	t2.withdraw(500.00);//withdraw amount from account 2
	
	//TRANSFER
	cout<<"\n\t\tAmount Tranfer from account 1 to account 2:\n";
	t1.transfer(t2, 7000.00);
	
	
	cout<<"\n";
	acc1.display();
	t1.display();
	cout<<"\n";
	acc2.display();
	t2.display();
	
	
return 0;	
}
