//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "AnimatedSprite.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *spriteBitMap = new Graphics::TBitmap(),
                   *bgBitMap = new Graphics::TBitmap(),
                   *cloudBitMap = new Graphics::TBitmap(),
                   *UnderDinoBitMap = new Graphics::TBitmap(),
                   *TempBitMap = new Graphics::TBitmap(),
                   *TempBitMap2 = new Graphics::TBitmap(),
                   *SceneBitMap = new Graphics::TBitmap(),

                   *cactusBitMap = new Graphics::TBitmap(),
                   *UnderCactusBitMap = new Graphics::TBitmap();

TRect UnderDinoTRect, bgUnderDinoTRect, ZeroTRect;
TRect CactusTRect, bgUnderCactusTRect;
TRect CloudTRect;
AnimatedSprite  *dinoSprite = new AnimatedSprite(),
				*bgSprite = new AnimatedSprite(),
                *cactusSprite = new AnimatedSprite(),
                *cloudSprite = new AnimatedSprite();

int currentDinoShot = 0;//, w, h;
const int dinoShotsAmount = 9, dinoRunShotsAmount = 6, margineX = 50, margineY = 160;
bool dinoIsJumping = false, dinoIsDead = false, autoJump = true;
int score = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    //Set default values
    spriteBitMap -> LoadFromFile("dino_spritesheet.bmp");
    spriteBitMap -> Transparent = true;

    dinoSprite = new AnimatedSprite(spriteBitMap, dinoShotsAmount);
    dinoSprite -> sprite_bmp -> Transparent = true;
    //w = dinoSprite -> w;
    //h = dinoSprite -> h;

    SceneBitMap  -> LoadFromFile("bg.bmp");
    bgBitMap -> LoadFromFile("bg.bmp");
    cactusBitMap -> LoadFromFile("cactus.bmp");
    cactusBitMap -> Transparent = true;

    cloudBitMap -> LoadFromFile("cloud_spritesheet.bmp");
    cloudBitMap -> Transparent = true;
    cloudSprite = new AnimatedSprite(cloudBitMap, 5);
    CloudTRect = Bounds (0,0, cloudSprite -> w, cloudSprite -> h);

    UnderDinoBitMap -> Width = dinoSprite -> w;
    UnderDinoBitMap -> Height = dinoSprite -> h;

    UnderCactusBitMap -> Width = cactusBitMap -> Width;
    UnderCactusBitMap -> Height = cactusBitMap -> Height;

    UnderDinoTRect = Bounds (margineX, margineY, dinoSprite -> w, dinoSprite -> h);
    bgUnderDinoTRect = Bounds (0,0, dinoSprite -> w, dinoSprite -> h);

    CactusTRect = Bounds (400, margineY+40, cactusBitMap -> Width, cactusBitMap -> Height);
    bgUnderCactusTRect = Bounds (0, 0, cactusBitMap -> Width, cactusBitMap -> Height);

    UnderDinoBitMap -> Canvas -> CopyRect(bgUnderDinoTRect, bgBitMap -> Canvas, UnderDinoTRect);
    UnderCactusBitMap -> Canvas -> CopyRect(bgUnderCactusTRect, bgBitMap -> Canvas, CactusTRect);


    SceneBitMap -> Canvas -> CopyMode = cmSrcCopy;

    ///Old debug
    //Image2 -> Canvas -> Draw(0,0,UnderDinoBitMap);
    //Image3 -> Canvas -> Draw(0,0,dinoSprite -> sprite_bmp);
    /*Image3 -> Canvas -> CopyRect(UnderDinoTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(0));  */

    ZeroTRect = Bounds (0,0, dinoSprite -> w, dinoSprite -> h);
    TempBitMap -> Width = dinoSprite -> w;
    TempBitMap -> Height = dinoSprite -> h;
    TempBitMap -> Transparent = true;

    TempBitMap2 -> Width = cloudSprite -> w;
    TempBitMap2 -> Height = cloudSprite -> h;
    TempBitMap2 -> Transparent = true;

    //Draw Dino on virtual scene
    TempBitMap -> Canvas -> CopyRect(ZeroTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(0));
    SceneBitMap -> Canvas -> Draw(margineX, margineY, TempBitMap);

    //Draw Cactus
    SceneBitMap -> Canvas -> Draw(400, margineY+45, cactusBitMap);

    ///Old version of drawing Dino
    /*SceneBitMap -> Canvas -> CopyRect(UnderDinoTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(0));*/

    //Draw virtual scene on main canvas
    Image1 -> Canvas -> Draw(0,0, SceneBitMap);
}


