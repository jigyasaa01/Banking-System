#include <bits/stdc++.h>
using namespace std;

int counter = 0;
int sizeAcc = 0, sizeAcc2 = 0, NoAcc = 0;
class account;

vector<account> Acc;
vector<int> Acc2;
class account
{
private:
    string First_Name;
    string Last_Name;
    int Age;
    string Gender;
    int AccountNo = 0;
    int Balance;

public:
    account()
    {
        First_Name = " ";
        Last_Name = " ";
        Age = 0;
        Gender = " ";
        AccountNo = counter;
        Balance = 0;
        counter++;
    }
    void setFname(string f);
    void setLname(string l);
    void setAge(int c);
    void setGender(string g);
    void setAccountNo(int a);
    void setBalance(int b);

    void Display(account a);
    void DisplayAcc();
    void CreateAcc();
    void BalEnq();
    void Deposit();
    void Withdraw();
    void RemoveAcc();
    void ShowAllAcc();
    void End();

    string getFname();
    string getLname();
    int getAccountNo();
    int getBalance();
    int getAge();
    string getGender();

    friend ofstream &operator<<(ofstream &ofs, account &acc);
    friend ifstream &operator>>(ifstream &ifs, account &acc);
    friend ostream &operator<<(ostream &os, account &acc);
};

ofstream &operator<<(ofstream &ofs, account &acc)
{
    ofs << acc.First_Name << endl;
    ofs << acc.Last_Name << endl;
    ofs << acc.AccountNo << endl;
    ofs << acc.Balance << endl;
    ofs << acc.Age << endl;
    ofs << acc.Gender << endl;
    return ofs;
}

ifstream &operator>>(ifstream &ifs, account &acc)
{
    ifs >> acc.First_Name;
    ifs >> acc.Last_Name;
    ifs >> acc.AccountNo;
    ifs >> acc.Balance;
    ifs >> acc.Age;
    ifs >> acc.Gender;
    return ifs;
}

ostream &operator<<(ostream &os, account &acc)
{
    os << "First Name : " << acc.getFname() << endl;
    os << "Last Name : " << acc.getLname() << endl;
    os << "Account Number : " << acc.getAccountNo() << endl;
    os << "Balance : " << acc.getBalance() << endl;
    os << "Age : " << acc.getAge() << endl;
    os << "Gender : " << acc.getGender() << endl;
    return os;
}

void account::setFname(string f)
{
    First_Name = f;
}
void account::setLname(string l)
{
    Last_Name = l;
}
void account::setAccountNo(int a)
{
    AccountNo = a;
}
void account::setBalance(int b)
{
    Balance = b;
}
void account::setAge(int c)
{
    Age = c;
}
void account::setGender(string g)
{
    Gender = g;
}

string account::getFname()
{
    return First_Name;
}

string account::getLname()
{
    return Last_Name;
}

int account::getAccountNo()
{
    return AccountNo;
}

int account::getBalance()
{
    return Balance;
}

int account::getAge()
{
    return Age;
}

string account::getGender()
{
    return Gender;
}

void account::Display(account a)
{
    cout << endl;
    cout << " First Name     : " << a.getFname() << endl;
    cout << " Last Name      : " << a.getLname() << endl;
    cout << " Age            : " << a.getAge() << endl;
    cout << " Gender         : " << a.getGender() << endl;
    cout << " Account Number : " << a.getAccountNo() << endl;
    cout << " Balance        : " << a.getBalance() << endl;
    cout << endl;
}
void account::DisplayAcc()
{
    vector<account>::iterator itr;
    for (itr = Acc.begin(); itr != Acc.end(); itr++)
    {
        itr->Display(*itr);
    }
}
void account::CreateAcc()
{
    account NewAcc;
    string Fname;
    string Lname;
    int Balance;
    cout << endl;
    cout << "\n\t Enter First Name : ";
    cin >> Fname;
    cout << "\n\t Enter Last Name  : ";
    cin >> Lname;
    cout << "\n\t Enter Age        : ";
    cin >> Age;
    cout << "\n\t Enter Gender     : ";
    cin >> Gender;
    cout << "\n\t Enter Amount     : ";
    cin >> Balance;

    NewAcc.setFname(Fname);
    NewAcc.setLname(Lname);
    NewAcc.setAge(Age);
    NewAcc.setGender(Gender);
    NewAcc.setBalance(Balance);

    Acc.push_back(NewAcc);
    NewAcc.Display(NewAcc);
    sizeAcc++;
}

