"""
Visualize the nodes, edges, and faces of an unstructed grid.

This example is based on the matplotlib demo of a PathPatch object,
https://matplotlib.org/examples/shapes_and_collections/path_patch_demo.html.
"""
import matplotlib.patches as mpatches
import matplotlib.path as mpath
import matplotlib.pyplot as plt

# Pairs of grid points; the output from get_grid_x and get_grid_y
x = [0, 1, 2, 1, 3, 4]
y = [3, 1, 2, 4, 0, 3]

fig, ax = plt.subplots()

Path = mpath.Path
path_data = [
    (Path.MOVETO, (x[0], y[0])),
    (Path.LINETO, (x[1], y[1])),
    (Path.LINETO, (x[2], y[2])),
    (Path.LINETO, (x[3], y[3])),
    (Path.CLOSEPOLY, (x[0], y[0])),
    (Path.MOVETO, (x[1], y[1])),
    (Path.LINETO, (x[4], y[4])),
    (Path.LINETO, (x[5], y[5])),
    (Path.LINETO, (x[2], y[2])),
    (Path.CLOSEPOLY, (x[1], y[1])),
    (Path.MOVETO, (x[2], y[2])),
    (Path.LINETO, (x[5], y[5])),
    (Path.LINETO, (x[3], y[3])),
    (Path.CLOSEPOLY, (x[2], y[2])),
]
codes, verts = zip(*path_data)
path = Path(verts, codes)
patch = mpatches.PathPatch(path, facecolor="gray", alpha=0.25)
ax.add_patch(patch)

# plot control points and connecting lines
vx, vy = zip(*path.vertices)
(line,) = ax.plot(vx, vy, "go-")

plt.text(4.15, 1.8, "nodes", color="r", fontsize=12, va="center")
plt.text(4.15, 1.5, "edges", color="b", style="italic", fontsize=12, va="center")
plt.text(4.15, 1.2, "faces", weight="bold", fontsize=12, va="center")

# Nodes
for i in range(len(x) - 2):
    plt.text(x[i] - 0.2, y[i], str(i), color="r", fontsize=12)
plt.text(x[4] + 0.1, y[4], "4", color="r", fontsize=12)
plt.text(x[5], y[5] + 0.1, "5", color="r", fontsize=12)

# Edges
plt.text(
    0.5 * (x[0] + x[1]) + 0.05,
    0.5 * (y[0] + y[1]),
    "0",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[1] + x[2]) - 0.15,
    0.5 * (y[1] + y[2]),
    "1",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[2] + x[3]) + 0.05,
    0.5 * (y[2] + y[3]),
    "2",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[3] + x[0]),
    0.5 * (y[3] + y[0]) - 0.15,
    "3",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[1] + x[4]),
    0.5 * (y[1] + y[4]) + 0.05,
    "4",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[4] + x[5]) - 0.15,
    0.5 * (y[4] + y[5]),
    "5",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[5] + x[2]),
    0.5 * (y[5] + y[2]) - 0.15,
    "6",
    color="b",
    style="italic",
    fontsize=12,
)
plt.text(
    0.5 * (x[5] + x[3]),
    0.5 * (y[5] + y[3]) + 0.05,
    "7",
    color="b",
    style="italic",
    fontsize=12,
)

# Faces
plt.text(0.9, 2.5, "0", weight="bold", fontsize=12)
plt.text(2.5, 1.3, "1", weight="bold", fontsize=12)
plt.text(2.3, 2.9, "2", weight="bold", fontsize=12)

ax.grid(alpha=0.5)
ax.axis("equal")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_xticks(list(range(-1, 6)))
ax.set_yticks(list(range(-1, 6)))

show = False
if show is True:
    plt.show()
else:
    plt.savefig("mesh_unstructured.png", dpi=300)
    plt.close()
