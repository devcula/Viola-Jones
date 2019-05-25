import PIL
import numpy as np
from PIL import Image
from resizeimage import resizeimage
from sklearn import preprocessing
import features
#import integral
from numpy import array


#Resizing Image
#with open('face00001.pgm', 'r+b') as f:
#    with Image.open(f) as image:
#        cover = resizeimage.resize_cover(image, [19, 19])
#        cover.save('face00001_new.pgm', image.format)

#Converting to Grayscale
img=PIL.Image.open("face00001.pgm").convert("L")
#Generating numpy arrayFaceNeuralNetwork
arr=np.array(img)
#Preprocessing
arr_scaled=preprocessing.scale(arr)
#Calculating and storing Haar features
features.calc_features(arr_scaled)
#Calculating Integral image
#integral.calc_integral(arr)

#opening features stored in text file and creating array of features
f = open("features.txt","r")
rs = [line.split('     ') for line in f.readlines()]
print(rs[0])
rs = array(rs)
rs = np.delete(rs,-1,1)
print(rs.shape)
#print(arr[185][185])
#numpyarray.display(arr)
#a=numpyarray.ret(arr)
#print(a)

