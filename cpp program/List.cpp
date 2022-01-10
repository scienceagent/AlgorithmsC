#include <bits/stdc++.h>

struct nod
{
	char inf[150];
	nod *urm;
};
typedef struct nod *lista;
lista l1, l;

void Adaugare(lista &prim, lista p, char x[120])
{
	lista q = new nod;

	strcpy(q->inf, x);
	if (!p)
	{
		q->urm = prim;
		prim = q;
	}
	else
	{
		q->urm = p->urm;
		p->urm = q;
	}
}

void afisare(lista prim)
{
	lista v;

	for (v = prim; v; v = v->urm)
		std::cout << v->inf << '\n';

	std::cout << '\n';
}

void afisare2(lista prim)
{
	lista v;
	v = prim;
	do
	{
		std::cout << v->inf << '\n';
		v = v->urm;
	} while (v != prim);
}

void Adaugare2(lista &p, char x[120])
{
	lista q = new nod;
	lista aux = p;
	strcpy(q->inf, x);
	q->urm = p;
	if (p != NULL)
	{
		while (aux->urm != p)
		{
			aux = aux->urm;
		}
		aux->urm = q;
	}
	else
	{
		q->urm = q;
	}
	p = q;
}

void Trans(lista l1, lista &l)
{
	lista v;

	for (v = l1; v; v = v->urm)
	{
		Adaugare2(l, v->inf);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	char x[100];

	l1 = NULL;

	std::cout << "Enter n : ";
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		std::cout << i << ")";
		std::cin >> x;
		Adaugare(l1, NULL, x);
	}
	std::cout << '\n';
	std::cout << "Stiva : " << '\n';
	afisare(l1);

	Trans(l1, l);

	std::cout << "Lista circulara : " << '\n';
	afisare2(l);

	return 0;
}
