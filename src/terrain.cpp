#include "terrain.hpp"
#include "draw.h"
#include "image_io.h"

//Flat Terrain

FlatTerrain::FlatTerrain(const Point& pmin, const Point& pmax) : mesh_(GL_TRIANGLES) {
  //terrain mesh
  unsigned int a = mesh_.vertex(pmin.x, pmin.y, 0.f);
  unsigned int b = mesh_.vertex(pmax.x, pmin.y, 0.f);
  unsigned int c = mesh_.vertex(pmax.x, pmax.y, 0.f);
  unsigned int d = mesh_.vertex(pmin.x, pmax.y, 0.f);

  mesh_.triangle(a, b, c);
  mesh_.triangle(a, c, d);
}

void FlatTerrain::project(const Point& from, Point& to, Vector& n) const {
  to.z = 0;
  n = Vector(0.f, 0.f, 1.f);
}

void FlatTerrain::draw(const Transform& v, const Transform& p) {
  ::draw(mesh_, Identity(), v, p);
}
