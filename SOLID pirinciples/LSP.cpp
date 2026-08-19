#include <iostream>
#include <vector>
#include <typeinfo> 
#include <stdexcept> 

using namespace std;

class DepositOnlyAccount {
    public: 
    virtual void deposit(double amount) =0;
};
class WithdrawableAccount : public DepositOnlyAccount{
    public: 
    virtual void withdraw(double amount) =0;
}
;
class SavingsAccount : public WithdrawableAccount{
    private: 
    double balance;
    public:
    SavingsAccount(){
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
}
;
;
class CurrentAccount : public WithdrawableAccount{
    private:
    double balance;
    public:
    CurrentAccount(){
        balance = 0;
    }
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }
    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }

}
;
class fixedDepositAccount : public DepositOnlyAccount{
    private:
    double balance;
    public:
    fixedDepositAccount(){
        balance = 0;
    }
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
}
;
class BankClient{
    private: 
    vector<DepositOnlyAccount*> depositonlyaccounts;
    vector<WithdrawableAccount*> withdrawableaccounts;

    public:
    BankClient(vector<DepositOnlyAccount*> depositonlyaccounts, vector<WithdrawableAccount*> withdrawableaccounts){
        this->depositonlyaccounts = depositonlyaccounts;
        this->withdrawableaccounts = withdrawableaccounts;

    }

    void processTransactions(){
        for(WithdrawableAccount* account : withdrawableaccounts){
            account->deposit(1000);
            account->withdraw(500);
        }
        for(DepositOnlyAccount* account : depositonlyaccounts){
            account->deposit(5000);
        }
    }

}

;


int main(){
    vector<WithdrawableAccount*> withdrawableaccounts;
    withdrawableaccounts.push_back(new SavingsAccount());
    withdrawableaccounts.push_back(new CurrentAccount());
    vector<DepositOnlyAccount*> depositonlyaccounts;
    depositonlyaccounts.push_back(new fixedDepositAccount());

    BankClient* client = new BankClient (depositonlyaccounts, withdrawableaccounts);
    client->processTransactions();
    return 0;
}