#pragma once
#include"iostream"
#include <ctime>
#include "math.h"
#include "string.h"
#include "exprtk.hpp"
#include "locale.h"
#include <cstdio>
using namespace std;
template <typename T> class
Intergral
{

	typedef exprtk::symbol_table<T> symbol_table_t;
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;
private:
	double res;
	double a;
	double b;
	double h;
	
	T y;
	T x;
	string funct;
	expression_t exp;
	int checkmethod;
	double tochnost;
public:
	Intergral<T>(){
		setlocale(LC_ALL,"rus");
	}
	unsigned int n;
	template <typename T>
	void vvod()
	{
		cout << "¬ведите функцию: " << endl;
		getline(cin, funct);
	
		cout << funct << endl;
		cout << "¬ведите значени b и a:" << endl;
		cin >> b;
		cin >> a;
		symbol_table_t symbol_table;
		symbol_table.add_variable("x", x);
		symbol_table.add_constants();
		exp.register_symbol_table(symbol_table);

		parser_t parser;
		parser.compile(funct, exp);
		

	}
	template <typename T>
	double findintergalsimpson(unsigned int n)
	{

		h = (b - a) / (2 * n);
		checkmethod = 1;
		x = T(a);
		T f0;
		f0 = exp.value();
		x = T(a + 2 * n*h);
		T f2N = exp.value();
		T S = T(0);
		T S1 = T(0);
		for (int i = 1; i <= 2 * n - 1; i++)
		{
			if (i % 2 != 0||i==1)
			{
				x = T(a + i*h);
				S += exp.value();
			}
			else if (i % 2 == 0)
			{
				x= T(a + i*h);
				S1 += exp.value();
			}
		}
		res = (h / 3)* (f0 + 4 * S + 2 * S1 + f2N);
		return res;
	}
	template <typename T>
	double findintergralpryamoygol(unsigned int n)
	{
		checkmethod = 2;
		double h1 = (b - a)/ n;
		T f = T(0);
	
		
		for (double i = 0; i <= n - 1; i++)
		{
			x = T(a + i*h1);
			
			f += exp.value();	
			
		}
		res = h1*f;
		return res;
	}
	template <typename T>
	double findintegraltrap(unsigned int n)
	{
		checkmethod = 3;
		res = 0;
		h = (b - a)/ n;
		T f;
		T f1;
		for (int i = 0; i <= n; i++)
		{
			x = T(a + i*h);
			 f = exp.value();
		x = T(a + (i+1)*h);
			 f1 = exp.value();
			 res += ((f + f1)*h) / 2;

		}
		return res;
	}
	template <typename T>
	double findtochnost()
	{
		double f2n;
		double fn;
		if (checkmethod == 1)
		{
			f2n = findintergalsimpson<double>(n);
			fn = findintergalsimpson<double>(n/2);
			tochnost = (f2n - fn)/15;

		}
		else if (checkmethod == 2)
		{
			f2n = findintergralpryamoygol<double>(2*n);
			fn = findintergralpryamoygol<double>(n);
			tochnost = f2n - fn;

		}
		else if (checkmethod == 3)
		{
			f2n = findintegraltrap<double>(2 * n);
			fn = findintegraltrap<double>(n);
			tochnost = (f2n - fn)/3;

		}
		return tochnost;
	}
	virtual void findnumiter()
	{
		cout << "¬ведите количество итераций (чем больше число, тем точнее вычисление): " << endl;
		
		cin >> n;
		while (n <= 0)
		{
			cout << "n не может быть меньше или равно 0, введите значение еще раз: " << endl;
			cin >> n;
		}
	};
	double vyvodres()
	{
		return res;
	}

};