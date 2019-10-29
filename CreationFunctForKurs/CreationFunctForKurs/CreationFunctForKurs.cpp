// CreationFunctForKurs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Intergal.h"

int main()
{
	
	Intergral<double> *l=new Intergral<double>();
	l->vvod<double>();
	l->findnumiter();
	cout << "Значение вычисления методом симпосона" << endl;
	cout << l->findintergalsimpson<double>(l->n)<<endl;
	cout << "Точность: " << endl;
	cout << l->findtochnost<double>() << endl;
	system("pause");
    return 0;
}

