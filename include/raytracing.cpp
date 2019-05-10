#include "raytracing.h"

raytracing::raytracing()
{
	O = { 0, 0, 0 };
	Cx = 0;
	Cy = 0;
	d = 1;
	Vx = 0;
	Vy = 0;
	Cw = WINDOW_WIDTH;
	Ch = WINDOW_HEIGHT;
	Sx = Cw / 2 + Cx;
	Sy = Ch / 2 + Cy;
	Vw = Cx * (Vx / Cw);
	Vh = Cy * (Vy / Ch), Vz = d;
	scn = scene();
}
void raytracing::draw()
{
	std::vector<int> D = { 0, 0, 0 };
	std::vector<int> color = { 0, 0, 0 };
	glBegin(GL_POINTS);
	/*
	for (int x = -Cw / 2; x < Cw / 2; x++)
	{
		for (int y = -Ch / 2; y < Ch / 2; y++)
		{
			D = this->canvas_to_viewport(x, y);
			color = trace_ray(O, D, 1, inf);
			glColor3f(color[0], color[1], color[2]);
			glVertex2i(x, y);
		}
	}
	*/
	glEnd();
}

std::vector<int> raytracing::trace_ray(std::vector<int> O, std::vector<int> D, int t_min, int t_max)
{
	/*
	int closest_t = inf;
	sphere closest_sphere;
	std::vector<int> t = { 0, 0 };
	for (int i = 0; i < scn.number_of_spheres; i++)
	{
		t = this->intersect_ray_sphere(O, D, scn.spheres[i]);
		if (t[0] > t_min && t[0] < t_max && t[0] < closest_t)
		{
			closest_t = t[0];
			closest_sphere = scn.spheres[i];
		}
	}
	if (closest_sphere.radius == 0)
	{
		return BACKGROUND_COLOR;
	}
	return closest_sphere.color;
	*/
	return{ 1, 1, 1 };
}

std::vector<int> raytracing::intersect_ray_sphere(std::vector<int> O, std::vector<int> D, sphere sph)
{
	/*
	std::vector<int> C = sph.center;
	int r = sph.radius;
	std::vector<int> OC = { O[0] - C[0], O[1] - C[1], O[2] - C[2] };
	std::vector<int> t = { 0, 0 };

	int k1 = dot(D, D);
	int k2 = 2 * dot(OC, D);
	int k3 = dot(OC, OC) - r * r;

	int discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		return{ inf, inf };
	}

	t[0] = (-k2 + std::sqrt(discriminant)) / (2 * k1);
	t[1] = (-k2 - std::sqrt(discriminant)) / (2 * k1);
	return t;
	*/
	return{ 0, 0 };
}

int raytracing::dot(std::vector<int> a, std::vector<int> b)
{
	int out = 0;
	for (int i = 0; i < a.size(); i++)
	{
		out = a[i] * b[i] + out;
	}
	return out;
}

std::vector<int> raytracing::canvas_to_viewport(int x, int y)
{
	return{ x * this->Vw / this->Cw, y * this->Vh / this->Ch, this->d };
}