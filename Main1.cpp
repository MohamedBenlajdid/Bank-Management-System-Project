#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";


    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
}

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nEnter an AccountNumber : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number already exicte , choose another one please : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
    ReadClientInfo(NewClient);
    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();
    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Added Successfully :-)\n";
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    }
}

void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nEnter an Account Number : ";
    AccountNumber =clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Not Exist , Enter Another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nYou're sure you want delete this client ? : ";
    char Ansr = 'n';
    cin >> Ansr;
    if (toupper(Ansr) == 'Y')
    {
        if (Client.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            Client.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }

}

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "|" << setw(15) << left << Client.AccountNumber();
    cout << "|" << setw(20) << left << Client.FullName();
    cout << "|" << setw(12) << left << Client.Phone;
    cout << "|" << setw(20) << left << Client.Email;
    cout << "|" << setw(10) << left << Client.PinCode;
    cout << "|" << setw(12) << left << Client.AccountBalance;
}

void ShowClientsList()
{
    vector <clsBankClient> Clients;
    Clients = clsBankClient::GetClientsList();
    cout << "\n\t\t\t\t\tClient List (" << Clients.size() << ") Client(s) .";
    cout << "\n-----------------------------------------------------------------------------------"
        << "----------------------------\n";
    cout << "\n|" << setw(15) << left << "AccountNumber";
    cout << "|" << setw(20) << left << "FullName";
    cout << "|" << setw(12) << left << "Phone";
    cout << "|" << setw(20) << left << "Email";
    cout << "|" << setw(10) << left << "PinCode";
    cout << "|" << setw(12) << left << "AccountBalance";
    cout << "\n-----------------------------------------------------------------------------------"
        << "----------------------------\n";
    if (Clients.size() == 0)
    {
        cout << "\n\t\t\t\tNo Client Available .";
    }
    else
    {
        for (clsBankClient C : Clients)
        {
            PrintClientRecordLine(C);
            cout << endl;
        }
    }
    cout << "\n-----------------------------------------------------------------------------------"
        << "----------------------------\n";
}

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "|" << setw(20) << left << Client.FullName();
    cout << "|" << setw(15) << left << Client.AccountBalance;
    cout << "|" << setw(10) << left << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s) .";
    cout << "\n-------------------------------------------------------------------------------"
        << "---------------------------\n";
    cout << "|" << setw(20) << left << "Full Name";
    cout << "|" << setw(15) << left << "Account Number";
    cout << "|" << setw(10) << left << "Balance";
    cout << "\n-------------------------------------------------------------------------------"
        << "---------------------------\n";
    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Client Exist In the Systeme.";
    }
    else
    {
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }
    }
    cout << "\n-------------------------------------------------------------------------------"
        << "---------------------------\n";
    double TotalBalance = clsBankClient::GetTotalBalances();
    cout << "\t\t\t\tTotal Balance : " << TotalBalance << endl;
    cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalance) << ")";

}

//int main()
//{
//    ShowTotalBalances();
//    system("pause>0");
//    return 0;
//}

