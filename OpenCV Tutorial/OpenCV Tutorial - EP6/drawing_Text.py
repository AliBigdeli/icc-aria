#adding opencv and numpy library to code
import cv2
import numpy as np
#reading the input image
image = cv2.imread('Sample.jpg')
#drawing a text
#function to draw a text
cv2.putText(image, "www.icc-aria.ir", (90, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2)
#showing the output image
cv2.imshow("image", image)
#waiting for a key stroke and closing all windows
cv2.waitKey(0)
cv2.destroyAllWindows()
