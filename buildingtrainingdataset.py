from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from scipy.misc import imread
import os
from scipy.misc import imsave


name=0
countface=0
countnonface=0
old_path= "/home/devcula/Downloads/Face_files/test/face"
new_path= "/home/devcula/Downloads/Face_files/test/new"

for n in os.listdir(old_path):
    image_path=os.path.join(old_path,n)
    img=imread(image_path)
    imsave(new_path+"/"+str(name)+".pgm",img)
    name+=1
    countface+=1

old_path="/home/devcula/Downloads/Face_files/test/non-face"
for n in os.listdir(old_path):
    image_path=os.path.join(old_path,n)
    img=imread(image_path)
    imsave(new_path+"/"+str(name)+".pgm",img)
    name+=1
    countnonface+=1

print(countface)
print(countnonface)