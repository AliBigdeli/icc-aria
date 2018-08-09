#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
#using resize method for changing size
#cv2.resize( 'source' , (x,y))
resize_img = cv2.resize(image  , (200 , 250))
#showing the original image
cv2.imshow("image ",image )
#showing the resized image
cv2.imshow("image2 ",resize_img )
#waiting for a key stroke to exit
cv2.waitKey(0)
cv2.destroyAllWindows()
