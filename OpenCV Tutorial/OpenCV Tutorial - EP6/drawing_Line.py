#adding opencv and numpy library to code
import cv2
import numpy as np
#reading the input image
image = cv2.imread('Sample.jpg')
#drawing a line
#function to draw a line
cv2.line(image, (20, 140), (380, 200), (0, 255, 0), thickness=4, lineType=cv2.LINE_AA)
#showing the output image
cv2.imshow("image", image)
#waiting for a key stroke and closing all windows
cv2.waitKey(0)
cv2.destroyAllWindows()
