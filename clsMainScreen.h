#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1 , eAddNewClient = 2 , eDeleteClient = 3 , eUpdateClient = 4 ,
		eFindClient = 5 , eShowTransactionsMenue = 6 , eManageUsers = 7 , eExit = 8
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Please Enter a choice between[1-8]: ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Please Enter a choice between[1 - 8]: ");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "Press Any Key To Go Back To Main Menue ...\n";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowListClientsScreen()
	{
		/*cout << "\nList Clients Will be here ...\n";*/
		clsClientListScreen::ShowClientsList();

	}

	static void _ShowAddNewClientScreen()
	{
		/*cout << "\nAdd New Client Will be here ...\n";*/
		clsAddNewClientScreen::ShowAddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		/*cout << "\nDelete Client Will be here ...\n";*/
		clsDeleteClientScreen::ShowDeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		/*cout << "\nUpdate Client Will be here ...\n";*/
		clsUpdateClientScreen::ShowUpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		/*cout << "\nFind Client Will be here ...\n";*/
		clsFindClientScreen::ShowFindClient();
	}

	static void _ShowTransactionsMenueScreen()
	{
		/*cout << "\nTransactions Menue Will be here ...\n";*/
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersScreen()
	{
		/*cout << "\nManage Users Will be here ...\n";*/
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	/*static void _ShowEndScreen()
	{
		cout << "\nExit Will be here ...";
	}*/

	static void _Logout()
	{
		CurrentUser = clsBankUser::Find("", "");
		// By default will logout.
	}

	static void _PerformeMainMenueChoice(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
			system("cls");
			_ShowListClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenueScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			//Login();
			break;
			
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformeMainMenueChoice((enMainMenueOptions)_ReadMainMenueOption());
	}

};

