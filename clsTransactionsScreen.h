#pragma once
#include<iostream>
#include<iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1 , eWithDraw = 2 , eTotalBalances = 3 , eMainMenue = 4 
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }
    static void _ShowDepositScreen()
    {
        /*cout << "\nDeposit Screen Will Be Here .";*/
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithDrawScreen()
    {
        /*cout << "\nWithDraw Screen Will Be Here .";*/
        clsWithDrawScreen::ShowWithDrawScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
        /*cout << "\nTotal Balances Will Be Here .";*/
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowMainMenueScreen()
    {
        /*cout << "\nMain Menue Will Be Here .";*/ 
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress Any Key To Go Back to Transction Menue ...";
        system("pause>0");
        ShowTransactionsMenue();
    }
    static void _PerformeTransactionsOption(enTransactionsMenueOptions TransactionOption)
    {
        switch (TransactionOption)
        {
        case enTransactionsMenueOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOptions::eWithDraw:
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOptions::eTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOptions::eMainMenue:
            system("cls");
            _ShowMainMenueScreen();
          
            break;
        }
    }

public:
	static void ShowTransactionsMenue()
	{
        if (!CheckAccessRights(clsBankUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformeTransactionsOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }
};