#include <iostream>

using namespace std;

void style_zero(char a);
void styleZeroForLoop(int a, bool isAplha);

void CreateSpace();
void NewLine();

int main()
{
    bool isStarted = false;
    int patterStyleIndex;
    char userCharacter;
    do
    {
        if (!cin.good() || cin.fail())
        {
            cin.clear();
            cin.ignore(INT32_MAX, '\n');
            NewLine();
            cout << "you entered none-numerical";
            NewLine();
            cout << "Please enter a number from [0 - ?]'Only [0] works': ";
            cin >> patterStyleIndex;
        }
        else
        {
            cout << "Please enter a number from [0 - ?]'Only [0] works': ";
            cin >> patterStyleIndex;
            isStarted = true;
        }
    } while (!cin.good() || cin.fail());

    cout << "Enter a single character: ";
    cin >> userCharacter;

    cout << "you chose style pattern " << patterStyleIndex;
    NewLine();
    cout << "and your character is " << userCharacter;
    NewLine();
    switch (patterStyleIndex)
    {
    case 0:
        style_zero(userCharacter);
        break;
    }
    system("pause");
    return 0;
}

#pragma region //style function
void style_zero(char a)
{
    int num;
    if (isdigit(a) != 0)
    {
        num = a - 48;
        styleZeroForLoop(num, false);
    }
    else if (isalpha(a) != 0)
    {
        styleZeroForLoop(a, true);
    }
    else
    {
        NewLine();
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << a;
            }
            NewLine();
        }
    }
}
#pragma endregion

#pragma region //Function of Pstyle methods
void styleZeroForLoop(int a, bool isAlpha)
{
    int origNum = a;
    int b = origNum;
    NewLine();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!isAlpha)
                cout << a;
            else
            {
                cout << (char)a;
            }
        }
        CreateSpace();
        for (int j = 0; j < 5; j++)
        {
            if (!isAlpha)
            {
                cout << b;
                b++;
                if (b > 9)
                    b = 0;
            }
            else
            {
                cout << (char)b;
                b++;
                if (b > 96)
                {
                    if (b > 122)
                        b = 97;
                }
                else
                {
                    if (b > 90)
                        b = 65;
                }
            }
        }
        NewLine();
        b = origNum;
        a += 1;
        if (!isAlpha)
        {
            if (a > 9)
                a = 0;
        }
        else
        {
            if (a > 96)
            {
                if (a > 122)
                    a = 97;
            }
            else
            {
                if (a > 90)
                    a = 65;
            }
        }
    }
}
#pragma endregion

void CreateSpace()
{
    cout << "\t";
}
void NewLine()
{
    cout << "\n";
}