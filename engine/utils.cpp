#include <PA9.h>

/*
B90sr Utils PAlib Wrappers Output Box Text.
S is for screen
*/
void B90SR_PW_OutputBoxText(u8 s, u16 x, u16 y, u8 wfv, const char* text){
	u16 nletters = 0; 
	u16 letter = 0; 
	u8 i = 0;
	
    while (letter == nletters){
	++nletters;
	letter = PA_BoxText(s,x,y,29,15,text, nletters);
	if(!Pad.Held.A) for(i = 0; i < wfv; i ++) PA_WaitForVBL(); 
	else for(i = 0; i < wfv/4; i ++) PA_WaitForVBL(); 
	PA_WaitForVBL();
	}
    return;
}