void account::BalEnq()
{
    int BalanceEnq = 0;
    cout << "\n\n\t Enter Account No. : ";
    cin >> BalanceEnq;
    cout << " Current Balance : ";

    vector<account>::iterator Enq;
    {
        for (Enq = Acc.begin(); Enq != Acc.end(); Enq++)
        {
            int temp = Enq->getAccountNo();
            if (temp == BalanceEnq)
            {
                cout << Enq->getBalance();
            }
        }
    }
}

void account::Deposit()
{
    int deposit = 0, BalanceD = 0;
    cout << "\n\n\t Enter Account No. : ";
    cin >> BalanceD;
    cout << "\n\n\t Enter depositing amount : ";
    cin >> deposit;

    vector<account>::iterator Dep;
    for (Dep = Acc.begin(); Dep != Acc.end(); Dep++)
    {
        int temp = Dep->getAccountNo();
        if (temp == BalanceD)
        {
            int tempBal = Dep->getBalance();
            Dep->setBalance(tempBal + deposit);
            cout << "\n\n\n\t Amount Deposited "<<endl;
            cout << "\n\n\n\t New Balance:  "<<Dep->getBalance()<<endl;

            // Update balance in file after deposit
            ofstream file("Banking_Project.txt", ios::app);
            file << "Account No: " << BalanceD << " Deposited: " << deposit << " New Balance: " << Dep->getBalance() << endl;
            file.close();
        }
    }
}

void account::Withdraw()
{
    int withdraw = 0, BalanceW = 0;
    cout << "\n\n\t Enter Account no. : ";
    cin >> BalanceW;
    cout << "\n\n\t Enter Withdrawing Amount :";
    cin >> withdraw;

    vector<account>::iterator With;
    for (With = Acc.begin(); With != Acc.end(); With++)
    {
        int temp = With->getAccountNo();
        if (temp == BalanceW)
        {
            int tempBal = With->getBalance();
            if(tempBal >= withdraw)
            {
                With->setBalance(tempBal - withdraw);
                cout << "\n\n\n\t Amount Withdrwan " << endl;
                cout << "\n\n\n\t New Balance : " << With->getBalance();

                // Update balance in file after withdrawal
                ofstream file("Banking_Project.txt", ios::app);
                file << "Account No: " << BalanceW << " Withdrawn: " << withdraw << " New Balance: " << With->getBalance() << endl;
                file.close();
            }
            else
            {
                cout << "\n\n\t Insufficient balance!" << endl;
            }
        }
    }
}

void account::RemoveAcc()
{
    int remove = 0, RemovedAcc = 0;
    cout << "\n\n\t Enter Account No. : ";
    cin >> remove;
    RemovedAcc = remove;

    vector<account>::iterator Rev;
    bool found = false;
    int Deleted = 0;
    //int DeleteCount = 0;
    for (Rev = Acc.begin(); Rev != Acc.end(); Rev++)
    {
        int temp = Rev->getAccountNo();
        if (temp == remove)
        {
            Acc.erase(Rev);
            found = true;
            //Acc.erase(Acc.begin() + DeleteCount);
            Deleted++;
            cout << "\n\n\n\t !!! Account Closed !!!";
            break;

            // Update file after account removal
            ofstream file("Banking_Project.txt", ios::app);
            file << "Account No: " << RemovedAcc << " Removed" << endl;
            file.close();
        }
        //DeleteCount++;
    }
    if(found)
    {
    Acc2.push_back(RemovedAcc);
    sizeAcc2++;
    sizeAcc--;
    }
    else
    {
        cout<<"\n\n\t Account Not Found!"<<endl;
    }
    //saveData();
}

