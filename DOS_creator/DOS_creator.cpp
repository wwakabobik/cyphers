//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

unsigned char filename[1024];

main()
{
char set;
ofstream f;
cout << "Enter the file: ";
gets(filename);
f.open(filename);
if (!f) exit(0);
getchar();
getchar();
cout << "Write through spacer file chain (to exit \~): ";
f << "Not_Useble ";
for(;;)
{
set=getch();
if (set=='\~')
break;
cout << set;
if (set!=32)
set-=7;
f << set;
}
f.close();
return 0;
}
