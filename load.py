import os
import numpy as np
import pandas as pd
from scipy.misc import imread
from sklearn.metrics import accuracy_score
import tensorflow as tf
from matplotlib import pyplot as pylab

root_dir = os.path.abspath('../../PycharmProjects/Violajones')
data_dir = os.path.join(root_dir, 'data')

seed = 500
rng = np.random.RandomState(seed)
test = pd.read_csv(os.path.join(data_dir, 'Test.csv'))

sess = tf.Session()
new_saver = tf.train.import_meta_graph('mymodel.meta')
new_saver.restore(sess, tf.train.latest_checkpoint('./'))
all_vars = tf.get_collection('vars')
for v in all_vars:
    v_ = sess.run(v)
    print(v_)
    pred_temp = tf.equal(tf.argmax(output_layer, 1), tf.argmax(y, 1))
    accuracy = tf.reduce_mean(tf.cast(pred_temp, "float"))
    print("Validation Accuracy:", accuracy.eval({x: val_x.reshape(-1, input_num_units), y: dense_to_one_hot(val_y)}))
    predict = tf.argmax(output_layer, 1)
    pred = predict.eval({x: test_x.reshape(-1, input_num_units)})
    # Testing
img_name = rng.choice(test.filename)
filepath = os.path.join(data_dir, 'Train', 'Images', 'test','test-images', img_name)
img = imread(filepath, flatten=True)
test_index = int(img_name.split('.')[0])
print("Prediction is: ", pred[test_index])
pylab.imshow(img, cmap='gray')
pylab.axis('off')
pylab.show()