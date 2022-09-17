//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <math.h>

ascii_c()
{
char x;
int z;
cout << "\n\nEnter char to convert to ASCII number: ";
cin >> x;
z = x;
cout << "Char " << x << " in ASCII encoding is #" << z << "\n\nPress any key to return to main menu.";
getch();
return 0;
}

ascii_t()
{
int i, z;
char x;
for (i = 1; i < 7; i++)
{
x = i;
cout << i << " " << x << "   ";
}
cout << "\nEnter to continue.";
getch();
cout << "\n";
for (i = 14; i < 100; i++)
{
x = i;
cout << i << " " << x << "   ";
}
cout << "\nEnter to continue.";
getch();
cout << "\n";
for (i = 100; i < 256; i++)
{
x = i;
cout << i << " " << x << "   ";
}
cout << "\n\nPress any key to return to main menu";
getch();
return 0;
}

bul()
{
int i, z;
long x;

cout << "\n\nEnter number to convert to binary format: ";
cin >> x;
cout << "\n";
for (i = 31; i >= 0; i--)
 {
 z = (x>>i&1);
 cout << z;
 }
cout << "\n\nPress any key to return to main menu ";
getch();
return 0;
}

revers()
{
getchar();
int x; char y;
cout << "Enter number to convert to symbol format: ";
cin >> x;
y = x;
cout << "\nNumber " << x << " is symbol "<< y << "\nPress any to fuck-off!";
getch();
}

revbul()
{
getchar();
int x=0;
int y;
int z;
cout << "\nEnter bool number to convert in normal: ";
cin >> y;
for (int i=0; i <= 9; i++)
{
z=y%10;
y=y/10;
x = x|z<<i;
}
cout << "\nNumber is " << x;
getch();
}

code()
{
getchar();
fstream f;
char set;
char file[13];
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~')
{
set=getch();
cout << set;
if (set == '~')
break;
x = set;
for (int j = 8; j >= 0; j--)
 {
 z = (x>>j&1);
 f << z;
 }
f << " ";
}
f.close();
}

decode()
{
getchar();
fstream f;
int x, z, y;
char file[13];
char set;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
while (!f.eof())
{
x=0;
f >> y;
for (int i=0; i <= 8; i++)
{
z=y%10;
y=y/10;
x = x|z<<i;
}
set = x;
cout << set;
}
f.close();
getch();
}



//----Enigma coding------------------------
int massiv[256];
int methodw;
int methodr;
int stepr;
int stepw;
int r1;
int r2;
int r3;
char file[13];

enigmad9() //позиционная дешифровка
{
int num=0, temp, rnd, num1=0, num2=0, num0=0;
getchar();
fstream f;
unsigned char set;
int x, z;
num1=128;
f >> r1 >> methodw >> r2 >> stepw >> r3;
f.open(file);
while (!f.eof())
{
num2++;
f >> temp;
if (((temp%13==0) && (temp%66==0)) && ((temp%7!=0) || (temp%29!=0)))
{
cout << " num 2: " << num2 << "  "; getch();
num0=(num2-1+num1);
//cout << num0 << " num2: " << num2;
set = num0;
//cout << set;
num1=num0;
num2=0;
}
if (((temp%7==0) && (temp%29==0)) && ((temp%13!=0) || (temp%66!=0)))
{
cout << " num 2: " << num2 << "  "; getch();
num0=(num1-num2-1);
//cout << num0 << "num2: " << num2;
set = num0;
//cout << set;
num1=num0;
num2=0;
}
}
f.close();
getch();
}

