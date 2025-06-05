#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsFindClientScreen : protected clsScreen
{
private:
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:

    static void ShowFindClient()
    {
        if (!CheckAccessRights(clsBankUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tFind Client Screen");
        
        string AccountNumber = "";

        cout << "\nPlease Enter an Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number not found ,Please Enter an exist one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient was not Found :-(\n";
        }
        _Print(Client1);
    }

};

