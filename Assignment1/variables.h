#define M_PI 3.1415926535897932
#define LEFT  90
#define RIGHT -90
#define SHOWCIRCLE 32

#define RESETBKG 48
#define GREENBKG 49
#define BLUEBKG 50
#define PURPLEBKG 51

#define REDSPIDER 52
#define GREENSPIDER 53
#define BLUESPIDER 54
#define RESET 57
#define MODE 109

#define MOVELEFT 97
#define MOVERIGHT 115
#define FORWARD 119
#define BACKWARDS 122

float radius = 10;
bool easy = true;
int windowSize = 1200;
int worldSize = 400;
float bodyRadius = radius;
float lwr_arm_len = radius;
float upr_arm_len = radius * 1.5;
int arm_width = 3;
bool boundingCircleIsVisible = true;

float black[] = { 0.0, 0.0, 0.0 };
float colors[] = { 0.0, 0.0, 0.0 };
float red[] = { 1.0, 0.0, 0.0 };
float green[] = { 0.0, 0.0, 1.0 };
float blue[] = { 0.0, 1.0, 0.0 };

struct spider
{
	double x;
	double y;
	double heading;
	float colour[3];
	float speed;
	float size;
};