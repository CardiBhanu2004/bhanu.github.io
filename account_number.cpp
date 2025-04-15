///
#include<iostream>
#include<string>
#include<vector>
using namespace std;
// Base class for bank account
class Account {
    protected:
        string Account_Number;
        double Balance;
    public:
        Account(string accNum, double initialbal): Account_Number(accNum), Balance(initialbal){}
        
        virtual void deposit(double amount) {
            Balance += amount;
        }
        virtual void withdraw(double amount) {
            if(Balance >= amount) {
                Balance -= amount;
            }
            else {
                cout << "Insufficient balance" << endl;
            }
        }
        double getBalance() const{
            return Balance;
        }
        virtual void display() const {
            cout << "Account Number: " << Account_Number << endl;
            cout << "Balance: " << Balance << endl;
        }
};
//Derived class for savings account
class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        SavingsAccount(string accNum, double initialbal, double rate): Account(accNum, initialbal), interestRate(rate){}
        void addInterest(double amount) {
            Balance += amount * interestRate;
        }
        void display() const override{
            Account::display();
        }
};
//Funtion to display account details
void displayAccountDetails(const Account &acc) {
    acc.display();
}
int main()
//create a savings account object
{
    SavingsAccount saving("SA1234",1000.0,0.05);
    //perform tansactions
    saving.deposit(500.0);
    saving.withdraw(200.0);
    //Display account details
    displayAccountDetails(saving);
    //Add interest and display update details
    saving.addInterest(saving.getBalance());
    displayAccountDetails(saving);
    return 0;
}
