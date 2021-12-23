#include <iostream>
#include "numgrande.h"
#include "numgrande.cpp"

using namespace std;

int main()
{
    string strnum1, strnum2;
    cout << "Insira dois numeros:" << endl;
    cin >> strnum1 >> strnum2;
    //Criacao das variaveis para chamada das funcoes;
    NumGrande n1(strnum1),n2(strnum2), soma = n1.adicao(n2), dobro = n1.adicao(n1), mtde = n2.metade(), subtracao = n1.sub(n2), multiplicacao = n1.multi(n1);

    cout<<"Primeiro numero: "<<endl;
	n1.Print();

	cout<< "Segundo numero: " <<endl;
	n2.Print();

	cout<< "Soma: "<<endl;
	soma.Print();

	cout<<"Dobro do primeiro: "<<endl;
	dobro.Print();

	//cout<<"Dobro do segundo: "<<endl;
	//dobro2.Print();

	cout<<"Metade do primeiro: "<<endl;
	mtde.Print();

	//cout<<"Metade do segundo: "<<endl;
	//mtde2.Print();

	cout<<"Subtracao do primeiro pelo segundo: "<<endl;
	subtracao.Print();

	cout<<"Multiplicacao do primeiro com o segundo: "<<endl;
	multiplicacao.Print();

    return 0;
}
