#ifndef LEXICO_H
#define LEXICO_H

#include <iostream>
#include <string>

using namespace std;

class TipoSimbolo
{
    public:
        static const int ERROR = -1;
        static const int IDENTIFICADOR = 0;
        static const int ENTERO = 1;
        static const int REAL = 2;
        static const int CADENA = 3;
        static const int TIPO = 4;
        static const int OPADIC = 5;
        static const int OPMUL = 6;
        static const int OPRELAC = 7;
        static const int OPOR = 8;
        static const int OPAND = 9;
        static const int OPNOT = 10;
        static const int OPIGUAL = 11;
        static const int PUNTOCOMA = 12;
        static const int COMA = 13;
        static const int PAR1 = 14;
        static const int PAR2 = 15;
        static const int CORCH1 = 16;
        static const int CORCH2 = 17;
        static const int IGUAL = 18;
        static const int IF = 19;
        static const int WHILE = 20;
        static const int RETURN = 21;
        static const int ELSE = 22;
        static const int PESOS = 23;

};

class lexico
{
    public:
        lexico(string fuente);
        lexico();
        string simb;
        int tipo;
        void entrada(string fuente);
        string tipoAcad(int tipo);
        int sigSimbolo();
        bool termi();

    private:
        string fuente;
        int ind;
        bool conti;
        char c;
        int estado;

        char sigCar();
        void sigEst(int estado);
        void acepta(int estado);
        bool esStr(char c);
        bool esInt(char c);
        bool esEspa(char c);
        void restroceso();
};

#endif // LEXICO_H
