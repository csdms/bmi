import numpy as np
from scipy import ndimage, random


def solve_2d(z, spacing, out=None):
    dy, dx = spacing
    denom = 2. * (dx ** 2 + dy ** 2)
    stencil = np.array([[0., dy ** 2, 0.],
                        [dx ** 2, 0., dx ** 2],
                        [0., dy ** 2, 0.]]) / denom

    return ndimage.convolve(z, stencil, output=out)


class Poisson(object):
    """Solve the Poisson equation on a grid.

    Examples
    --------
    >>> poisson = Poisson()
    >>> poisson.time
    0.0
    >>> poisson.advance_in_time()
    >>> poisson.time
    1.0

    >>> poisson = Poisson(shape=(5, 5))
    >>> poisson.z = np.zeros((3, 3), dtype=float)
    >>> poisson.z[2, 2] = 1.
    >>> poisson.advance_in_time()
    >>> poisson.z
    """
    def __init__(self, shape=(10, 20), spacing=(1., 1.), origin=(0., 0.),
                dt=1., end_time=10.):
        self._shape = shape
        self._spacing = spacing
        self._origin = origin
        self._dt = dt
        self._time = 0.

        self._z = random.random(self._shape)
        self._z_temp = np.empty_like(self._z)

    @property
    def time(self):
        return self._time

    @property
    def z(self):
        return self._z

    @z.setter
    def z(self, new_z):
        self._z[:] = new_z

    @classmethod
    def from_file(clazz, filename):
        with open(filename, 'r') as fp:
            config = yaml.load(fp)
        return clazz(**config)

    def advance_in_time(self):
        solve_2d(self._z, self._spacing, out=self._z_temp)
        self._z[:] = self._z_temp
        self._z[:, (0, -1)] = 0.
        self._z[(0, -1), :] = 0.
        self._time += self._dt
