#adding opencv and numpy library to code
import cv2
import numpy as np
#reading the input image
image = cv2.imread('Sample.jpg')
#drawing a circle
#function to draw a circle
cv2.circle(image, (200, 200), 150, (0, 0, 0), thickness=5, lineType=cv2.LINE_AA)
#showing the output image
cv2.imshow("image", image)
#waiting for a key stroke and closing all windows
cv2.waitKey(0)
cv2.destroyAllWindows()
