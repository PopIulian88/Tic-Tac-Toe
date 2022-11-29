#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
using namespace std;
char tabla[4][4], Jucator = 'X', Castigator;
int posLin = 1, posCol = 1;
char mesaj[100];
void afisare()
{
    int i, j;
    system ("CLS");
    cout << mesaj << '\n';
    for(i = 1; i <= 3; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            if(posLin == i && posCol == j)
                cout << "*";
            else
                cout << tabla[i][j];
            if(j < 3)
                cout << "|";
        }
        cout << '\n';
        if(i < 3)
            cout << "-----\n";
    }
    cout << "It's your turn: " << Jucator << '\n';
}
int gataJoc()
{
    int i, j, spatiu = 0;
    for(i = 1; i <= 3; i++)
    {
        if(tabla[i][1] == tabla[i][2] && tabla[i][2] == tabla[i][3] && tabla[i][1] != ' ')
        {
            Castigator = tabla[i][1];
            return 1;
        }
        if(tabla[1][i] == tabla[2][i] && tabla[2][i] == tabla[3][i] && tabla[1][i] != ' ')
        {
            Castigator = tabla[1][i];
            return 1;
        }
    }
    if(tabla[1][1] == tabla[2][2] && tabla[2][2] == tabla[3][3] && tabla[1][1] != ' ')
    {
        Castigator = tabla[1][1];
        return 1;
    }
    if(tabla[1][3] == tabla[2][2] && tabla[2][2] == tabla[3][1] && tabla[1][3] != ' ')
    {
        Castigator = tabla[1][3];
        return 1;
    }
    for(i = 1; i <= 3; i++)
        for(j = 1; j <= 3; j++)
            if(tabla[i][j] == ' ')
                spatiu = 1;
    if(spatiu)
        return 0;
    else
    {
        Castigator = 'R';
        return 1;
    }
}
void comenzi()
{
    while(!gataJoc())
    {
        afisare();
        if(_kbhit())
        {
            switch(_getch())
            {
                case 's' :
                    posLin = (posLin + 1) % 4;
                    if(posLin == 0)
                        posLin = 1;
                    break;
                case 'w' :
                    posLin = (posLin - 1 + 4) % 4;
                    if(posLin == 0)
                        posLin = 3;
                    break;
                case 'd' :
                    posCol = (posCol + 1) % 4;
                    if(posCol == 0)
                        posCol = 1;
                    break;
                case 'a' :
                    posCol = (posCol - 1 + 4) % 4;
                    if(posCol== 0)
                        posCol = 3;
                    break;
                case 13 : // 13 = caracterul ENTER in C++
                    if(tabla[posLin][posCol] == ' ')
                    {
                    tabla[posLin][posCol] = Jucator;
                        if(Jucator == 'X')
                        {
                            Jucator = '0';
                            strcpy(mesaj, "X was positioned");
                        }
                        else
                        {
                            Jucator = 'X';
                            strcpy(mesaj, "0 was positioned");
                        }
                    }else
                        strcpy(mesaj, "Space busy, try again");
                    break;
            }
        }
    }
    system("CLS");
    if(Castigator == 'R')
        cout << "\n\n\n\nDraw\n\n\n\n";
    else
        cout << "\n\n\n\nThe winner is : " << Castigator << "\n\n\n\n";
}
int main()
{
    int i, j;
    for(i = 1; i <= 3; i++)
        for(j = 1; j <= 3; j++)
            tabla[i][j] = ' ';
    comenzi();
    cout << "If you want to close the game, write yes: ";
    char variabila[100];
    cin >> variabila;
    cout << "Are you sure?" << '\n';
    cin >> variabila;
}
