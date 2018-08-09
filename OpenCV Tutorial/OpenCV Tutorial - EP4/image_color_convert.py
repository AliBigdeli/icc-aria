#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
#chaning image to gray scale image
grayscale = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#for showing the image in a window use imshow("windows name",image)
cv2.imshow("image", image)
#showing the gray scale image in another window
cv2.imshow("grayscale", grayscale)
#waiting for a key stoke
cv2.waitKey(0)
