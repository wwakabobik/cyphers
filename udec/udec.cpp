//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "udec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
WideString C, D;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int f1, f5, swap;
C=Edit1->Text;
D=Edit1->Text;
f1=C[1]; f5=C[5];
swap=f5-f1;
while (swap>10)
swap-=10;
int i=1;
while (C[i]!=0)
{
int swp0=0;
swp0=C[i];
swp0-=swap;
if (i%2==0 && i!=1 && i!=5)
swp0-=3;
else if (i%3==0 && i%2!=0 && i!=1 && i!=5)
swp0-=2;
if (C[i]!=' ')
D[i]=swp0;
else D[i]=C[i];
i++;
}
Edit2->Text=D;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int f1, f5, swap;
C=Edit2->Text;
D=Edit2->Text;
f1=C[1]; f5=C[5];
swap=f5-f1;
while (swap>10)
swap-=10;
int i=1;
while (D[i]!=0)
{
int swp0=0;
swp0=D[i];
swp0+=swap;
if (i%2==0)
swp0+=3;
else if (i%3==0 && i%2!=0)
swp0+=2;
if (D[i]!=' ')
C[i]=swp0;
else C[i]=D[i];
i++;
}
Edit1->Text=C;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
exit(0);
}
//---------------------------------------------------------------------------
