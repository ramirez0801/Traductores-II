#include <iostream>
#include <string>
#include <cstdlib>

#include "lexico.h"

using namespace std;

int main()
{
    lexico lex;
    lex.entrada("+ + * / - + + < >= <= + { } ( ) | &");

    cout<< "\tResultado"<<endl<<endl;
    cout<< "Simbolo\t\tTipo"<<endl;
    while(lex.simb.compare("$") != 0)
    {
        lex.sigSimbolo();
        cout<< lex.simb << "\t\t" << lex.tipoAcad(lex.tipo) <<endl;

    }

    cin.get();
    return 0;
}
