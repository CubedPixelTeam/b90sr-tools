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
    s32 y,sx,sy,angle;
    s32 startingx, startingy;
    bool alive,hflip;
    u8 id,sc,cb;
    void Create(u8 id, u8 pal, s32 x,s32 y, u8 sc, u8 cb);
    void CreateGFX2(u8 id, u8 pal, s32 x,s32 y, u8 sc, u8 cb);
    void ReActivate();
    void CreateCustomGFX(u8 id, void* customgfx, u8 palid, s32 x,s32 y, u8 sc, u8 cb);
    bool vbl(s32 PlayerX,s32 PlayerY, bool kill);
    bool vblRot(s32 PlayerX,s32 PlayerY, bool kill, u8 rotscaleid);
};
class ASpring{
    public:
    bool collision(s32 x,s32 y, s32 pointx, s32 pointy, s8 xp);
};

class abossfdz{
    public:
    bool collision(u8 id,s32 playerx,s32 playery);
};
class ACierra{
    public:
    float x,y;
    u8 id,angle,rotid;
    bool flip;
    s32 startingx,startingy,endy,endx, sx,sy;
    void Create(u8 id, u8 pal, s32 startingposx,s32 startingposy, s32 endposy);
    u8 vbl(s32 PlayerX, s32 PlayerY);
    u8 vblnm(s32 PlayerX, s32 PlayerY);
    u8 vblMX(s32 PlayerX, s32 PlayerY);
    void CreateCustomX(u8 id, u8 pal, s32 startingposx,s32 startingposy, s32 endx, s32 endposy);
    void CreateCustomXb(u8 id, u8 pal, s32 startingposx,s32 startingposy, s32 endx, s32 endposy);
    void CreateB(u8 id, u8 pal, s32 startingposx,s32 startingposy, s32 endposy);
};
#endif