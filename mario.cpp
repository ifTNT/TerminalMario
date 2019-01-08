#include<iostream>
#include "Mario.h"
//#include "Monster.h"
using namespace std;


Mario::Mario(Game& api) :Point(api) {
	Mx = 0;
	My = 0;
	setContent("¡ð");
}

void Mario::update() {
	Lastx = Mx;
	Lasty = My;
	if (api.reachBottom(this) != true) {
		My = My - g;
	}
	switch (api.getUserKey())
	{
	case'w':
		for (double i = My;i <= My + v;i += 1) {
			if (api.moveTo(this, Mx, i) == false) break;
			My = i;
		}
		if (api.reachBottom(this) != true) {
			My = My - g;
		}
		break;
	case'a':
		Mx = Mx - 1;
		if (api.whosThere(this, Mx - 1, My) == &typeid(Monster)) {
			if (api.getLife() == 0) {
				api.endGame();
			}
			api.setLife(api.getLife() - 1);
			Mx = Mx - 2;
		}
		break;
	case'd':
		Mx = Mx + 1;
		if (api.whosThere(this, Mx + 1, My) == &typeid(Monster)) {
			if (api.getLife() == 0) {
				api.endGame();
			}
			api.setLife(api.getLife() - 1);
			Mx = Mx + 2;
		}
	}
	if (api.moveTo(this, (int)Mx, (int)My) == false) {
		api.moveTo(this, (int)Lastx, (int)Lasty);
		Mx = Lastx;
		My = Lasty;
	}
	else {
		api.moveTo(this, (int)Mx, (int)My);
	}
}