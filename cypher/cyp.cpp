//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

int buf=0;
unsigned char buf0;
unsigned char set;
int massivn[8];
int massivc[8];
int massivs[16];
int massivf[16][16];


cypher()
{
//code block
cout << endl;
cout << "Enter output file: ";
unsigned char filet[1024];
cin >> filet;
cout << endl;
cout << "Write text: ";
ofstream f;
f.open(filet);
while (set!='~')
{
set=getch(); cout << set;
if (set=='~')
break;
   for (int j=0; j<16; j++)
   {
   for (int i=0; i<16; i++)
   {
   if(set==massivf[i][j])
   {
   f << massivs[i] << " " << massivs[j] << " ";
   }
   }
   }
}
f.close();
return 0;
}

decypher()
{
cout << endl;
cout << "Enter input file: ";
unsigned char filet[1024];
cin >> filet;
ifstream r;
int f0,l0;
cout << endl;
//decode block;
r.open("txt.txt");
r >> f0 >> l0;
while(!r.eof())
{
//cout << f0 << l0;
for (int i=0; i<16; i++)
{
if (massivs[i]==f0)
{
f0=i;
break;
}
}
for (int i=0; i<16; i++)
{
if (massivs[i]==l0)
{
l0=i;
break;
}
}
set=massivf[f0][l0];
cout << set;
r >> f0 >> l0;
}
r.close();
return 0;
}

getvec()
{
cout << "Enter the vector (8 numbers): ";
for (int i=0; i<8; i++)
{
buf = 0;
buf=getch();
while (buf>240) buf--;
cout << buf-48;
massivn[i]=buf;
}
cout << "\nEnter the keyword (8 characters): ";
for (int i=0; i<8; i++)
{
buf0=getch();
buf=buf0;
while (buf>240) buf--;
cout << buf0;
massivc[i]=buf;
}
for (int k=0; k<10; k++)
{
for (int j=0; j < 8; j++)
{
buf=massivn[j];
//cout << buf;
 for (int i=1; i < 8; i++)
 {
 if (massivn[i]==buf && i!=j)
 {
 massivn[j]++;
 buf++;
 }
}
}
}
for (int k=0; k<10; k++)
{
for (int j=0; j < 8; j++)
{
buf=massivc[j];
//cout << buf;
 for (int i=1; i < 8; i++)
 {
 if (massivc[i]==buf && i!=j)
 {
 massivc[j]++;
 buf++;
 }
}
}
}
for (int i=0; i<16; i++)
{
int j0=0;
j0=i;
if (j0>7)
j0-=8;
if (i+1%2==0)
massivs[i]=massivn[j0];
else
massivs[i]=massivc[j0];
}
for (int k=0; k<20; k++)
{
for (int j=0; j < 16; j++)
{
buf=massivs[j];
//cout << buf;
 for (int i=1; i < 16; i++)
 {
 if (massivs[i]==buf && i!=j)
 {
 massivs[j]++;
 buf++;
 }
}
}
}
int k=0;
for (int j=0; j<16; j++)
{
for (int i=0; i<16; i++)
{
k++;
massivf[i][j]=k;
}
}
return 0;
}

main()
{
cout << "***\t\t\tTDSV Oct Cypher\t\t\t***\n **\t\t\t               \t\t\t**\n\nGet started!\n";
getvec();
char menu;
cout << "\n\nChoose action:\n\t1. Cypher\n\t2. Decypher\n";
menu=getch();
switch(menu)
{
case '1':
cypher();
break;
case '2':
decypher();
break;
default:
exit(2);
}
getch();
}
//---------------------------------------------------------------------------
