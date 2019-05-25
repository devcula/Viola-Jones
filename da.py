from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import csv

#Generating Comma Separated Value file for test images

name=0
countface=471
new_path= "/home/devcula/Downloads/Face_files/test/"

with open(new_path+"test.csv", 'w') as csvFile:
  writer = csv.writer(csvFile, delimiter=',', quotechar='"')
  writer.writerow(["filename", "label"])
  for i in range(24045):
    if i <= countface:
        writer.writerow([str(i) + ".pgm", 1])
    else:
        writer.writerow([str(i) + ".pgm", 0])