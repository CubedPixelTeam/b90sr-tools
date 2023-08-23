#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
extern s32 player_bgx;
extern s32 player_bgy;
#include "../common.h"
class APlayer{
    public:
    s32 x,y,sx,sy;
    float g,vx;
    u8 id,speedcap,cbg,screenc;
    u8 trampoline,utrampoline,death,co,bp;
    bool hflip,idlekillswitch,triggerkillswitch,looser_grav,airdash_killswitch;
    u8 checkCollisionRight(s32 x, s32 y, s8 speed);
    u8 checkCollisionLeft(s32 x, s32 y, s8 speed);
    u8 checkCollisionBottom(s32 x, s32 y);
    void Create(u8 id, s32 x, s32 y,u8 c,u8 b,u8 t, u8 d, u8 ut);
    void hflipSprite(bool hflip);
    u8 Move();
    u8 Gravity();
    void Update();
    void UpdateBg();
};

#endif