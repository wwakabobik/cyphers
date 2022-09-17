//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cypher.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <stdio.h>
#include <io.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

//WideString R0;
int buf=0;
//int i0;
unsigned char buf0;
//unsigned
char set;
unsigned char filename[1024];
unsigned char filenamer[1024];
int massivn[8];
int massivc[8];
int massivs[16];
int massivf[16][16];

cypher()
{
//code block
cout << endl;
//cout << "Enter output file: ";
//unsigned char filet[1024];
//cin >> filet;
//cout << endl;
//cout << "Write text: ";
ofstream f;
//ofstream wr;
ifstream r0;
r0.open(filenamer);
f.open(filename,ios::out);
//wr.open("test1.txt");
//i0=0;
//r0 >> set;
r0.get(set);
//ofstream wrc;
//wrc.open("testr.txt");
for (;;)
{
/*int cont0;
cont0=set;
wrc << cont0;
unsigned char set0;
if (cont0<0)
{
set0=cont0+90;
wrc << set0;
}
i0++; */
//wr << set;
//set=R0[i0];
//if (R0[i0]==0)
if (r0.eof())
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
r0.get(set);
//r0 >> set;
}
f.close();
return 0;
}

decypher()
{
//cout << endl;
//cout << "Enter input file: ";
//unsigned char filet[1024];
//cin >> filet;
ifstream r;
ofstream w0;
w0.open(filenamer,ios::out);
int f0,l0;
cout << endl;
//decode block;
r.open(filename);
r >> f0 >> l0;
//i0=1;
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
//R0[i0]=set;
w0 << set;
//i0++;
r >> f0 >> l0;
}
//w0 << R0;
r.close();
w0.close();
return 0;
}

getvec()
{
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

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Timer1->Enabled=true;
ifstream r;
int buf,sta,tm9;
r.open(filename);
randomize();
tm9=random(10);
for (int i=0; i<tm9; i++)
r >> buf;
if (r)
{
if (r.eof())
{
r.close();
r.open(filename);
}
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel1->Caption=buf%10;
else
Panel1->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel2->Caption=buf%10;
else
Panel2->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel3->Caption=buf%10;
else
Panel3->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel4->Caption=buf%10;
else
Panel4->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel5->Caption=buf%10;
else
Panel5->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel6->Caption=buf%10;
else
Panel6->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel7->Caption=buf%10;
else
Panel7->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel8->Caption=buf%10;
else
Panel8->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel9->Caption=buf%10;
else
Panel9->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel10->Caption=buf%10;
else
Panel10->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel11->Caption=buf%10;
else
Panel11->Caption=buf/10;
r >> buf;
sta=random(2);
if (sta==1 && !r.eof())
Panel12->Caption=buf%10;
else
Panel12->Caption=buf/10;
r.close();
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit3Click(TObject *Sender)
{
if (OpenDialog1->Execute())
Edit3->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
Timer1->Enabled=true;
WideString H0;
H0=Edit3->Text;
int i=1;
for(;;)
{
if (H0[i]==0)
break;
filename[i-1]=H0[i];
i++;
}
filename[i-1]='\0';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Click(TObject *Sender)
{
if (OpenDialog2->Execute())
Edit4->Text=OpenDialog2->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
WideString H0;
H0=Edit4->Text;
int i=1;
for(;;)
{
if (H0[i]==0)
break;
filenamer[i-1]=H0[i];
i++;
}
filenamer[i-1]='\0';
/*ifstream r;
ofstream w;
r.open("1.txt");
w.open("t1.txt");
char set0;
r.get(set0);
while (!r.eof())
{
w.put(set0);
r.get(set0);
}
r.close();
w.close(); */
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Panel13Click(TObject *Sender)
{
WideString t;
//R0=Edit3->Text;
t=Edit1->Text;
massivn[0]=t[1];
massivn[1]=t[2];
massivn[2]=t[3];
massivn[3]=t[4];
massivn[4]=t[5];
massivn[5]=t[6];
massivn[6]=t[7];
massivn[7]=t[8];
t=Edit2->Text;
massivc[0]=t[1];
massivc[1]=t[2];
massivc[2]=t[3];
massivc[3]=t[4];
massivc[4]=t[5];
massivc[5]=t[6];
massivc[6]=t[7];
massivc[7]=t[8];
getvec();
cypher();
//decypher();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel14Click(TObject *Sender)
{
WideString t;
//R0=Edit3->Text;
t=Edit1->Text;
massivn[0]=t[1];
massivn[1]=t[2];
massivn[2]=t[3];
massivn[3]=t[4];
massivn[4]=t[5];
massivn[5]=t[6];
massivn[6]=t[7];
massivn[7]=t[8];
t=Edit2->Text;
massivc[0]=t[1];
massivc[1]=t[2];
massivc[2]=t[3];
massivc[3]=t[4];
massivc[4]=t[5];
massivc[5]=t[6];
massivc[6]=t[7];
massivc[7]=t[8];
getvec();
//cypher();
decypher();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2Click(TObject *Sender)
{
Timer1->Enabled=false;
Form1->Close();
//exit(0);
}
//---------------------------------------------------------------------------