enigmac9() //позиционное кодирование
/*Выбирается первый значимый элемент, априорно равный 128.
После ввода символа пользователем устанавливается абсолютная разница между
элементом 128 и вводимым т.е. abs(num1-num2) и записывается случайное число
через (num0+1) символов, с тем условием, что если num0<0 то символ temp должен
соответствовать условиям
(((z%(abs(((r1-100000000)/10000)/2))==0) && (z%13==0) && (z%66==0)) && ((z%(abs(((r3-100000000)/10000)/7))!=0) || (z%7!=0) || (z%29!=0)))
если num0>=0
(((z%(abs(((r3-100000000)/10000)/7))==0) && (z%7==0) && (z%29==0)) && ((z%(abs(((r1-100000000)/10000)/2))!=0) || (z%13!=0) || (z%66!=0)))
так заполнение {r1, method, r2, step, r3, числа с промежутками с мусором}*/
{
int num=0, temp, rnd, num1=0, num2=0, num0=0;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
cout << "\nWrite secret info. To escape enter \"~\"\n";
num1=128;
while (set != '~') //ввод текста
{
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 255+x;
num0=abs(num1-x);
for (int i = 0; i < num0; i++)
{
temp=100000000+random(900000000);
while (((temp%13==0) || (temp%66==0)) && ((temp%7==0) || (temp%29==0)))
temp=100000000+random(900000000);
f << temp << " ";
}
if ((num1-x)<0)
{
for (int i = 0; i < 100; i--)
{
z=100000000+random(900000000);
if (((z%13==0) && (z%66==0)) && ((z%7!=0) || (z%29!=0))) break;
}
}
else
{
for (int i = 0; i < 100; i--)
{
z=100000000+random(900000000);
if (((z%7==0) && (z%29==0)) && ((z%13!=0) || (z%66!=0))) break;
}
}
cout << " NUM2:" << abs(num1-x) << endl;
num1=x;
f << z;
f << " ";
}
f.close();
}



enigmac9h() //сложное !!! алгоритм медленный!!! позиционное кодирование
/*Выбирается первый значимый элемент, априорно равный 128.
После ввода символа пользователем устанавливается абсолютная разница между
элементом 128 и вводимым т.е. abs(num1-num2) и записывается случайное число
через (num0+1) символов, с тем условием, что если num0<0 то символ temp должен
соответствовать условиям
(((z%(abs(((r1-100000000)/10000)/2))==0) && (z%13==0) && (z%66==0)) && ((z%(abs(((r3-100000000)/10000)/7))!=0) || (z%7!=0) || (z%29!=0)))
если num0>=0
(((z%(abs(((r3-100000000)/10000)/7))==0) && (z%7==0) && (z%29==0)) && ((z%(abs(((r1-100000000)/10000)/2))!=0) || (z%13!=0) || (z%66!=0)))
так заполнение {r1, method, r2, step, r3, числа с промежутками с мусором}*/
{
int num=0, temp, rnd, num1=0, num2=0, num0=0;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
cout << "\nWrite secret info. To escape enter \"~\"\n";
num1=128;
while (set != '~') //ввод текста
{
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 255+x;
num0=abs(num1-x);
for (int i = 0; i < num0; i++)
{
z=100000000+random(900000000);
//while (((temp%13!=0) || (temp%66!=0)) && ((temp%7!=0) || (temp%29!=0)))
while (((z%(abs(((r1-100000000)/10000)/2))!=0) || (z%13!=0) || (z%66!=0)) && ((z%(abs(((r3-100000000)/10000)/7))!=0) || (z%7!=0) || (z%29!=0)))
z=100000000+random(900000000);
f << z << " ";
}
if ((num1-x)<0)
{
z=100000000+random(900000000);
//while (((z%13==0) && (z%66==0)) && ((z%7!=0) || (z%29!=0)))
while (((z%(abs(((r1-100000000)/10000)/2))==0) && (z%13==0) && (z%66==0)) && ((z%(abs(((r3-100000000)/10000)/7))!=0) || (z%7!=0) || (z%29!=0)))
z=100000000+random(900000000);
}
else
{
z=100000000+random(900000000);
//while (((z%7==0) && (z%29==0)) && ((z%13!=0) || (z%66!=0)))
while (((z%(abs(((r3-100000000)/10000)/7))==0) && (z%7==0) && (z%29==0)) && ((z%(abs(((r1-100000000)/10000)/2))!=0) || (z%13!=0) || (z%66!=0)))
z=100000000+random(900000000);
}
num1=x;
f << z;
f << " ";
}
f.close();
}


