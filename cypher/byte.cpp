//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <iostream.h>

var1()
{
int x, z, i;
cout << "x?";
cin >> x;
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var2()
{
int x, z, i;
cout << "x? i?";
cin >> x >> i;
z = (x>>i&1);
cout << z;
getch();
return 0;
}

var3()
{
int x, z, i, k0=0, k1=0;
cout << "x?";
cin >> x;
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 if (z == 0)
 k0+=1;
 else
 k1+=1;
 }
cout << "\nNumber of 0: " << k0 << "\nNumber of 1: " << k1;
getch();
return 0;
}

var4()   //противоположный
{
int x, z, i;
cout << "x? i?";
cin >> x >> i;
x = x|1<<i;
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var5()  //противоп
{
int x, z, i;
cout << "x? i?";
cin >> x >> i;
z = (x>>i&1);
if (z == 1)
x = x^1<<i;
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var6()
{
int x, z, i;
cout << "x? i?";
cin >> x >> i;
z = x>>i&1;
if (z == 0)
x = x|1<<i;
else
x = x^1<<i;
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var7()
{
int x, z, i, k;
cout << "x? k?";
cin >> x >> k;
for (i = 31; i >= 0; i--)
 {
 z = x>>i&1;
 if (i != k)
 {
 if (z == 1)
 x = x^1<<i;
 }
 }
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var8()
{
int x, z, i, k;
cout << "x? k?";
cin >> x >> k;
for (i = 31; i >= 0; i--)
 {
 z = x>>i&1;
 if (i != k)
 {
 if (z == 0)
 x = x^1<<i;
 }
 }
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var9()
{
int x, z, i, zi, zk, k;
cout << "x? i? k?";
cin >> x >> i >> k;
zk = (x>>k&1);
zi = (x>>i&1);
if (zk == 1)
x = x|1<<i;
else
x = x^1<<i;
if (zi == 1)
x = x|1<<k;
else
x = x^1<<k;
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var10()
{
int x, z, i, k, buf;
cout << "x? k?";
cin >> x >> k;
for (i = 0; i < k; i++)
{
buf = (x>>31&1);
x = x<<1;
x = x^buf<<0;
}
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

var11()
{
int x, z, i, k, buf;
cout << "x? k?";
cin >> x >> k;
for (i = 0; i < k; i++)
{
buf = (x>>0&1);
x = x>>1;
z = (x>>31&1);
if (z == 1)
x = x^1<<31;
x = x^buf<<31;
}
cout << "\n";
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z << " ";
 }
getch();
return 0;
}

main()
{
int buffer;
cout << "\n\nEnter number (0-9 to 2-11 or letter to 1): ";
buffer = getchar();
switch(buffer)
{
case '0': var2(); break;
case '1': var3(); break;
case '2': var4(); break;
case '3': var5(); break;
case '4': var6(); break;
case '5': var7(); break;
case '6': var8(); break;
case '7': var9(); break;
case '8': var10(); break;
case '9': var11(); break;
default: var1(); break;
}
return 0;
}


