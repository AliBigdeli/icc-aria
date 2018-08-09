#adding opencv and numpy library to code
import cv2
import numpy as np
#reading the input image
image = cv2.imread('Sample.jpg')
#drawing a rectangle
#function to draw a rectangle
cv2.rectangle(image, (20, 20), (300, 300), (255, 255, 0), thickness=2, lineType=cv2.LINE_8)
#showing the output image
cv2.imshow("image", image)
#waiting for a key stroke and closing all windows
cv2.waitKey(0)
cv2.destroyAllWindows()
