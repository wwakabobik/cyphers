//---------------------------------------------------------------------------

#ifndef cypherH
#define cypherH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TPanel *Panel1;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label1;
        TTimer *Timer1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel7;
        TPanel *Panel8;
        TPanel *Panel9;
        TPanel *Panel10;
        TPanel *Panel11;
        TPanel *Panel12;
        TOpenDialog *OpenDialog1;
        TEdit *Edit4;
        TOpenDialog *OpenDialog2;
        TPanel *Panel13;
        TPanel *Panel14;
        TLabel *Label2;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall Edit4Click(TObject *Sender);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall Panel13Click(TObject *Sender);
        void __fastcall Panel14Click(TObject *Sender);
        void __fastcall Label2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