void account::ShowAllAcc()
{
    account *showall;
    showall->DisplayAcc();
}

void account::End()
{
    cout << "\n\n\t Thank You For Using The App";
}

void saveData()
{
    ofstream outfile("Banking_Project.txt", ios::trunc);
    if (outfile.is_open())
    {
        outfile << NoAcc << endl;
        outfile << sizeAcc << endl;
        outfile << sizeAcc2 << endl;

        for (auto &acc : Acc)
        {
            outfile << acc;
        }
        for (auto &accNo : Acc2)
        {
            outfile << accNo << endl;
        }
        outfile.close();
    }
    else
    {
        cerr << "Error: Could not open file for saving data." << endl;
    }
}

void loadData()
{
    ifstream infile("Banking_Project.txt");
    if (infile.is_open())
    {
        infile >> NoAcc >> sizeAcc >> sizeAcc2;
        Acc.resize(sizeAcc);
        Acc2.resize(sizeAcc2);
        for (auto &acc : Acc)
        {
            infile >> acc;
        }
        for (auto &accNo : Acc2)
        {
            infile >> accNo;
        }
        infile.close();
        counter = NoAcc;
    }
    else
    {
        cerr << "Error: Could not open file for loading data." << endl;
    }
}

int main()
{
    loadData();

    ifstream infile("Banking_Project.txt");
    {
        infile >> NoAcc;
        infile >> sizeAcc;
        infile >> sizeAcc2;

        Acc.resize(sizeAcc);
        Acc2.resize(sizeAcc2);

        vector<account>::iterator itr;
        for (itr = Acc.begin(); itr != Acc.end(); itr++)
        {
            infile >> *itr;
        }

        vector<int>::iterator itr2;
        for (itr2 = Acc2.begin(); itr2 != Acc2.end(); itr2++)
        {
            infile >> *itr2;
        }
        infile.close();
        counter = NoAcc;
    }
    account acc;
    int choice;

    cout << "\n\n\n\t ***** WELCOME TO THE BANK OF ''JIGYASA'' ***** ";
    do
    {
        cout << endl;
        cout << "\n\n\t List of Services : ";
        cout << "\n\n\t1 Open an Account";
        cout << "\n\n\t2 Balance Enquiry";
        cout << "\n\n\t3 Deposit Amount";
        cout << "\n\n\t4 Withdraw Amount";
        cout << "\n\n\t5 Close an Account";
        cout << "\n\n\t6 Show All Accounts";
        cout << "\n\n\t7 Quit App";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            acc.CreateAcc();
            saveData();
            break;
        case 2:
            acc.BalEnq();
            break;
        case 3:
            acc.Deposit();
            saveData();
            break;
        case 4:
            acc.Withdraw();
            saveData();
            break;
        case 5:
            acc.RemoveAcc();
            saveData();
            break;
        case 6:
            acc.ShowAllAcc();
            break;
        case 7:
            acc.End();
            break;
        default:
            cout << " Enter valid choice ";
            exit(0);
        }
    } while (choice != 7);
    return 0;

    ofstream outfile("Banking_Project.txt", ios::trunc);
    {

        outfile << NoAcc << endl;
        outfile << sizeAcc << endl;
        outfile << sizeAcc2 << endl;

        {
            vector<account>::iterator itr;
            for (itr = Acc.begin(); itr != Acc.end(); itr++)
            {
                outfile << *itr;
            }
        }
        {
            vector<int>::iterator itr2;
            for (itr2 = Acc2.begin(); itr2 != Acc2.end(); itr2++)
            {
                outfile << *itr2 << endl;
            }
        }
    }
    outfile.close();
}