#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "|" << setw(20) << left << Client.FullName();
        cout << "|" << setw(15) << left << Client.AccountBalance;
        cout << "|" << setw(10) << left << Client.AccountBalance;
    }
public:
    static void ShowTotalBalances()
    {
        _DrawScreenHeader("\t   Total Balance Screen");
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
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        }
        cout << "\n-------------------------------------------------------------------------------"
            << "---------------------------\n";
        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << "\t\t\t\tTotal Balance : " << TotalBalance << endl;
        cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalance) << ")";

    }
};

