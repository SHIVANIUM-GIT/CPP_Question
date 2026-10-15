#include <iostream>
#include <vector>
#include <memory>

// 1. ABSTRACTION: Interface defining what an account does, without exposing details
class IAccount {
public:
 virtual void deposit(double amount) = 0;
 virtual bool withdraw(double amount) = 0;
 virtual void printStatement() const = 0;
 virtual ~IAccount() = default;
};

// 2. ENCAPSULATION & 3. INHERITANCE: Base account implementation
class BankAccount : public IAccount {
private:
 // Encapsulated data: Cannot be directly corrupted from outside
 double balance;
 int accountNumber;

protected:
 double getBalance() const { return balance; }

public:
 BankAccount(int accNum, double initialBalance) 
 : balance{initialBalance}, accountNumber{accNum} {}

 void deposit(double amount) override {
 if (amount > 0) balance += amount;
 }

 bool withdraw(double amount) override {
 if (amount > 0 && balance >= amount) {
 balance -= amount;
 return true;
 }
 return false;
 }

 void printStatement() const override {
 std::cout << "Account #" << accountNumber << " | Balance: $" << balance << "\n";
 }
};

// 4. POLYMORPHISM: Derived classes with specialized behavior
class SavingsAccount : public BankAccount {
private:
 double interestRate;

public:
 SavingsAccount(int accNum, double balance, double rate)
 : BankAccount(accNum, balance), interestRate{rate} {}

 void applyInterest() {
 deposit(getBalance() * interestRate);
 }
};

int main() {
 // Polymorphic collection of accounts
 std::vector<std::unique_ptr<IAccount>> portfolio;
 portfolio.push_back(std::make_unique<BankAccount>(101, 500.0));
 portfolio.push_back(std::make_unique<SavingsAccount>(102, 1200.0, 0.05));

 for (const auto& acc : portfolio) {
 acc->deposit(100.0);
 acc->printStatement();
 }

 return 0;
}
