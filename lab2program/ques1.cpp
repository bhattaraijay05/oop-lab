// Assume that a bank maitains two kinds of accounts for customers,one called as savings account and the other as current account. The saving account provides compound interest and withdrawal facilities but no cheque book facility. The current account provides cheque book facility but no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed.  Class account stores customer name, account number and the type of account.
//          Include member functions:-
// Accept deposit from a customer and update the balance
// Display the balance
// Compute and deposit interest
// Permit withdrawal and update balance
// Check for minimum balance, impose penalty and update the balance
// Include constructors in all the classes

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Account
{
public:
    string customerName, typeOfAccount;
    int accountNumber, balance;
    Account(string cname, string account, int accNumber, int bal)
    {
        customerName = cname;
        typeOfAccount = account;
        accountNumber = accNumber;
        balance = bal;
    }
    Account() : customerName("NULL"), typeOfAccount("NULL"), accountNumber(0), balance(0){};
    void enterData();
    void displayBalance();
    void depositBalance();
};

void Account::enterData()
{
    cout << "\n Enter customer name" << endl;
    cin >> customerName;
    cout << "\n Enter account number" << endl;
    cin >> accountNumber;
    cout << "\n Enter account type" << endl;
    cin >> typeOfAccount;
    cout << "\n Enter balance" << endl;
    cin >> balance;
}

void Account::displayBalance()
{
    cout << "\n Customer Name " << customerName;
    cout << "\n Account Number " << accountNumber;
    cout << "\n Type " << typeOfAccount;
    cout << "\n The balance is: " << balance;
}

void Account::depositBalance()
{
    int amount;
    cout << "\n Enter the amount to deposit" << endl;
    cin >> amount;
    balance = balance + amount;
}

class SavingsAccount : public Account
{
    int interest;

public:
    SavingsAccount(string cname, string account, int accNumber, int bal, int intr) : Account(cname, account, accNumber, bal)
    {
        interest = intr;
    }
    SavingsAccount() : interest(0){};
    int compoundInterest()
    {
        int time, rate;
        rate = 10;
        cout << "\n Enter time" << endl;
        cin >> time;
        interest = balance * pow(1 + rate / 100.0, time) - balance;
        return interest;
    }
    void updateBalance()
    {
        balance = balance + compoundInterest();
        cout << "The balance is: " << balance << endl;
    }
    void withdrawal()
    {
        int amount;
        cout << "\n Enter amount to withdrawn" << endl;
        cin >> amount;
        if (balance >= amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "\n The amount cannot be withdrawn" << endl;
        }
    }
};
class CurrentAccount : public Account
{
    int checkBook, serviceCharge;
    int minBalance = 500;

public:
    CurrentAccount(string cname, string account, int accNumber, int bal, int intr) : Account(cname, account, accNumber, bal)
    {
        checkBook = intr;
    }
    CurrentAccount() : checkBook(0){};

    int mainBalance()
    {
        int penalty = 1;
        if (balance <= minBalance)
        {
            serviceCharge = 50;
            balance = balance - serviceCharge;
            penalty = 0;
        }
        else
        {
            cout << "\n No service charge " << endl;
        }
        return penalty;
    }
    void withdrawal()
    {
        int amount;
        cout << "\n Enter the amount to withdrawn" << endl;
        cin >> amount;
        int checkPenalty = mainBalance();
        if (checkPenalty == 1)
        {
            if (balance >= amount)
                balance = balance - amount;
        }
        else
        {
            cout << "\n The amount cannot be withdrawn" << endl;
        }
    }
};

int main()
{
    SavingsAccount s1;
    CurrentAccount c1;
    s1.enterData();
    s1.displayBalance();
    s1.depositBalance();
    s1.displayBalance();
    s1.updateBalance();
    s1.withdrawal();
    s1.displayBalance();
    c1.enterData();
    c1.displayBalance();
    c1.depositBalance();
    c1.displayBalance();
    c1.withdrawal();
    c1.displayBalance();
    return 0;
}