//==============================================================================
#include "CApp.h"


//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	
    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

	if((Background = CSurface::OnLoad("./GFX/BG3.png")) == NULL){
		return false;
	}
	if((Background2 = CSurface::OnLoad("./GFX/BG4.png")) == NULL){
		return false;
	}

    if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
    	return false;
    }
	 
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if(Player.OnLoad("./GFX/Archer.png", 36, 52,0) == false) {
    	return false;
    }

    if(Player2.OnLoad("./GFX/Genzoh.png", 68, 36,3) == false) {
    	return false;
    }

	Player.X = 1000;
	Player.Y = 900;

    Player2.X = 200;
	Player2.Y = 1000;
	
    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&Player2);
	



	CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

    return true;
}

//==============================================================================
