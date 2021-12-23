#ifndef NUMGRANDE_H
#define NUMGRANDE_H
#include <string>
using namespace std;

class NumGrande
{
	private:
		int *vet, top, capacity;
		void realocar();
	public:
		//Construtor
		NumGrande();
		NumGrande(string str);
		NumGrande(const NumGrande &c);

		void strint(string str);
		void inverte();
		void zeroesqueda();

		void operator =(const NumGrande& c);

		void Push(int element);
		int Pop();
		bool Empty();

		//Operacoes
		const NumGrande adicao(const NumGrande& num);
		const NumGrande sub(const NumGrande& num);
		const NumGrande metade();
		//const NumGrande metade2();
		const NumGrande multi(const NumGrande& num);

		void Print();

		//Destrutor
		~NumGrande();
};

#endif // NUMGRANDE_H

