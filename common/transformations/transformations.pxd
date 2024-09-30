# cython: language_level=3
from libcpp cimport bool

cdef extern from "orientation.cc":
  pass

cdef extern from "orientation.hpp":
  cdef cppclass Quaternion "Eigen::Quaterniond":
    Quaternion()
    Quaternion(double, double, double, double)
    double w()
    double x()
    double y()
    double z()

  cdef cppclass Vector3 "Eigen::Vector3d":
    Vector3()
    Vector3(double, double, double)
    double operator()(int)

  cdef cppclass Matrix3 "Eigen::Matrix3d":
    Matrix3()
    Matrix3(double*)

    double operator()(int, int)

<<<<<<< HEAD
  Quaternion euler2quat(Vector3)
  Vector3 quat2euler(Quaternion)
  Matrix3 quat2rot(Quaternion)
  Quaternion rot2quat(Matrix3)
  Vector3 rot2euler(Matrix3)
  Matrix3 euler2rot(Vector3)
  Matrix3 rot_matrix(double, double, double)
  Vector3 ecef_euler_from_ned(ECEF, Vector3)
  Vector3 ned_euler_from_ecef(ECEF, Vector3)
=======
  Quaternion euler2quat(const Vector3 &)
  Vector3 quat2euler(const Quaternion &)
  Matrix3 quat2rot(const Quaternion &)
  Quaternion rot2quat(const Matrix3 &)
  Vector3 rot2euler(const Matrix3 &)
  Matrix3 euler2rot(const Vector3 &)
  Matrix3 rot_matrix(double, double, double)
  Vector3 ecef_euler_from_ned(const ECEF &, const Vector3 &)
  Vector3 ned_euler_from_ecef(const ECEF &, const Vector3 &)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e


cdef extern from "coordinates.cc":
  cdef struct ECEF:
    double x
    double y
    double z

  cdef struct NED:
    double n
    double e
    double d

  cdef struct Geodetic:
    double lat
    double lon
    double alt
    bool radians

<<<<<<< HEAD
  ECEF geodetic2ecef(Geodetic)
  Geodetic ecef2geodetic(ECEF)
=======
  ECEF geodetic2ecef(const Geodetic &)
  Geodetic ecef2geodetic(const ECEF &)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

  cdef cppclass LocalCoord_c "LocalCoord":
    Matrix3 ned2ecef_matrix
    Matrix3 ecef2ned_matrix

<<<<<<< HEAD
    LocalCoord_c(Geodetic, ECEF)
    LocalCoord_c(Geodetic)
    LocalCoord_c(ECEF)

    NED ecef2ned(ECEF)
    ECEF ned2ecef(NED)
    NED geodetic2ned(Geodetic)
    Geodetic ned2geodetic(NED)
=======
    LocalCoord_c(const Geodetic &, const ECEF &)
    LocalCoord_c(const Geodetic &)
    LocalCoord_c(const ECEF &)

    NED ecef2ned(const ECEF &)
    ECEF ned2ecef(const NED &)
    NED geodetic2ned(const Geodetic &)
    Geodetic ned2geodetic(const NED &)
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

cdef extern from "coordinates.hpp":
  pass
