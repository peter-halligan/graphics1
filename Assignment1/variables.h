#define M_PI 3.1415926535897932
#define LEFT  90;
#define RIGHT -90;
float radius = 10;
bool easy = true;
int windowSize = 1200;
int worldSize = 400;
float bodyRadius = radius;
float lwr_arm_len = radius;
float upr_arm_len = radius * 1.5;
int arm_width = 3;
bool boundingCircleIsVisisble = true;

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
	double colour[3];
};