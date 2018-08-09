#adding opencv and numpy library to code
import cv2
import numpy as np
#reading the input image
image = cv2.imread('Sample.jpg')
#drawing a ellipse
#function to draw a ellipse
cv2.ellipse(image, (190, 200), (100, 50), 45, 0, 360, (255, 0, 0), thickness=2, lineType=cv2.LINE_AA)
#showing the output image
cv2.imshow("image", image)
#waiting for a key stroke and closing all windows
cv2.waitKey(0)
cv2.destroyAllWindows()