void __fastcall TForm1::DinoRun()
{
    //Clear Dino on virtual scene
    SceneBitMap -> Canvas -> Draw(margineX, margineY, UnderDinoBitMap);

    //Dino run animation
    currentDinoShot++;
    if(currentDinoShot >= dinoRunShotsAmount)
        currentDinoShot = 0;

    ////UnderDinoTRect = Bounds (margineX, margineY, dinoSprite -> w, dinoSprite -> h);

    //Draw Dino on virtual scene
    /*TempBitMap -> Canvas -> CopyRect(ZeroTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(currentDinoShot));
    SceneBitMap -> Canvas -> Draw(margineX, margineY, TempBitMap);  */

    //Draw virtual scene on main canvas
    //Image1 -> Canvas -> Draw(0,0,SceneBitMap);
}

float k;
int dinoY = 0;
void __fastcall TForm1::DinoStartJump()
{
    //Clear Dino on virtual scene
	SceneBitMap -> Canvas -> Draw(margineX, margineY, UnderDinoBitMap);

    //Set start values
    //Timer1 -> Enabled = false;
    //JumpTimer -> Enabled = true;
    k = 0;
    currentDinoShot = dinoRunShotsAmount;
    /*UnderDinoTRect = Bounds (margineX, margineY, dinoSprite -> w, dinoSprite -> h);

    //Draw Dino on virtual scene
    TempBitMap -> Canvas -> CopyRect(ZeroTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(currentDinoShot));
    SceneBitMap -> Canvas -> Draw(margineX, margineY, TempBitMap);

    //Draw virtual scene on main canvas
    //Image1 -> Canvas -> Draw(0,0,SceneBitMap);*/

    dinoIsJumping = true;
}

void __fastcall TForm1::DinoJump()
{
    //Clear Dino on the virtual scene
    SceneBitMap -> Canvas -> Draw(margineX, margineY- dinoY, UnderDinoBitMap);

    //Jump Formula
    k+=1.25;
    dinoY = 0;
    if(k <= 40)
       dinoY += 3*k;
    else if(k<=50)
    {
       if(k==45)
          currentDinoShot++;
       dinoY = 40*3;
    }

    else if(k <= 90)
    {
        //if(k == 61)
        	//currentDinoShot++;
        dinoY += 3*(90-k);
    }
    else
    {
        dinoY = 0;

        //JumpTimer -> Enabled = false;
		//Timer1 -> Enabled = true;
    	currentDinoShot = 0;

        dinoIsJumping = false;
        DinoRun();
    }
   /* UnderDinoTRect = Bounds (margineX, margineY-dinoY, dinoSprite -> w, dinoSprite -> h);
    //if(!dinoIsJumping)
    	UnderDinoBitMap -> Canvas -> CopyRect(bgUnderDinoTRect, bgBitMap -> Canvas, UnderDinoTRect);
    //else
        //UnderDinoBitMap -> Canvas -> CopyRect(bgUnderDinoTRect, SceneBitMap -> Canvas, UnderDinoTRect);
    //Draw Dino on virtual scene
    TempBitMap -> Canvas -> CopyRect(ZeroTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(currentDinoShot));
    SceneBitMap -> Canvas -> Draw(margineX, margineY-dinoY, TempBitMap); */

    //Draw virtual scene on main canvas
    //Image1 -> Canvas -> Draw(0,0,SceneBitMap);
}


//---------------------------------------------------------------------------

int cactusX = 400, t = 0;
void __fastcall TForm1::CactusMove()
{
    //Clear Cactus on the virtual scene
    SceneBitMap -> Canvas -> Draw(cactusX, margineY+45, UnderCactusBitMap);

    cactusX -= 3;
    if(cactusX <= -(cactusBitMap -> Width))
    {
        cactusX = 500;
        score++;
        ScoreLabel -> Caption = "Score: " + IntToStr(score);
    }

    //Dino AutoJump
    if(autoJump)
    	if(cactusX <= 180 && cactusX > 100 && !dinoIsJumping)
        	DinoStartJump();


    /*CactusTRect = Bounds (cactusX, margineY+45, cactusBitMap -> Width, cactusBitMap -> Height);
    if(!dinoIsJumping)
    	UnderCactusBitMap -> Canvas -> CopyRect(bgUnderCactusTRect, SceneBitMap -> Canvas, CactusTRect);
    else
        UnderCactusBitMap -> Canvas -> CopyRect(bgUnderCactusTRect, bgBitMap -> Canvas, CactusTRect);
    //Draw Cactus on virtual scene
    //TempBitMap -> Canvas -> CopyRect(ZeroTRect,
    							//dinoSprite -> sprite_bmp -> Canvas,
                                //dinoSprite -> ChangeSpriteAnimation(currentDinoShot));
    SceneBitMap -> Canvas -> Draw(cactusX, margineY+45, cactusBitMap); */

    //Draw virtual scene on main canvas
    //DrawScene();

}

double cloudX = 120, cloudY =20, p = 0;
int currentCloudShot = 0;

