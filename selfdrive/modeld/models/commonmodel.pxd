# distutils: language = c++

from msgq.visionipc.visionipc cimport cl_device_id, cl_context, cl_mem

cdef extern from "common/mat.h":
  cdef struct mat3:
    float v[9]

cdef extern from "common/clutil.h":
  cdef unsigned long CL_DEVICE_TYPE_DEFAULT
  cl_device_id cl_get_device_id(unsigned long)
  cl_context cl_create_context(cl_device_id)

cdef extern from "selfdrive/modeld/models/commonmodel.h":
<<<<<<< HEAD
  float sigmoid(float)

=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  cppclass ModelFrame:
    int buf_size
    ModelFrame(cl_device_id, cl_context)
    float * prepare(cl_mem, int, int, int, int, mat3, cl_mem*)
