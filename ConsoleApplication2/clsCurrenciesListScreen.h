#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include <iomanip>
class clsCurrenciesListScreen  : public clsScreen
{
    static void PrintCurrencyRecordLine(clsCurrency Currency) {
        cout << setw(8) << left << "" << "| " << setw(27) << left << Currency.Country();
        cout << "| " << setw(5) << left << Currency.CurrencyCode();
        cout << "| " << setw(39) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();
    }
public:
	static void ShowCurrenciesListScreen() {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(27) << "Country";
        cout << "| " << left << setw(5) << "Code";
        cout << "| " << left << setw(39) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

