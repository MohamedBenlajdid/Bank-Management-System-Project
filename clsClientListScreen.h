#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "|" << setw(15) << left << Client.AccountNumber();
        cout << "|" << setw(20) << left << Client.FullName();
        cout << "|" << setw(12) << left << Client.Phone;
        cout << "|" << setw(20) << left << Client.Email;
        cout << "|" << setw(10) << left << Client.PinCode;
        cout << "|" << setw(12) << left << Client.AccountBalance;
    }
    
public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsBankUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsBankClient> vClients;
        vClients = clsBankClient::GetClientsList();

        string Title = "\t\tClients List";
        string SubTitle = "\t\t(" + to_string(vClients.size()) + ") Client(s) ";
        
        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(8) << left << "" << "-----------------------------------------------------------------------------------"
            << "----------------------------\n";
        cout << "\n" << setw(8) << left << "" << "|" << setw(15) << left << "AccountNumber";
        cout << "|" << setw(20) << left << "FullName";
        cout << "|" << setw(12) << left << "Phone";
        cout << "|" << setw(20) << left << "Email";
        cout << "|" << setw(10) << left << "PinCode";
        cout << "|" << setw(12) << left << "AccountBalance";
        cout << "\n" << setw(8) << left << "" <<"-----------------------------------------------------------------------------------"
            << "----------------------------\n";
        if (vClients.size() == 0)
        {
            cout << "\n\t\t\t\tNo Client Available .";
        }
        else
        {
            for (clsBankClient C : vClients)
            {
                _PrintClientRecordLine(C);
                cout << endl;
            }
        }
        cout << "\n" << setw(8) << left << "" << "-----------------------------------------------------------------------------------"
            << "----------------------------\n";
    }

};

