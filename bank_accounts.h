#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>


using UnixTS = unsigned int;

const unsigned short TRANSACTION_COL_N = 6;
const unsigned short ACCOUNT_COL_N = 3;

struct Transaction {
    std::string id;
    UnixTS date;
    std::string type;
    std::string from;
    std::string to;
    double amount;
    bool operator<(const Transaction& other) const;
};

class Account
{
public:
    Account();// default constructor
    Account(const std::string& id, const std::string& name, UnixTS validity_dt = UINT_MAX);
    void addTransaction(const Transaction& transaction);
    double getBalance(UnixTS = UINT_MAX) const;
    void printInfo() const;
    size_t getTransactionsCount() const;

private:
    std::string id;
    std::string name;
    std::set<Transaction> transactions;
    UnixTS validity_dt;
};

void Account::printInfo() const
{
    std::cout << "--------------------------------\n"
              << "id: " << id << '\n'
              << "name: " << name << '\n'
              << "validity datetime: " << validity_dt << '\n'
              << "--------------------------------\n";
}

size_t Account::getTransactionsCount() const
{
    return transactions.size();
}

Account::Account()
{
    id = "00000000-0000-0000-0000-000000000000";
    name = "Noname";
    validity_dt = 0;
}
// Task 1 (5 points)
// Implement Account constructor with arguments
Account::Account(const std::string& id,
                 const std::string& name,
                 UnixTS validity_dt)
{
    // put your code here;
}

// Task 2 (10 points)
// Implement operator< overloading for Transaction
bool Transaction::operator<(const Transaction& other) const
{
    return false;// replace by your code;
}

// Task 3 (10 points)
// Implement get balance to date method (default max value)
double Account::getBalance(UnixTS timestamp) const
{
    double balance = 0;
    // put your code here;
    return balance;
}

// Task 4 (15 points)
// Implement adding transaction to Account
void Account::addTransaction(const Transaction& transaction)
{
    // put your code here;
}


// Task 5 (20 points)
// Implement transaction and account reading from csv and fill accounts by transactions
using AccountContainer = std::unordered_map<std::string, Account>;
using TransactionContainer = std::set<Transaction>;

TransactionContainer readTransactions(std::ifstream& fileStream)
{
    TransactionContainer transactions;

    std::string line;
    std::getline(fileStream, line);
    size_t transactionsCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < transactionsCount; ++i)
    {
        std::stringstream ss(line);
        std::string field;
        Transaction transaction;
        for (unsigned short i = 0; i < TRANSACTION_COL_N; i++)
        {
            // add your code here;
        }
        // and here;
    }


    return transactions;
}

AccountContainer readAccounts(std::ifstream& fileStream)
{
    AccountContainer accounts;

    // put your code here;

    return accounts;
}

void fillAccounts(AccountContainer& accounts, const TransactionContainer& transactions)
{
    // put your code here;
}
