#pragma once

#include <eigen3/Eigen/Dense>

#define DEG2RAD(x) ((x) * M_PI / 180.0)
#define RAD2DEG(x) ((x) * 180.0 / M_PI)

struct ECEF {
  double x, y, z;
<<<<<<< HEAD
  Eigen::Vector3d to_vector(){
=======
  Eigen::Vector3d to_vector() const {
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    return Eigen::Vector3d(x, y, z);
  }
};

struct NED {
  double n, e, d;
<<<<<<< HEAD
  Eigen::Vector3d to_vector(){
=======
  Eigen::Vector3d to_vector() const {
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
    return Eigen::Vector3d(n, e, d);
  }
};

struct Geodetic {
  double lat, lon, alt;
  bool radians=false;
};

<<<<<<< HEAD
ECEF geodetic2ecef(Geodetic g);
Geodetic ecef2geodetic(ECEF e);
=======
ECEF geodetic2ecef(const Geodetic &g);
Geodetic ecef2geodetic(const ECEF &e);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

class LocalCoord {
public:
  Eigen::Matrix3d ned2ecef_matrix;
  Eigen::Matrix3d ecef2ned_matrix;
  Eigen::Vector3d init_ecef;
<<<<<<< HEAD
  LocalCoord(Geodetic g, ECEF e);
  LocalCoord(Geodetic g) : LocalCoord(g, ::geodetic2ecef(g)) {}
  LocalCoord(ECEF e) : LocalCoord(::ecef2geodetic(e), e) {}

  NED ecef2ned(ECEF e);
  ECEF ned2ecef(NED n);
  NED geodetic2ned(Geodetic g);
  Geodetic ned2geodetic(NED n);
=======
  LocalCoord(const Geodetic &g, const ECEF &e);
  LocalCoord(const Geodetic &g) : LocalCoord(g, ::geodetic2ecef(g)) {}
  LocalCoord(const ECEF &e) : LocalCoord(::ecef2geodetic(e), e) {}

  NED ecef2ned(const ECEF &e);
  ECEF ned2ecef(const NED &n);
  NED geodetic2ned(const Geodetic &g);
  Geodetic ned2geodetic(const NED &n);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
};
