//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TTimer *fpsTimer;
	TTimer *SceneTimer;
	TButton *Button1;
	TCheckBox *CheckBox1;
	TLabel *FpsLabel;
	TLabel *ScoreLabel;
	void __fastcall FormCreate(TObject *Sender);
    void __fastcall DinoRun();
    void __fastcall DinoStartJump();
    void __fastcall DinoJump();
	void __fastcall Image1Click(TObject *Sender);
    void __fastcall CactusMove();
    void __fastcall BgMove();
    void __fastcall CloudMove();
    void __fastcall DrawScene();
    void __fastcall UpdateScene();
	void __fastcall SceneTimerTimer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall fpsTimerTimer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
