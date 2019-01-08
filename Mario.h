#ifndef M_H
#define M_H

#include"Point.h"
using namespace std;

class Mario :public Point
{
public:
	Mario(Game&);
	virtual void update();
private:
	double Mx;
	double My;
	double Lastx;
	double Lasty;
	const double v = 4;
	const double g = 0.2;
};

#endif // !M_H