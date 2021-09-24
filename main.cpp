#include <iostream>
#include <string>

bool nCorrect (std::string str)
{
    bool nCorrect = true;
    if (str.length() != 9)
    {
        nCorrect = false;
    }
    else
    {
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] != 'X' && str[i] != 'O' && str[i] != '.')
            {
                nCorrect = false;
                break;
            }

        }
    }
    return nCorrect;
}

int symbolCounter (std::string str, char symbol)
{
    int symbolCounter = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == symbol)
        {
            ++symbolCounter;
        }
    }
    return symbolCounter;
}

bool  checkCol (std::string sumStr, char symbol)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((sumStr[i] == sumStr[i+3]) && (sumStr[i+3] == sumStr[i+6])
        && (sumStr[i] == symbol))
        {
            return true;
        }
    }
    return false;
}

bool checkRow (std::string sumStr, char symbol)
{
    for (int i = 0; i < 3; ++i)
    {
        if (((sumStr[i + 2 * i]) == sumStr[(i + 1) + 2 * i])
        && ((sumStr[(i + 1 ) + 2 * i]) == sumStr[(i + 2) + 2 * i])
        && sumStr[i + 2 * i] == symbol)
        {
            return true;
        }
    }
    return false;
}

bool checkDiag (std::string sumStr, char symbol)
{
    if ((((sumStr[0] == sumStr[4]) && (sumStr[4] == sumStr[8]))
    || ((sumStr[2] == sumStr[4]) && (sumStr[4] == sumStr[6])))
    && (sumStr[4] == symbol))
    {
        return true;
    }
    return false;
}

int main()
{
    std::string str1, str2, str3;
    std::cout << "You are welcome!Enter three lines: \n";
    std::cin >> str1 >> str2 >> str3;
    std::string table = str1 + str2 + str3;

    if (!nCorrect( table))
    {
        std::cout << "Incorrect!\n";
    }
    else
    {
        int countX = symbolCounter(table, 'X');
        int countO = symbolCounter(table, 'O');

        if((checkCol(table, 'X') || checkRow(table, 'X')
        || checkDiag(table, 'X')) && ((countX -  countO ) == 1))
        {
            std::cout << "Petya won\n";
        }
        else if ((checkCol( table, 'O') || checkRow(table, 'O')
        || checkDiag(table, 'O')) && (countO == countX))
        {
            std::cout << "Vanya won\n";
        }
        else if ((!checkCol(table, 'X') && !checkRow(table, 'X')
        && !checkDiag(table, 'X')) && (countO == 3 && countX == 3)
        || (countO <= 2 && countX <= 2) || (countX == 5 && countO == 4))
        {
            std::cout << "Nobody\n";
        }
        else
        {
            std::cout << "Incorrect\n";
        }
    }
}
