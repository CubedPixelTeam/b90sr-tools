#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

class ACrystal{
    public:
    s32 x,y,sx,sy;
    u8 alive,id,cbg;
    void Create(u8 id, u8 pal, s32 x, s32 y);
    void ReActivate();
    bool vbl(s32 PlayerX,s32 PlayerY);
};
class ACannon{
    public:
    float x;
    s32 y,sx,sy;
    s32 startingx, startingy;
    bool alive,hflip;
    u8 id,sc,cb;
    void Create(u8 id, u8 pal, s32 x,s32 y, u8 sc, u8 cb);
    void CreateGFX2(u8 id, u8 pal, s32 x,s32 y, u8 sc, u8 cb);
    void ReActivate();
    bool vbl(s32 PlayerX,s32 PlayerY);
};
class ASpring{
    public:
    bool collision(s32 x,s32 y, s32 pointx, s32 pointy, s8 xp);
};

class abossfdz{
    public:
    bool collision(u8 id,s32 playerx,s32 playery);
};
#endif