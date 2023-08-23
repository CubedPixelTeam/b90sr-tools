#include <PA9.h>
#include "objects.h"
#include "all_gfx.h"
#include "../common.h"

void ACrystal::Create(u8 id, u8 pal, s32 x, s32 y){
    this->x = x;
    this->y = y;
    this->id = id;
    this->cbg = cbg;
    PA_CreateSprite(1,id,(void*)crystal_Sprite,OBJ_SIZE_16X16,0,pal,x,y);
    PA_StartSpriteAnim(1,this->id,0,3,4);
    this->alive = true;
}
void ACrystal::ReActivate(){
    this->alive = true;
}
bool ACrystal::vbl(s32 PlayerX, s32 PlayerY){
   this->sx = this->x - PA_BgInfo[0][2].ScrollX;
   this->sy = this->y - PA_BgInfo[0][2].ScrollY;
   if((this->sx < -16 || this->sx > 272 )||
   (this->sy < -16 || this->sy > 208)||
   this->alive == false) {
    this->sx = 256;
   }
   else if((this->x < PlayerX+22 && this->x > PlayerX-8 )&&
   (this->y < PlayerY + 31 && this->y > PlayerY - 16)&&
   this->alive == true) {
        this->alive = false;
        this->sx = 256;
        mmEffect(SFX_CRYS);
        return 1;
   }
   PA_SetSpriteXY(1,this->id,this->sx,this->sy);
    return 0;
}
bool ASpring::collision(s32 x,s32 y, s32 pointx, s32 pointy, s8 xp){
    if(x> pointx - 16 && x < pointx + xp &&
    y < pointy + 16 && y > pointy - 3)return 1;
    return 0;
}

void ACannon::Create(u8 id, u8 pal, s32 x,s32 y, u8 sc, u8 cb){
    this->id = id;
    this->x = x;
    this->y = y;
    this->startingx = x;
    this->startingy = y;
    this->sc = sc;
    this->cb = cb;
    this->alive = true;
    PA_CreateSprite(1,id,(void*)cannon_Sprite,OBJ_SIZE_16X16,0,pal,x,y);
}
void ACannon::ReActivate(){
    this->alive = true;
    this->x = this->startingx;
    this->y = this->startingy;
}
bool ACannon::vbl(s32 PlayerX,s32 PlayerY){
    if(this->hflip == true) this->x += 0.6;
    else this->x -= 0.6;
    PA_SetSpriteHflip(1,this->id,this->hflip);
   this->sx = this->x - PA_BgInfo[0][2].ScrollX;
   this->sy = this->y - PA_BgInfo[0][2].ScrollY;
    if(PA_EasyBgGetPixel(0,2,this->sx + 16, this->sy) != 0||
    PA_EasyBgGetPixel(0,2,this->sx, this->sy) !=0||
    PA_EasyBgGetPixel(0,2,this->sx + 14, this->sy + 16) == 0||
    PA_EasyBgGetPixel(0,2,this->sx - 2, this->sy + 16) == 0) this->hflip = !this->hflip;
        
   if((this->sx < -16 || this->sx > 272 )||
   (this->sy < -16 || this->sy > 208)) {
   PA_SetSpriteX(1,this->id,256);
   }
   else if((this->x < PlayerX+8 && this->x > PlayerX-8 )&&
   (this->y < PlayerY + 16 && this->y > PlayerY - 16)) {
        return 1;
   }
   else PA_SetSpriteXY(1,this->id,this->sx,this->sy);
   return 0;
}
void ACannon::CreateGFX2(u8 id, u8 pal, s32 x,s32 y, u8 sc, u8 cb){
    this->id = id;
    this->x = x;
    this->y = y;
    this->sc = sc;
    this->cb = cb;
    this->alive = true;
    PA_CreateSprite(1,id,(void*)xed_Sprite,OBJ_SIZE_16X16,1,pal,x,y);
}

bool abossfdz::collision(u8 id,s32 PlayerX,s32 PlayerY){
   if(PA_GetSpriteX(1,id) < PlayerX+18 && PA_GetSpriteX(1,id) > PlayerX-18&&
   PA_GetSpriteY(1,id) < PlayerY + 28 && PA_GetSpriteY(1,id) > PlayerY - 28) {
        return 1;
   }
   return 0;
}