double cloudX2 = 500, cloudY2 = 50, p2 = 0;
int currentCloudShot2 = 2;

void __fastcall TForm1::CloudMove()
{
    p+=0.2;
    cloudX -= p/100;
    cloudY += sin(p)/2;

    if(cloudX < 0-(cloudSprite->w))
    {
        cloudX = 500;
        p = 0;
        cloudY = 20;
    }

    p2 += 0.20;
    cloudX2 -= p2/100;
    cloudY2 += sin(p2)/2;

    if(cloudX2 < 0-(cloudSprite->w))
    {
        cloudX2 = 500;
        p2 = 0;
        cloudY2 = 50;
    }


}


void __fastcall TForm1::DrawScene()
{
    Image1 -> Canvas -> Draw(0,0,SceneBitMap);
}

int bgX = 0;
void __fastcall TForm1::UpdateScene()
{
    //draw bg
    //SceneBitMap ->Canvas -> Draw(0,0,bgBitMap);

    //move bg =)
    SceneBitMap -> Canvas -> Draw(bgX,0,bgBitMap);

    //draw cloud
    TempBitMap2 -> Canvas -> CopyRect(CloudTRect,
    							cloudSprite -> sprite_bmp -> Canvas,
                                cloudSprite -> ChangeSpriteAnimation(currentCloudShot));
    SceneBitMap -> Canvas -> Draw(cloudX, cloudY, TempBitMap2);

    //draw cloud2
    TempBitMap2 -> Canvas -> CopyRect(CloudTRect,
    							cloudSprite -> sprite_bmp -> Canvas,
                                cloudSprite -> ChangeSpriteAnimation(currentCloudShot2));
    SceneBitMap -> Canvas -> Draw(cloudX2, cloudY2, TempBitMap2);


    //draw dino
    TempBitMap -> Canvas -> CopyRect(ZeroTRect,
    							dinoSprite -> sprite_bmp -> Canvas,
                                dinoSprite -> ChangeSpriteAnimation(currentDinoShot));
    SceneBitMap -> Canvas -> Draw(margineX, margineY-dinoY, TempBitMap);

    //draw cactus
    SceneBitMap -> Canvas -> Draw(cactusX, margineY+45, cactusBitMap);



    //draw scnene on screen
    ////Image1 -> Canvas -> Draw(0,0,SceneBitMap);
    DrawScene();
}

void __fastcall TForm1::BgMove()
{
    bgX -= 2;
    if(bgX == -500)
        bgX = 0;
}




void __fastcall TForm1::Image1Click(TObject *Sender)
{
    /*if(JumpTimer -> Enabled == false)
    	DinoJump(); */
    if(dinoIsJumping == false)
    	DinoStartJump();
}
//---------------------------------------------------------------------------

int timeCounter = 0, fpsCounter = 0;
int leftCollider, rightCollider, topCollider;
void __fastcall TForm1::SceneTimerTimer(TObject *Sender)
{
    timeCounter++;
    if(timeCounter > 700)
        timeCounter = 0;
    fpsCounter++;
    //if(timeCounter % 2 == 0)
    //{

    //}


    if(!dinoIsDead)
    {
        CactusMove();
        BgMove();

        if(timeCounter % 4 == 0)
        {
           	CloudMove();
        }
        if(timeCounter % 10 == 0)
        {
            currentCloudShot++;
            currentCloudShot2++;
            if(currentCloudShot > 3)
                currentCloudShot = 0;
            if(currentCloudShot2 > 3)
                currentCloudShot2 = 0;
        }


    	if(!dinoIsJumping)
    	{
        	if(timeCounter % 5 == 0)
    		{
        		DinoRun();
    		}
    	}
    	else
    	{
        	DinoJump();
    	}

        //Collision detection:
        leftCollider = margineX - cactusBitMap -> Width;
        rightCollider = margineX + cactusSprite -> w + cactusBitMap -> Width;
        topCollider = margineY + 45 - cactusBitMap -> Height;
        if((cactusX < rightCollider)&&(cactusX > leftCollider)&&(margineY - dinoY > topCollider))
        {
        	currentDinoShot=8;
        	dinoIsDead = true;
            SceneTimer -> Enabled = false;
            Button1 -> Visible = true;
    	}
        UpdateScene();
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    //Restart
    dinoIsJumping = false;
    dinoY = 0;
    currentDinoShot=0;
    cactusX = 500;
    score = 0;
    dinoIsDead = false;
    Button1 -> Visible = false;
    ScoreLabel -> Caption = "Score: " + IntToStr(score);
    SceneTimer -> Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    autoJump = CheckBox1 -> Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::fpsTimerTimer(TObject *Sender)
{
    FpsLabel -> Caption = ("FPS: " + IntToStr(fpsCounter));
    fpsCounter = 0;
}
//---------------------------------------------------------------------------

