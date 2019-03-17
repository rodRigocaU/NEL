#include <iostream>
#include "vector"

using namespace std;

void ver(int n,int n1,int n2, int mod)
{
    if(n == 1)
    {

        if(n1 + n2 >= mod)
        {
            cout << (n1 + n2 ) % mod << " mod " << mod << '\n';
        }
        else
        {
            if((n1 + n2 ) % mod == 0)
            {
                cout << ((n1  + n2 ) % mod) << " mod " << mod << '\n';
            }
            else
                cout << ((n1 + n2) % mod) + mod << " mod " << mod << '\n';
        }
    }
    else if(n == 2)
    {
        if(n1 - n2  >= mod)
        {
            cout << (n1 - n2) % mod << " mod " << mod << '\n';
        }
        else
        {
            if((n1 - n2) % mod == 0)
            {
                cout << ((n1 - n2 ) % mod) << " mod " << mod << '\n';
            }
            else
                cout << ((n1  - n2 ) % mod) + mod << " mod " << mod << '\n';
        }
    }
    else if(n == 3)
    {
        if(n1 * n2 < 0)
        {
            cout <<  ((n1 * n2) % mod) + mod << " mod " << mod << '\n';
        }
        else
            cout <<  (n1 * n2) % mod << " mod " << mod << '\n';
    }
    else
    {
        int aux2;
        int aux3;
        int a1;
        int r;
        int cont = 0;
        vector<int>v;

        aux3 = n1;
        a1 = mod / n1;
        r = (mod % n1);
        for(int i = 0; ;i++)
        {

            aux2 = r;
            r = (aux3 % aux2);
            v.push_back(a1);
            a1 = aux3 / aux2;
            aux3 = aux2;
            cont++;
            if(r == 0)
            {
                break;
            }


        }

        int posa2 = 0;
        int posa = 1;
        int pos ;

        if(aux3 == 1)
        {
            cout << " Si tiene inversa y es " << '\n';
            for(int i = 0; i < v.size(); i++)
            {
                if(posa2 - (posa * v[i]) < 0)
                {
                    pos = mod + (posa2 -(posa * v[i]) );
                }
                else
                {
                    pos = posa2 -(posa * v[i]);
                }
                posa2 = posa;
                posa = pos;
            }
            cout << pos << '\n';

        }
        else
            cout << "no tiene inversa" ;

    }
}

int main()
{
    int num1, num2, mod, op;
    cout << "Ingrese el modulo..." << '\n';
    cin >> mod;
    cout << "Ingresar dos numeros..." << '\n';
    cin >> num1 >> num2;

    cout << "Que operacion quiere realizar..?" << '\n';
    cout << "1. Suma" << '\n';
    cout << "2. Resta" << '\n';
    cout << "3. Multiplicacion" << '\n';
    cout << "4. Inversa solo del primer numero ingresado " << '\n';

    cin >> op;
    ver(op, num1 , num2, mod);
    return 0;
}
