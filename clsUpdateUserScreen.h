#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _ReadUserInfo(clsBankUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }
    static void _Print(clsBankUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsBankUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }
public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsBankUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsBankUser User = clsBankUser::Find(UserName);
        _Print(User);

        cout << "\nYou are sure you want to Update this User ? ";
        char Ansr = 'n';
        cin >> Ansr;

        if (toupper(Ansr) == 'Y') {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User);

            clsBankUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult)
            {
            case  clsBankUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";
                _Print(User);
                break;
            }
            case clsBankUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }
    }

};