enigmad8() //обратная сложная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f >> massiv[i];
for (int k=1; k <=stepr; k++)
f >> temp;
}
while (!f.eof())
 {
 x = 0;
 num++;
 temp=num%stepr;
 if (temp!=0)
  {
  f >> x;
  for (int i = 1; i < 255; i++)
  if (massiv[i]==x)
  {
   y = i;
   set = y;
   cout << set;
  }
 }
 else for (int k =1; k <= stepr; k++)
 f >> temp;
}
f.close();
getch();
}


enigmac8() //сложное обратное кодирование
/* В алгоритме сложного кодирования символы
располагаются следующим образом - {первая метка, метод,
вторая метка, шаг, третья метка, таблица кода в обратном
порядке с мусором, равным шагу через каждый символ
таблицы кода, текст с мусором, равным шагу, причем
мусор состоит из символов таблицы кода}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f << massiv[i] << " ";
for (int k=1; k <=stepr; k++)
{
int h;
h=random(254)+1;
rnd = massiv[h];
f << rnd << " ";
}
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
for (int k =1; k <= stepr; k++)
{
int h;
h=random(254)+1;
rnd = massiv[h];
f << rnd << " ";
}
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 255+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}

enigmad7() //прямая сложная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=1; i < 255; i++) //задание таблицы символов
{
f >> massiv[i];
for (int k=1; k <=stepr; k++)
f >> temp;
}
while (!f.eof())
 {
 x = 0;
 num++;
 temp=num%stepr;
 if (temp!=0)
  {
  f >> x;
  for (int i = 1; i < 255; i++)
  if (massiv[i]==x)
  {
   y = i;
   set = y;
   cout << set;
  }
 }
 else for (int k =1; k <= stepr; k++)
 f >> temp;
}
f.close();
getch();
}


enigmac7() //сложное прямое кодирование
/* В алгоритме сложного кодирования символы
располагаются следующим образом - {первая метка, метод,
вторая метка, шаг, третья метка, таблица кода в прямом
порядке с мусором, равным шагу через каждый символ
таблицы кода, текст с мусором, равным шагу, причем
мусор состоит из символов таблицы кода}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=1; i < 255; i++) //задание таблицы символов
{
f << massiv[i] << " ";
for (int k=1; k <=stepr; k++)
{
int h;
h=random(254)+1;
rnd = massiv[h];
f << rnd << " ";
}
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
for (int k =1; k <= stepr; k++)
{
int h;
h=random(254)+1;
rnd = massiv[h];
f << rnd << " ";
}
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 256+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}



enigmad6() //обратная ложная двойная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f >> massiv[i];
for (int k=1; k <=stepr; k++)
f >> temp;
}
while (!f.eof())
 {
 x = 0;
 num++;
 temp=num%stepr;
 if (temp!=0)
  {
  f >> x;
  for (int i = 1; i < 255; i++)
  if (massiv[i]==x)
  {
   y = i;
   set = y;
   cout << set;
  }
 }
 else for (int k =1; k <= stepr; k++)
 f >> temp;
}
f.close();
getch();
}


enigmac6() //обратное ложное двойное кодирование
/* В алгоритме прямого ложного кодирования символы
располагаются следующим образом - {первая метка, метод,
вторая метка, шаг, третья метка, таблица кода в обратном
порядке с мусором, равным шагу через каждый символ
таблицы кода, текст с мусором, равным шагу}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f << massiv[i] << " ";
for (int k=1; k <=stepr; k++)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
for (int k =1; k <= stepr; k++)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 256+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}





enigmad5() //прямая ложная двойная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=1; i < 255; i++) //задание таблицы символов
{
f >> massiv[i];
for (int k=1; k <=stepr; k++)
f >> temp;
}
while (!f.eof())
 {
 x = 0;
 num++;
 temp=num%stepr;
 if (temp!=0)
  {
  f >> x;
  for (int i = 1; i < 255; i++)
  if (massiv[i]==x)
  {
   y = i;
   set = y;
   cout << set;
  }
 }
 else for (int k =1; k <= stepr; k++)
 f >> temp;
}
f.close();
getch();
}


enigmac5() //прямое ложное двойное кодирование
/* В алгоритме прямого ложного кодирования символы
располагаются следующим образом - {первая метка, метод,
вторая метка, шаг, третья метка, таблица кода в прямом
порядке с мусором, равным шагу через каждый символ
таблицы кода, текст с мусором, равным шагу}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=1; i < 255; i++) //задание таблицы символов
{
f << massiv[i] << " ";
for (int k=1; k <=stepr; k++)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
for (int k =1; k <= stepr; k++)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 256+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}



enigmad4() //обратная ложная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f >> massiv[i];
for (int k=1; k <=stepr; k++)
f >> temp;
}
while (!f.eof())
{
x = 0;
num++;
temp=num%stepr;
if (temp!=0)
{
f >> x;
for (int i = 1; i < 255; i++)
if (massiv[i]==x)
{
y = i;
set = y;
cout << set;
}
}
}
f.close();
getch();
}


enigmad3() //прямая ложная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=1; i < 255; i++) //задание таблицы символов
{
f >> massiv[i];
for (int k=1; k <=stepr; k++)
f >> temp;
}
while (!f.eof())
 {
 x = 0;
 num++;
 temp=num%stepr;
 if (temp!=0)
  {
  f >> x;
  for (int i = 1; i < 255; i++)
  if (massiv[i]==x)
  {
   y = i;
   set = y;
   cout << set;
  }
 }
}
f.close();
getch();
}



enigmad2() //обратная дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f >> massiv[i];
}
while (!f.eof())
{
x = 0;
num++;
temp=num%stepr;
if (temp!=0)
{
f >> x;
for (int i = 1; i < 255; i++)
if (massiv[i]==x)
{
y = i;
set = y;
cout << set;
}
}
}
f.close();
getch();
}



enigmad1() //прямая дешифровка
{
int num=0, temp, rnd;
getchar();
fstream f;
int x, z, y;
char set;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000);
methodr=methodw-100000000-r1+r2-r3;
for (int i=1; i < 255; i++) //задание таблицы символов
{
f >> massiv[i];
}
while (!f.eof())
{
x = 0;
num++;
temp=num%stepr;
if (temp!=0)    //проверка на мусорный элемент
{
f >> x;
for (int i = 1; i < 255; i++) //сравнение символа с таблицей кода
if (massiv[i]==x)             //и выдача символа по номеру
{
y = i;
set = y;
cout << set;
}
}
}
f.close();
getch();
}

enigmad() //программа дешифровки
{
fstream f;
int x, z, y;
char set;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f >> r1 >> methodw >> r2 >> stepw >> r3;
stepr=(stepw-100000000)/(r1-100000000); //реальный шаг
methodr=methodw-100000000-r1+r2-r3;     //реальный метод
f.close();
if (methodr == 1) //выбор алгоритма дешифровки
enigmad1();
if (methodr == 2)
enigmad2();
if (methodr == 3)
enigmad3();
if (methodr == 4)
enigmad4();
if (methodr == 5)
enigmad5();
if (methodr == 6)
enigmad6();
if (methodr == 7)
enigmad7();
if (methodr == 8)
enigmad8();
if (methodr == 9)
enigmad9();

}

enigmac4() // обратное ложное кодирование
/* В алгоритме обратного ложного кодирования символы
располагаются следующим образом - {первая метка, метод,
вторая метка, шаг, третья метка, таблица кода в обратном
порядке с мусором, равным шагу через каждый символ
таблицы кода, текст}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f << massiv[i] << " ";
for (int k=1; k <=stepr; k++)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 256+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}

enigmac3() //прямое ложное кодирование
/* В алгоритме прямого ложного кодирования символы
располагаются следующим образом - {первая метка, метод,
вторая метка, шаг, третья метка, таблица кода в прямом
порядке с мусором, равным шагу через каждый символ
таблицы кода, текст}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=1; i < 255; i++) //задание таблицы символов
{
f << massiv[i] << " ";
for (int k=1; k <=stepr; k++)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 256+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}

enigmac2() //обратное кодирование
/* В алгоритме обратного кодирования символы располагаются
следующим образом - {первая метка, метод, вторая метка,
шаг, третья метка, таблица кода в обратном порядке без
мусора, текст}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=254; i >= 1; i--) //задание таблицы символов
{
f << massiv[i] << " ";
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;
temp=num%stepr;
if (temp == 0)
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
else {
set=getch();
cout << set;
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80))
x = 256+x;
z=massiv[x];
f << z;
f << " ";
}
}
f.close();
}

enigmac1() //прямое кодирование
/* В алгоритме прямого кодирования символы располагаются
следующим образом - {первая метка, метод, вторая метка,
шаг, третья метка, таблица кода в прямом порядке без
мусора, текст}*/
{
int num=0, temp, rnd;
getchar();
fstream f;
char set;
int x, z;
cout << "\nEnter filename: "; cin >> file;
f.open(file);
f << r1 << " " << methodw << " " << r2 << " " << stepw << " " << r3 << " ";
for (int i=1; i < 255; i++) //задание таблицы символов
{                           //в текущем файле
f << massiv[i] << " ";
}
cout << "\nWrite secret info. To escape enter \"~\"\n";
while (set != '~') //ввод текста
{
num++;          //номер текущего кодируемого элемента
temp=num%stepr;
if (temp == 0)  //проверка на принадлежность к мусорному знаку
{
rnd = 100000000+random(900000000);
f << rnd << " ";
}
else {
set=getch();
cout << set; //ввод буквы
if (set == '~')
break;
x = set;
if ((x > -129 && x < -80) || (x < -16 && x > -80)) //преобразование русских букв
x = 256+x;
z=massiv[x]; //кодирование и ввод согласно таблице кода
f << z;
f << " ";
}
}
f.close();
}


