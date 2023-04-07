import cv2
import numpy as np


def bilinear(x_: float, y_: float, img_: np.ndarray) -> np.ndarray:
    x1, y1 = int(x_), int(y_)
    x2, y2 = x1 + 1, y1 + 1
    y_y1 = y_ - y1
    y2_y = y2 - y_
    x_x1 = x_ - x1
    x2_x = x2 - x_
    f_x1_y = y2_y * img_[x1, y1]
    if y_y1 > 0:
        f_x1_y += y_y1 * img_[x1, y2]
    f_x2_y = y_y1 * img_[x2, y2] if y_y1 > 0 and x_x1 > 0 else 0
    if x_x1 > 0:
        f_x2_y += y2_y * img_[x2, y1]
    f_x_y = x_x1 * f_x2_y + x2_x * f_x1_y if x_x1 > 0 else x2_x * f_x1_y
    return f_x_y


def resize(img_, d_size):
    h, w = img_.shape[:2]
    d_h, d_w = d_size
    img_resize = np.zeros((d_h, d_w, 3), dtype=np.uint8)
    theta_x = (h - 1) / (d_h - 1)
    theta_y = (w - 1) / (d_w - 1)
    for i in range(d_h):
        x = theta_x * i
        for j in range(d_w):
            y = theta_y * j
            img_resize[i, j] = bilinear(x, y, img_)
    return img_resize


if __name__ == "__main__":
    img_origin = cv2.imread("../map10/X2/0602.png")  # (H, W, C)
    img_resize = resize(img_origin, (792, 696))
    cv2.imshow('image', img_origin)
    cv2.waitKey(0)
    cv2.imshow('image', img_resize)
    cv2.waitKey(0)
    cv2.imwrite('output.jpg', img_resize)
    cv2.destroyAllWindows()
