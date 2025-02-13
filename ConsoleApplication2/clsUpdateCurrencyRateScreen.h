#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsCurrenciesListScreen.h"
#include <iomanip>
class clsUpdateCurrencyRateScreen : public clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static bool _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
            return true;
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
            return false;
        }
    }

public:
	static void _ShowUpdateCurrencyRateScreen() {
        char Answer = ' ';
        _DrawScreenHeader("\t  Update Currency Screen");
        string CurrencyCode;
        cout << "\nPlease Enter CurrencyCode: ";
        CurrencyCode = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        if (_ShowResults(Currency)) {
            cout << "Are you sure you want to update this currency rate? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y') {
                float NewRate = 0;
                cout << "\nUpdate Currency Rate: \n";
                cout << "---------------------\n";
                cout << "New Rate : ";
                cin >> NewRate;

                Currency.UpdateRate(NewRate);
                cout << "\nCurrency Updated Successfully :-)\n";

                _PrintCurrency(Currency);
            }
            else {
                
            }
           
   

        }
        else {
            "\nCurrncy didnt Found \n";
        }
	}
};

