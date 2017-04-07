import PIL
import numpy
from PIL import Image
from resizeimage import resizeimage
from sklearn import preprocessing
import features
import integral

#Resizing Image
with open('4chad.png', 'r+b') as f:
    with Image.open(f) as image:
        cover = resizeimage.resize_cover(image, [24, 24])
        cover.save('4chad_new.png', image.format)

#Converting to Grayscale
img=PIL.Image.open("circle_new.png").convert("L")
#Generating numpy array
arr=numpy.array(img)
#Preprocessing
arr_scaled=preprocessing.scale(arr)
#Calculating and storing Haar features
#features.calc_features(arr_scaled)
#Calculating Integral image
integral.calc_integral(arr)


#print(arr[185][185])
#numpyarray.display(arr)
#a=numpyarray.ret(arr)
#print(a)

