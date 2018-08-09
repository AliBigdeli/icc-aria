#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
#cropping image and makeing a square from point x1,y1 to x2,y2
#image[x1:x2,y1:y2]
crop = image[1:200,1:200]
#showing original image
cv2.imshow("image ",image )
#showing the cropped image
cv2.imshow("image2 ",crop )
#waiting for a key stroke to exit
cv2.waitKey(0)
cv2.destroyAllWindows()
