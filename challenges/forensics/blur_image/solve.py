import numpy as np
import scipy as sp
from scipy import signal, sparse
from scipy.sparse import linalg
from PIL import Image
import matplotlib.pyplot as plt

im = Image.open("downloads/blurry.png")
im = np.array(im).reshape(im.height, im.width, -1) / 256

logo = Image.open("logo.png")
logo = np.array(logo).reshape(logo.height, logo.width, -1) / 256
print("Logo:", logo.shape)

plt.subplot(211)
plt.imshow(im)
plt.subplot(234)
plt.imshow(logo[:,:,0])
plt.subplot(235)
plt.imshow(logo[:,:,1])
plt.subplot(236)
plt.imshow(logo[:,:,2])
plt.show()

FIL_RAD = 7
FIL_WIDTH = FIL_RAD * 2 + 1
FIL_SIZE = FIL_WIDTH ** 2

print("Filter size is", FIL_SIZE, "points")

# Find filter given known part of image
logo_origin = im.shape[0] - logo.shape[0], im.shape[1] - logo.shape[1]
print("Logo origin:", logo_origin)

# x, y relative to logo_origin
def add_filter_equation_at(y, x, c):
    coeff = np.zeros((FIL_SIZE))
    res = im[y + logo_origin[0], x + logo_origin[1], c]

    for dy in range(-FIL_RAD, FIL_RAD+1):
        for dx in range(-FIL_RAD, FIL_RAD+1):
            i = (dy + FIL_RAD) * FIL_WIDTH + dx + FIL_RAD
            orig_val = logo[y - dy, x - dx, c]
            coeff[i] = orig_val

    return coeff, res

coeff_mat = np.zeros((0, FIL_SIZE))
ress = []

i = 0
while True:
    y = i % (logo.shape[0] - FIL_WIDTH - 1) + FIL_RAD
    x = i // (logo.shape[0] - FIL_WIDTH - 1) + FIL_RAD

    if x > logo.shape[1] - FIL_WIDTH  - 1:
        break

    for c in [0, 1, 2]:

        coeff, r = add_filter_equation_at(y, x, c)

        res_coeff_mat = np.concatenate((coeff_mat, coeff.reshape(1, -1)))
        coeff_mat = res_coeff_mat
        ress.append(r)

    i += 1

ress = np.array(ress)

print(coeff_mat.shape, ress.shape)
print("Rank", np.linalg.matrix_rank(coeff_mat))

fil = np.linalg.lstsq(coeff_mat, ress)[0]
fil = fil.reshape((FIL_WIDTH, FIL_WIDTH))
plt.imshow(fil)
plt.show()

def reverse_filter(im, fil):
    fil_rad = (fil.shape[0] - 1) // 2
    print("fil_rad=", fil_rad)

    # Given vector of original image, v, we want, based on fil, find a matrix F, such that
    # F*v = original

    h, w = im.shape

    result_mat = np.zeros((h * w, h * w))
    print("Filling with shape", result_mat.shape)

    print("Start")
    for y in range(h):
        for x in range(w):
            i = y * w + x
            for fy in range(-fil_rad, fil_rad+1):
                for fx in range(-fil_rad, fil_rad+1):
                    j = ((y + fy) % h) * w + (x + fx) % w

                    result_mat[i, j] = fil[-fy + fil_rad, -fx + fil_rad]
        print("\033[1A\033[KApplied row", y+1, "/", h)

    print("Solving...")
    solution = np.linalg.solve(result_mat, im.reshape(-1)).reshape(im.shape)
    return solution

r_solve = reverse_filter(im[:,:,0], fil).reshape(im.shape[0], im.shape[1], 1)
# g_solve = reverse_filter(im[:,:,1], fil).reshape(im.shape[0], im.shape[1], 1)
# b_solve = reverse_filter(im[:,:,2], fil).reshape(im.shape[0], im.shape[1], 1)
g_solve = b_solve = r_solve

solve = np.concatenate([r_solve, g_solve, b_solve], axis=2)
plt.subplot(121)
plt.imshow(solve)
plt.subplot(122)
plt.imshow(im)
plt.show()

solve = np.clip(solve, 0, 1)

# Save
out_im = Image.fromarray(np.array(solve * 255, dtype="uint8"))
out_im.save("result.png")
