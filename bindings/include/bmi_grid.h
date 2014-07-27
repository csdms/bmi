/* -*- c-file-style: "stroustrup" -*- */

#ifndef BMI_GRID_API_H
#define BMI_GRID_API_H

#define BMI_GRID_API_VERSION_MAJOR 1
#define BMI_GRID_API_VERSION_MINOR 0



#if defined _WIN32
#define BMI_GRID_API __declspec(dllexport)
/* Calling convention, stdcall in windows, cdecl in the rest of the world */
#define CALLCONV __stdcall
#else
#define BMI_GRID_API
#define CALLCONV
#endif


#define BMI_SUCCESS (0)
#define BMI_FAILURE (1)

#include <stddef.h>
#include "bmi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  BMI_GRID_TYPE_UNKNOWN = 0,
  BMI_GRID_TYPE_UNIFORM,
  BMI_GRID_TYPE_RECTILINEAR,
  BMI_GRID_TYPE_STRUCTURED,
  BMI_GRID_TYPE_UNSTRUCTURED,
  BMI_GRID_TYPE_NUMBER
}
  BMI_Grid_type;



/* Grid information functions */
int get_grid_shape (const char *, int *);
int get_grid_spacing (const char *, double *);
int get_grid_origin (const char *, double *);

int get_grid_x (const char *, double *);
int get_grid_y (const char *, double *);
int get_grid_z (const char *, double *);

int get_grid_cell_count (const char *, int *);
int get_grid_point_count (const char *, int *);
int get_grid_vertex_count (const char *, int *);

int get_grid_connectivity (const char *, int *);
int get_grid_offset (const char *, int *);

#ifdef __cplusplus
}
#endif

#endif

