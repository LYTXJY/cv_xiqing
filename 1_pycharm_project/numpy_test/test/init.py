# -*- coding: utf-8 -*-
# Author : calmcar_XJY
# Date : 2020/11/26 下午2:22
# Function:

'''

'''

import cv2
import numpy as np

im = cv2.imread("./000000512537.jpg")
central_crop = 0.875
resize_strategy = "tf"

cv2.imshow("im", im)
print("im.shape； ", im.shape)

try:
    im_dim = im.shape[2]
except IndexError:
    im_dim = 1

if im_dim == 3:
    rgb = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
elif im_dim == 4:
    rgb = cv2.cvtColor(im, cv2.COLOR_BGRA2RGB)
else:
    rgb = cv2.cvtColor(im, cv2.COLOR_GRAY2RGB)


#1 .cnetral crop
h, w = im.shape[0], im.shape[1]

h_cropped = int(h * central_crop)
w_cropped = int(w * central_crop)

h_start = (h-h_cropped) // 2
h_end = h_cropped + h_start

w_start = (w-w_cropped) // 2
w_end = w_cropped + w_start

image = rgb[h_start : h_end, w_start : w_end]

cv2.imshow("image", cv2.cvtColor(image, cv2.COLOR_RGB2BGR))
print("image.shape : ", image.shape)

#2. resize to target shape
(scaled_w, scaled_h) = (224, 224)

if resize_strategy == "tf":
    import tensorflow as tf
    image = np.expand_dims(image, 0)
    '''
    原始image         : 0 1 2    : h w c          : image.shape :  (437, 291, 3)
    np添加维度后 image : 0 1 2 3  : 新添维度 h w c  : np add dims :  (1, 437, 291, 3)
    '''
    print("np add dims : ", image.shape)

    tf_resized_image = tf.compat.v1.image.resize_bilinear(image,
                                                          (scaled_w, scaled_h))
    with tf.Session():
        resized_image = tf_resized_image.eval()


else:
    cv_resized_image = cv2.resize(image, (scaled_w, scaled_h), interpolation=cv2.INTER_AREA)
    resized_image = np.expand_dims(cv_resized_image, 0)





cv2.waitKey()
cv2.destroyAllWindows()