#ifndef RAYTRACING
#define RAYTRACING

#include <glut_.h>
#include <stdio.h>
#include <vector>
#include <math.h>

const int WINDOW_WIDTH = 500, WINDOW_HEIGHT = 500, inf = 999999;

class sphere
{
public:
	std::vector<int> center;
	std::vector<int> color;
	int radius;
	sphere(std::vector<int> _center, int _radius, std::vector<int> _color) : center(_center), radius(_radius), color(_color) { }
	sphere() : center({ 0, 0, 0 }), radius(0), color({ 0, 0, 0 }) { }
};

class scene
{
public:
	sphere * spheres;
	int number_of_spheres = 3;
	scene() { spheres = new sphere[number_of_spheres]; }
	~scene() { delete[] spheres; }
};

class raytracing
{
	// O camera
	// C anvas, Cx Cy - pixels
	// V iewport, Vx Vy - points of the viewport
	// S creen, Sx Sy - points of the screen
	std::vector<int> O;
	int Cx, Cy,
		d,
		Vx, Vy,
		Cw, Ch,
		Sx, Sy,
		Vw, Vh, Vz;
	scene scn;
	std::vector<int> trace_ray(std::vector<int> O, std::vector<int> D, int t_min, int t_max);
	std::vector<int> intersect_ray_sphere(std::vector<int> O, std::vector<int> D, sphere sph);
	int dot(std::vector<int> a, std::vector<int> b);
	std::vector<int> canvas_to_viewport(int x, int y);
public:
	raytracing();
	void draw();
};

#endif