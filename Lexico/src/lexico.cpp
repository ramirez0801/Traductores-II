#include "lexico.h"

lexico::lexico(string fuente)
{
    ind = 0;
    this->fuente = fuente;
}

lexico::lexico()
{
        ind = 0;
}

string lexico::tipoAcad(int tipo)
{
    string cad = "";
    switch(tipo)
    {
        case TipoSimbolo::IDENTIFICADOR:
            cad = "identificador";
            break;
        case TipoSimbolo::ENTERO:
            cad = "Entero";
            break;
        case TipoSimbolo::OPADIC:
            cad = "OP. adicion";
            break;
        case TipoSimbolo::OPMUL:
            cad = "OP. mult.";
            break;
        case TipoSimbolo::OPRELAC:
            cad = "OP. relacional";
            break;
        case TipoSimbolo::OPOR:
            cad = "OP. or";
            break;
        case TipoSimbolo::OPAND:
            cad = "OP. and";
            break;
        case TipoSimbolo::OPNOT:
            cad = "OP. not";
            break;
        case TipoSimbolo::OPIGUAL:
            cad = "OP. igual";
            break;
        case TipoSimbolo::PUNTOCOMA:
            cad = "Punto y coma";
            break;
        case TipoSimbolo::COMA:
            cad = "Coma";
            break;
        case TipoSimbolo::PAR1:
            cad = "Abrir parentesis";
            break;
        case TipoSimbolo::PAR2:
            cad = "Cerrar parentesis";
            break;
        case TipoSimbolo::CORCH1:
            cad = "Abrir corchete";
            break;
        case TipoSimbolo::CORCH2:
            cad = "Cerrar corchete";
            break;
        case TipoSimbolo::PESOS:
            cad = "Fin de la entrada";
            break;
        case TipoSimbolo::ERROR:
            cad = "ERROR";
            break;
    }
    return cad;
}

void lexico::entrada(string fuente)
{
    ind = 0;
    this->fuente = fuente;

}

int lexico::sigSimbolo()
{
    estado = 0;
    conti = true;
    simb = "";

    while(conti)
    {
        c = sigCar();
        //cout<<"c: "<<c;
        switch(estado)
        {
            case 0:
                if(esStr(c))
                {
                    estado = 1;
                    break;
                }
                else if(esInt(c))
                    acepta(1);
                else if(c == '+' || c == '-')
                    acepta(5);
                else if(c == '*' || c == '/')
                    acepta(6);
                else if(c == '<' || c == '>')
                    acepta(7);
                else if(c == '|')
                    acepta(8);
                else if(c == '&')
                    acepta(9);
                else if(c == '!')
                    acepta(10);
                else if (c == '=')
                    acepta(11);
                else if(c == ';')
                    acepta(12);
                else if(c == ',')
                    acepta(13);
                else if(c == '(')
                    acepta(14);
                else if(c == ')')
                    acepta(15);
                else if(c == '{')
                    acepta(16);
                else if(c == '}')
                    acepta(17);
                else if( c == '$')
                        acepta(23);
                break;
        }
    }

    switch(estado)
    {
        case 1:
            tipo = TipoSimbolo::ENTERO;
            break;
        case 5:
            tipo = TipoSimbolo::OPADIC;
            break;
        case 6:
            tipo = TipoSimbolo::OPMUL;
            break;
        case 7:
            tipo = TipoSimbolo::OPRELAC;
            break;
        case 8:
            tipo = TipoSimbolo::OPOR;
            break;
        case 9:
            tipo = TipoSimbolo::OPAND;
            break;
        case 10:
            tipo = TipoSimbolo::OPNOT;
            break;
        case 11:
            tipo = TipoSimbolo::OPIGUAL;
            break;
        case 12:
            tipo = TipoSimbolo::PUNTOCOMA;
            break;
        case 13:
            tipo = TipoSimbolo::COMA;
            break;
        case 14:
            tipo = TipoSimbolo::PAR1;
            break;
        case 15:
            tipo = TipoSimbolo::PAR2;
            break;
        case 16:
            tipo = TipoSimbolo::CORCH1;
            break;
        case 17:
            tipo = TipoSimbolo::CORCH2;
            break;
        case 23:
            tipo = TipoSimbolo::PESOS;
            break;

        default:
            tipo = TipoSimbolo::ERROR;
            break;
    }

    return tipo;

}

char lexico::sigCar()
{
    if(termi())
        return '$';
    return fuente[ind++];

}

void lexico::sigEst(int estado)
{
    this->estado = estado;
    simb += c;
    //cout<<"Simbolo: "<<simb<<endl;
}

void lexico::acepta(int estado)
{
    sigEst(estado);
    conti = false;
}

bool lexico::termi()
{
    return ind >= fuente.length();
}

bool lexico::esStr(char c)
{
    return isalpha(c) || c == '_';
}

bool lexico::esInt(char c)
{
    return isdigit(c);
}

bool lexico::esEspa(char c)
{
    return c == ' ' || c == '\t';
}

void lexico::restroceso()
{
    if(c != '$')
        ind--;
    conti = false;

}
