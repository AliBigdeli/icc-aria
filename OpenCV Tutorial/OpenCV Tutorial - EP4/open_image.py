#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
#for showing the image in a window use imshow("windows name",image)
cv2.imshow("image", image)
#waiting for a key stoke to exit
cv2.waitKey(0)
cv2.destroyAllWindows()
