#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
class list
{
	int count;
	char serial[30][30];
	char name[30][30];
	char price[30][30];
	char quality[30][30];
	char quantity[30][30];
public:
	void goods();
	void order_goods();
	void show_goods();
};

void list::order_goods()
{
	char productID[30];
	long Pquantity;
	int found = 0;
	cout << "Enter Product id: ";
	cin >> productID;
	int v;
	for (v = 0; v < count; v++)
	{
		if (strcmp(serial[v], productID) == 0)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		char read;
		cout << "Enter quantity(kg): ";
		cin >> Pquantity;
	AA:
		cout << "Are you sure of ordering " << Pquantity << " kg of " << name[v];
		cout << "\nEnter (y/n)";
		cin >> read;
		if (read == 'y')
		{
			fstream fout;
			fout.open("list.txt", ios::out);
			long sum = 0;
			int d = 1;
			for (int s = strlen(quantity[v]) - 1; s >= 0; s--)
			{
				sum += (quantity[v][s] - 48)*d;
				d *= 10;
			}
			sum += Pquantity;



			/*sum = (long)quantity[v];

			cout << "sum" << sum;*/

			_itoa_s(sum, quantity[v], 10);

			for (int m = 0; m < count; m++)
			{
				fout << serial[m] << ";";
				fout << name[m] << ";";
				fout << price[m] << ";";
				fout << quality[m] << ";";
				fout << quantity[m] << ";" << "\n";
			}
			long ati = atoi(price[v])*Pquantity;
			cout << "\n" << ati << " Rupees has been truncated from shop account\n";
		}
		else if (read == 'n');
		else
		{
			system("cls");
			goto AA;
		}
		//char y='n';
		//printf("%d",y);
	}
}
void list::goods()
{
	char pricestr[20];
	char str[2000];
	ifstream fin;
	fin.open("list.txt", ofstream::in);

	//char s[2000];
	count = 0;
	while (fin >> str)
	{

		int savei = 0;
		//cout<<str;
		//   cout<<strlen(str)<<" ";
		int i = 0;
		int d = 0;
		while (i < strlen(str))
		{

			if (str[i] == ';')
			{

				//cout<<"Savei="<<savei<<"\t"<<"i="<<i<<" ";
				char s[30];
				int l = 0;
				for (int j = savei; j < i; j++)
				{
					s[l] = str[j];
					l++;
				}
				s[l] = '\0';
				if (d == 0)
					strcpy_s(serial[count], s);
				else if (d == 1)
					strcpy_s(name[count], s);
				else if (d == 2)
					strcpy_s(price[count], s);
				else if (d == 3)
					strcpy_s(quality[count], s);
				else if (d == 4)
					strcpy_s(quantity[count], s);
				d++;
				//cout<<"strlen="<<l<<",s="<<s<<"\n";
				//char tab='\t';
				//printf("%5c",tab);

				i++;
				savei = i;
			}
			//printf("%c",str[i]);

			i++;

		}
		count++;
		if (fin.eof())
			break;
		//cout<<"\n";
	}
	fin.close();


}
void list::show_goods()
{
	cout << "p-id\t name\t  price\t   quality\tquantity(kg)\n";
	cout << "-----------------------------------------------------------\n";
	for (int v = 0; v < count; v++)
	{

		printf("%s", serial[v]);
		printf("%8s", name[v]);
		printf("%8s", price[v]);
		printf("%15s", quality[v]);
		printf("%10s", quantity[v]);
		printf("\n");
	}
}
int main()
{
	char s[50];
	char pass[50] = "password";
start:
	system("cls");
	cout << "\t\t\t\tStore management system\n";
	cout << "\n\n\n Input password to access the system\n";
	cin >> s;
	if ((strcmp(s, pass) == 0))
	{
	A:
		system("cls");
		cout << "Make your choice:\n[1] For see products\n[2] For order products\n[3] For quit\n\n";
		list ob;
		char a;
		cin >> a;
		system("cls");
		ob.goods();
		if (a == 49)
			ob.show_goods();
		else if (a == 50)
			ob.order_goods();
		else if (a == 51)
			exit(0);
		else
			goto A;
		cout << "\n\nPress any key to return to Main Menu.";
		_getch();
		goto A;
	}
	else
	{
		system("cls");
		cout << "incorrect password";
		goto start;
	}
}
