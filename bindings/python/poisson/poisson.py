import numpy as np
from scipy import ndimage


def solve_2d(z, spacing, out):
    dy, dx = spacing
    denom = 2. * (dx ** 2 + dy ** 2)
    stencil = np.array([[0., dy ** 2, 0.],
                        [dx ** 2, 0., dx ** 2],
                        [0., dy ** 2, 0.]]) / denom
    ndimage.convolve(z, stencil, output=out)


class Poisson(object):
    def __init__(self, shape=(10, 20), spacing=(1., 1.), origin=(0., 0.),
                dt=1., end_time=10.):
        self._shape = shape
        self._spacing = spacing
        self._origin = origin
        self._dt = dt
        self._time = 0.

        self._z = np.ones(self._shape, dtype=float)
        self._z_temp = np.ones(self._shape, dtype=float)

    @property
    def time(self):
        return self._time

    @property
    def z(self):
        return self._z

    @classmethod
    def from_file(clazz, filename):
        with open(filename, 'r') as fp:
            config = yaml.load(fp)
        return clazz(**config)

    def advance_in_time(self):
        solve_2d(self._z, self._spacing, self._z_temp)
        self._z[:] = self._z_temp
        self._time += self._dt
