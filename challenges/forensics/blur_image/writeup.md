# Blurred Image

We can from the description guess that the blurred image is the result of applying an arbitrary convolution
to the original. We can also make out the word `watevr{` in the blurred image, which means that we need to
invert the convolution to get the flag.

If we also guess that the background of the image was originally pure white, which the spots in the lower
left seem to suggest, we can from the logo see that the convolution has a size length of at most 15.

As the text is black, we will only look at one of the color channels, as it gives enough information to read
the flag.

If we let each value in the filter be a variable, we can use the fact that we are given the image of the
logo in the lower right, and create a system of equations, where each equation is given by the resulting
pixel after applying the convolution. If we choose those pixels as the ones in the blurry logo, we know the
original pixel values. These give enough information to give us the flter. This filter can be seen in the
file `filter.png`.

![filter](filter.png)

Once we know the filter, we can create a new, big system of equations to solve for the original image. The
variables are each pixel in the original image, and each pixel in the blurry image give us one equation.
Solving this equation system takes about 10 minutes on my laptop. Once we solwe the system of equations, we
can simply read the flag.


