#include "numgrande.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>


#define MAX 666
using namespace std;

//Funcao realocar
void NumGrande::realocar()
{
    int *aux = new int[capacity + MAX];
	for (int i = 0; i < capacity; i++)
		aux[i] = vet[i];
	delete [] vet;
	vet = aux;
	capacity += MAX;
}

//Construtor
NumGrande::NumGrande()
{
	top = -1;
	capacity = MAX;
	vet = new int[capacity];
}

//Construtor com parametro
NumGrande::NumGrande(string str)
{
	top = -1;
	capacity = MAX;
	vet = new int[capacity];
	strint(str);
}

//Construtor de copia
NumGrande::NumGrande(const NumGrande &c)
{
	capacity = c.capacity;
	top = c.top;
	vet = new int[capacity];
	//Copia os elementos para vetor
	for (int i = 0; i <= top; i++)
		vet[i] = c.vet[i];
}

//Funcao que converte string para int
void NumGrande::strint(string str)
{
	reverse(str.begin(), str.end());
	int aux = str.length();
	for(int i = 0; i < aux; i++)
		Push(str[i] - '0');
	zeroesqueda();
}

//Funcao que inverte ordem do vetor int
void NumGrande::inverte()
{
	NumGrande c(*this), temp;
	while (! Empty())
		temp.Push(Pop());
	while (! c.Empty())
		Push(c.Pop());
}

//Remove zero a esquerda
void NumGrande::zeroesqueda()
{
	while (! Empty() && vet[top] == 0)
		Pop();
	if (Empty())
		Push(0);
}

//Sobrecarga operador =
void NumGrande::operator=(const NumGrande& c)
{
	capacity = c.capacity;
	top = c.top;
	vet = new int[capacity];
	for (int i = 0; i <= top; i++)
		vet[i] = c.vet[i];
}

//Inserir elemento no topo da pilha
void NumGrande::Push(int element)
{
	if (top + 1 == capacity)
		realocar();
	vet[++top] = element;
}

//Funcao desempilha
int NumGrande::Pop()
{
	assert(! Empty());
	return vet[top--];
}
//Funcao verifica pilha vazia
bool NumGrande::Empty()
{
	return top == -1;
}

//Funcao soma
const NumGrande NumGrande::adicao(const NumGrande& num)
{
	NumGrande result, end1(*this), end2(num);
	end1.inverte();
	end2.inverte();
	int vaium = 0;
	while (! end1.Empty() || ! end2.Empty()) {
		int aux1, aux2;
		if (end1.Empty())
			aux1 = 0;
		else
			aux1 = end1.Pop();
		if (end2.Empty())
			aux2 = 0;
		else
			aux2 = end2.Pop();
		int total = aux1 + aux2 + vaium;
		result.Push(total % 10);
		vaium = total / 10;
	}
	if (vaium > 0)
		result.Push(vaium);
	result.zeroesqueda();
	return result;
}

 //Funcao subtracao
const NumGrande NumGrande::sub(const NumGrande& num)
{
	NumGrande result, minuend(*this), subtrahend(num);
	minuend.inverte();
	subtrahend.inverte();
	int vaium = 0;
	while (! minuend.Empty()) {
		int aux1, aux2;
		aux1 = minuend.Pop();
		if (subtrahend.Empty())
			aux2 = 0;
		else
			aux2 = subtrahend.Pop();
		int total = aux1 - aux2 - vaium;
		if (total < 0)
        {
			total += 10;
			vaium = 1;
		}
		else
			vaium = total / 10;
		result.Push(total % 10);
	}
	result.zeroesqueda();
	if (result.Empty())
		result.Push(0);
	return result;
}

//Funcao metade vet1
const NumGrande NumGrande::metade()
{
	NumGrande result, half(*this);
	int vaium = 0, aux;
	while (! half.Empty()) {
		aux = half.Pop() + vaium * 10;
		if (aux == 0)
			result.Push(0);
		else
        {
			if (aux < 2)
			{
				if (! half.Empty())
					aux = aux * 10 + half.Pop();
				result.Push(aux / 2);
				vaium = aux % 2;
			}
            else
            {
				result.Push(aux / 2);
				vaium = aux % 2;
			}
		}
	}
	result.inverte();
	result.zeroesqueda();
	return result;
}


//Funcao metade vet2
/*const NumGrande NumGrande::metade2()
{
	NumGrande result, half(*this);
	int vaium = 0, aux;
	while (! half.Empty()) {
		aux = half.Pop() + vaium * 10;
		if (aux == 0)
			result.Push(0);
		else
        {
			if (aux < 2)
			{
				if (! half.Empty())
					aux = aux * 10 + half.Pop();
				result.Push(aux / 2);
				vaium = aux % 2;
			}
            else
            {
				result.Push(aux / 2);
				vaium = aux % 2;
			}
		}
	}
	result.inverte();
	result.zeroesqueda();
	return result;
}
*/
//Funcao multiplicacao
const NumGrande NumGrande::multi(const NumGrande& num)
{
	NumGrande result, fator1(*this);
	int vaium = 0, aux1, aux2, total, exp = 0;
	result.Push(0);
	fator1.inverte();
	while (! fator1.Empty())
    {
		aux1 = fator1.Pop();
		NumGrande fator2(num), temp;
		fator2.inverte();
		int zeros = 0;
		while (! fator2.Empty())
		{
			if (zeros == 0 && exp >= 1)
			{
				for (int i = 0; i < exp; i++)
					temp.Push(0);
				zeros++;
			}
			aux2 = fator2.Pop();
			total = aux1 * aux2 + vaium;
			if (total < 10)
            {
				temp.Push(total);
				vaium = 0;
			}
            else
			{
				temp.Push(total % 10);
				vaium = total / 10;
			}
		}
		if (vaium > 0) {
			temp.Push(vaium);
			vaium = 0;
		}
		result = temp.adicao(result);
		exp++;
	}
	result.zeroesqueda();
	return result;
}

//Imprimir
void NumGrande::Print()
{
	cout << "{";
	for (int i = top; i > 0; i--)
		cout << vet[i] << " ";
	if (! Empty())
		cout << vet[0];
	cout << "}" << endl;
}

//Destrutor
NumGrande::~NumGrande()
{
	if (vet)
		delete [] vet;
}
