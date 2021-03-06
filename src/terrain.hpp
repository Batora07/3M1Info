#pragma once

#ifndef _MMACHINE_TERRAIN_HPP_
#define _MMACHINE_TERRAIN_HPP_

#include "vec.h"
#include "mat.h"
#include "mesh.h"
#include "image.h"
#include "orbiter.h"

class Terrain {
public:
  /**
   * Fonction de projection sur le terrain
   * @param from le point d'ou provient le vehicule
   * @param to le point ou souhaite se rendre le vehicule
   * @param n la normale du vehicule
   *
   * Cette fonction doit modifier le point to et la normale du vehicule, pour
   * fournir au programme appelant la position a laquelle le vehicule est
   * parvenu, et la normale du terrain a ce point.
   */
  virtual void project(const Point& from, Point& to, Vector& n) const = 0;

  /**
   * Fonction d'affichage du terrain
   * @param v la matrice view de la camera
   * @param p la matrice de projection de la camera
   */
  virtual void draw(const Transform& v, const Transform& p) = 0;
};


class FlatTerrain : public Terrain {
public:
  FlatTerrain(const Point& pmin, const Point& pmax);
  void project(const Point& from, Point& to, Vector& n) const;
  void draw(const Transform& v, const Transform& p);

private:
  Mesh mesh_;
};

#endif
