import cv2
from PIL import Image

img_cv = cv2.imread("../map10/gt/0602.png")
img_pil = Image.open("../map10/gt/0602.png")
img_pil = img_pil.convert("RGB")

cv_shape = img_cv.shape
cv_size = img_cv.size

pil_size = img_pil.size

