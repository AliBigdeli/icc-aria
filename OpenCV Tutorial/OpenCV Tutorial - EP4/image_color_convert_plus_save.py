#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
#chaning image to gray scale image
grayscale = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#showing the grayscaled image
cv2.imshow("grayscale ",grayscale )
#writing and saving the image in same directory
cv2.imwrite("grayscale.jpg", grayscale)
#waiting for a key stroke
cv2.waitKey(0)
