# -*- coding: utf-8 -*-
# Author : XJY
# Date : 2020/11/25 下午6:06
# Function:

'''

'''

import numpy as np
import os
import matplotlib.pyplot as plt




def parse_npy_data(data_name):
    print("*"*100)

    input_npy_data = np.load(data_name)
    one_ndim_npy_data = input_npy_data.flatten()
    size_len = input_npy_data.size
    print("one_ndim_npy_data.szie : {0}, \nnp.max(one_ndim_npy_data) : {1}, \nnp.min(one_ndim_npy_data) : {2}"
                                                .format(one_ndim_npy_data.size,
                                                np.max(one_ndim_npy_data),
                                                np.min(one_ndim_npy_data), ))

    print("*"*100)

    for i in range(0, size_len):
        plt.suptitle(data_name)
        if data_name == data_name_float:

            plt.scatter(i, one_ndim_npy_data[i], c= 'b')
        else:
            plt.scatter(i, one_ndim_npy_data[i], c= "r")


    new_pic_name = "../result_img/{}.png".format(data_name.split("/")[-1])
    plt.savefig(new_pic_name)
    plt.show()

def merge_float_uint8(data_name_float, data_name_uint8):
    input_npy_data_float = np.load(data_name_float)
    input_npy_data_uint8 = np.load(data_name_uint8)

    X = np.arange(0, input_npy_data_float.size)

    plt.subplot(2,1,1)
    plt.scatter(X, input_npy_data_float * 128,s=5, c= "b", marker="x", label = "float")
    plt.scatter(X, input_npy_data_uint8,s=5, c= "r", label = "uint8")
    plt.legend()
    plt.xlabel("data_size")
    plt.ylabel("fitting")

    plt.subplot(2, 1, 2)
    plt.scatter(X, input_npy_data_float, s=5, c="b", marker = "x", label = "float")
    plt.scatter(X, input_npy_data_uint8 / 128, s=5, c="r", label = "uint8")
    plt.legend()
    plt.xlabel("data_size")
    plt.ylabel("fitting")


    plt.savefig("../result_img/{}_{}_merge.png".format(data_name_float.split("/")[-1].split(".")[0]
                                                    ,data_name_uint8.split("/")[-1].split(".")[0]),
                figsize = (1920, 1080),
                dpi = 1080)
    plt.show()


def main():
    print("ok")
    parse_npy_data(data_name_float)
    parse_npy_data(data_name_uint8)
    merge_float_uint8(data_name_float, data_name_uint8)


if __name__ == "__main__":


    data_name_float = "../data/float.npy"
    data_name_uint8 = "../data/uint8.npy"

    main()
