#include <iostream>
#include <iomanip>
#include <map>
#include "clsLoginScreen.h"
using namespace std;

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }

	system("pause > 0");
	return 0;
}