enigmac() //программа кодирования
{
getchar();
randomize();
r1=100000000+random(90000000); //кодирование меток
r2=100000000+random(90000000); //кодирование меток
r3=100000000+random(90000000); //кодирование меток
stepr=random(4)+2;             //кодирование настоящего шага
//cout << stepr;
stepw=100000000+stepr*(r1-100000000); //кодирование шага вывода
methodr=9;
//methodr=(random(9)+1);                //кодирование настоящего метода
methodw=100000000+r1-r2+r3+methodr;   //кодирование метода вывода
for (int m = 1; m <= 256; m++)        //кодирование таблицы
{                                     //кода и предотвращение
for (int i = 1; i <= 256; i++)        //возможности появления дупликатов
{                                     //проходится до конца
for (int j = 1; j <= 256; j++)        //таблицы символов
{
if (massiv[i]==massiv[j] && i!=j)
massiv[i]=100000000+random(900000000);
}
}
}
//cout << methodr;
if (methodr == 1)               //передача управления
enigmac1();                     //машине создания
if (methodr == 2)               //закодированного текста
enigmac2();
if (methodr == 3)
enigmac3();
if (methodr == 4)
enigmac4();
if (methodr == 5)
enigmac5();
if (methodr == 6)
enigmac6();
if (methodr == 7)
enigmac7();
if (methodr == 8)
enigmac8();
if (methodr == 9)
enigmac9();


/*---!!!!!ПРОВЕРКА НА ДУПЛИКАТЫ!!!!!!!!!!!!!!!---
for (int i = 1; i <= 256; i++)
{
for (int j = 1; j <= 256; j++)
{
if (massiv[i]==massiv[j] && i!=j)
cout << "!";
}
}
*/
/*----Вывод таблицы кода------
cout << "\nr1: " << r1 << "\nr2: " << r2 << "\nr3: " << r3 << "\nMethod: " << method;
getch();
for (int i = 1; i <= 256; i++)
cout << " " << massiv[i];
*/
}

main()
{
int buffer;
cout << "1. Char to number\n2. ASCII\n3. Number to bool\n4. Number to char\n5. Bool to number\n6. Code secret data\n7. Decode secret data\n8. Enigma coding \n9. Enigma decoding\nAny to exit";
buffer = getchar();
switch(buffer)
{
case '1':
ascii_c();
break;
case '2':
ascii_t();
break;
case '3':
bul();
break;
case '4':
revers();
break;
case '5':
revbul();
break;
case '6':
code();
break;
case '7':
decode();
break;
case '8':
enigmac();
break;
case '9':
enigmad();
break;
}
return 0;
}
