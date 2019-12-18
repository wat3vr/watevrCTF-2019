import numpy as np
import scipy as sp
import os
import shutil
from scipy import signal, sparse
from scipy.sparse import linalg
from PIL import Image

SHOW_DEBUG = False

if SHOW_DEBUG:
    import matplotlib.pyplot as plt

im = Image.open("original.png")
im_ar = np.array(im).reshape(im.height, im.width, -1) / 256

print("Loaded original")
if SHOW_DEBUG:
    plt.imshow(im_ar, vmin=0, vmax=1)
    plt.show()

# Remove alpha
im_ar = im_ar[:,:,:3]
print("Image shape:", im_ar.shape)

FIL_RAD = 7

fil_im = Image.open("filter.png")
fil = np.array(fil_im).reshape(fil_im.height, fil_im.width, -1)[:,:,0] / 256

if fil.shape[0] != fil.shape[1] or fil.shape[0] != FIL_RAD * 2 + 1:
    print("Wrong filter shape! Wanted", (FIL_RAD * 2 + 1, FIL_RAD * 2 + 1), "got", fil.shape)
    exit()

fil /= fil.sum()

print("Loaded filter")
if SHOW_DEBUG:
    plt.imshow(fil)
    plt.show()

# Convolve filter
out = np.zeros((im_ar.shape[0], im_ar.shape[1], 3))

for c in range(3):
    out[:,:,c] = signal.convolve2d(im_ar[:,:,c], fil, boundary="wrap", mode="same")

# Quantize to 256 colors
out = np.floor(out * 256) / 256

print("Applied filter")
if SHOW_DEBUG:
    plt.imshow(out, vmin=0, vmax=1)
    plt.show()

# Save

if not os.path.isdir("downloads"):
    os.mkdir("downloads")

out_im = Image.fromarray(np.array(out * 256, dtype="uint8"))
out_im.save("downloads/blurry.png")
shutil.copy("logo.png", "downloads/logo.png")
print("Done")
