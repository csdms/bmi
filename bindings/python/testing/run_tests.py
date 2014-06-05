#!/usr/bin/env python
"""
>>> import grid_info_test
>>> grid_info_test.run ()
Example Python Model
Variable name: height_above_sea_floor
Type: double
Units: meter
Rank: 1
Dimension: 10
Resolution: 1.0
Corner: (0.0)
Grid type: Uniform
<BLANKLINE>
Variable name: grid_longitude
Type: double
Units: arc_degrdd
Rank: 1
Dimension: 10
Resolution: 1.0
Corner: (0.0)
Grid type: Uniform
<BLANKLINE>
Variable name: height_above_sea_floor
Type: double
Units: meter
Rank: 1
Dimension: 10
Resolution: 1.0
Corner: (0.0)
Grid type: Uniform
<BLANKLINE>

>>> import get_value_test
>>> get_value_test.run ()
Example Python Model
Time 0: 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
Time 1: 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0
Time 2: 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0
Time 3: 6.0, 9.0, 12.0, 15.0, 18.0, 21.0, 24.0, 27.0, 30.0, 33.0
Time 4: 10.0, 14.0, 18.0, 22.0, 26.0, 30.0, 34.0, 38.0, 42.0, 46.0
Time 5: 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0
Time 6: 21.0, 27.0, 33.0, 39.0, 45.0, 51.0, 57.0, 63.0, 69.0, 75.0
Time 7: 28.0, 35.0, 42.0, 49.0, 56.0, 63.0, 70.0, 77.0, 84.0, 91.0
Time 8: 36.0, 44.0, 52.0, 60.0, 68.0, 76.0, 84.0, 92.0, 100.0, 108.0
Time 9: 45.0, 54.0, 63.0, 72.0, 81.0, 90.0, 99.0, 108.0, 117.0, 126.0
Time 9: 55.0, 65.0, 75.0, 85.0, 95.0, 105.0, 115.0, 125.0, 135.0, 145.0

>>> import irf_test
>>> irf_test.run ()
Initializing... Done.
Example Python Model
Running time step: 0... Done.
Running time step: 1... Done.
Running time step: 2... Done.
Running time step: 3... Done.
Running time step: 4... Done.
Running time step: 5... Done.
Running time step: 6... Done.
Running time step: 7... Done.
Running time step: 8... Done.
Running time step: 9... Done.
Finalizing... Done.

>>> import print_var_names_test
>>> print_var_names_test.run ()
Example Python Model
Input var names: height_above_sea_floor
Output var names: grid_longitude, height_above_sea_floor

>>> import set_value_test
>>> set_value_test.run ()
Example Python Model
0: 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
1: -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0
2: 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
3: 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
"""

import doctest
doctest.testmod ()


