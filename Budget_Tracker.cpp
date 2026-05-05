
#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;
 
class BudgetAccount {
private:
    double monthlyBudget;
    double totalSpent;
    string ownerName;
 
public:
    BudgetAccount() {
        ownerName = "Unknown";
        monthlyBudget = 0.0;
        totalSpent = 0.0;
    }
 
    BudgetAccount(string name, double budget) {
        ownerName = name;
        monthlyBudget = budget;
        totalSpent = 0.0;
    }
 
    void setOwnerName(string name) {
        this->ownerName = name;   
    }
 
    void setMonthlyBudget(double budget) {
        monthlyBudget = budget;
    }
 
    void setTotalSpent(double spent) {
        totalSpent = spent;
    }
 
    // Getters
    string getOwnerName() const {
        return ownerName;
    }
 
    double getMonthlyBudget() const {
        return monthlyBudget;
    }
 
    double getTotalSpent() const {
        return totalSpent;
    }
 
    void addExpense(double amount) {
        if (amount > 0) {                    
            totalSpent += amount;
        }
    }
 
    double getRemainingBalance() const {
        return monthlyBudget - totalSpent;
    }
 
    bool isOverBudget() const {
        return totalSpent > monthlyBudget;
    }
 
    void printSummary() const {
        cout << fixed << setprecision(2);
        cout << "Budget Summary for: " << ownerName << endl;
        cout << "Monthly Budget: $" << monthlyBudget << endl;
        cout << "Total Spent: $" << totalSpent << endl;
        cout << "Remaining Balance: $" << getRemainingBalance() << endl;
 
        if (isOverBudget()) {
            cout << "Status: Over budget!" << endl;
        } else {
            cout << "Status: Within budget" << endl;
        }
    }
};
 
int main() {
    BudgetAccount account;     // Start with default account
    bool hasAccount = false;   
    int choice;
 
    cout << "==========================================" << endl;
    cout << "     Personal Budget Tracker" << endl;
    cout << "==========================================" << endl;
 
    do {
        cout << "\nPersonal Budget Menu" << endl;
        cout << "========================================" << endl;
        cout << "1. Set up budget account" << endl;
        cout << "2. Add an expense" << endl;
        cout << "3. View summary" << endl;
        cout << "4. Quit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
 
        if (choice == 1) {
            // Set up / update budget account
            string name;
            double budget;
 
            cout << "Enter your full name: ";
            cin.ignore();                    
            getline(cin, name);
 
            cout << "Enter your monthly budget: $";
            cin >> budget;
 
            account.setOwnerName(name);
            account.setMonthlyBudget(budget);
            account.setTotalSpent(0.0);      
 
            hasAccount = true;
            cout << "Budget account created successfully!" << endl;
 
        } 
        else if (choice == 2) {
            if (!hasAccount) {
                cout << "Please set up your budget account first." << endl;
            } else {
                double amount;
                cout << "Enter expense amount: $";
                cin >> amount;
 
                account.addExpense(amount);
                cout << "Expense added!" << endl;
                cout << "Remaining balance: $" 
                     << fixed << setprecision(2) 
                     << account.getRemainingBalance() << endl;
            }
        } 
        else if (choice == 3) {
            if (!hasAccount) {
                cout << "Please set up your budget account first." << endl;
            } else {
                account.printSummary();
            }
        } 
        else if (choice == 4) {
            cout << "\nGoodbye! Thank you for using the Personal Budget Tracker." << endl;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
 
    } while (choice != 4);
 
    return 0;
}