#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"

class clsListUsersScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsBankUser User)
    {
        cout << setw(8) << left << "" << "|" << setw(15) << left << User.UserName;
        cout << "|" << setw(20) << left << User.FullName();
        cout << "|" << setw(12) << left << User.Phone;
        cout << "|" << setw(20) << left << User.Email;
        cout << "|" << setw(10) << left << User.Password;
        cout << "|" << setw(12) << left << User.Permissions;
    }

public:

    static void ShowUsersList()
    {
        vector <clsBankUser> vUsers;
        vUsers = clsBankUser::GetUsersList();

        string Title = "\t\tUsers List";
        string SubTitle = "\t\t(" + to_string(vUsers.size()) + ") User(s) ";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n" << setw(8) << left << "" << "-----------------------------------------------------------------------------------"
            << "----------------------------\n";
        cout << "\n" << setw(8) << left << "" << "|" << setw(15) << left << "User Name";
        cout << "|" << setw(20) << left << "FullName";
        cout << "|" << setw(12) << left << "Phone";
        cout << "|" << setw(20) << left << "Email";
        cout << "|" << setw(10) << left << "Password";
        cout << "|" << setw(12) << left << "Permissions";
        cout << "\n" << setw(8) << left << "" << "-----------------------------------------------------------------------------------"
            << "----------------------------\n";
        if (vUsers.size() == 0)
        {
            cout << "\n\t\t\t\tNo User Available .";
        }
        else
        {
            for (clsBankUser U : vUsers)
            {
                _PrintUserRecordLine(U);
                cout << endl;
            }
        }
        cout << "\n" << setw(8) << left << "" << "-----------------------------------------------------------------------------------"
            << "----------------------------\n";
    }

};

