#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"


class AnimatedSprite
{
    public:
        __fastcall AnimatedSprite();
        __fastcall AnimatedSprite(Graphics::TBitmap *_sprite, int _k);
        virtual ~AnimatedSprite();
        Graphics::TBitmap __fastcall GetSpriteFromSpriteSheet(int number);
        Graphics::TBitmap __fastcall GetShotBitmap(int number);
        TRect __fastcall ChangeSpriteAnimation(int number);
        void __fastcall MoveAndChangeSprite(int new_x, int new_y, int number);
        int k, w, h;
        TRect TRect_sprite;
        Graphics::TBitmap *sprite_bmp = new Graphics::TBitmap(),*temp_bmp = new Graphics::TBitmap();
    protected:

    private:
        //static TRect zeroTRect;




};

#endif // ANIMATEDSPRITE_H
