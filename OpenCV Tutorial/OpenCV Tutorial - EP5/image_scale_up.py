#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
#for scaling down the image
scale=1.3
resize_img = cv2.resize(image, None, fx=scale, fy=scale, interpolation= cv2.INTER_LINEAR)
#showing the original image
cv2.imshow("image ",image )
#showing the resized image
cv2.imshow("image2 ",resize_img )
#waiting for a key stroke to exit
cv2.waitKey(0)
cv2.destroyAllWindows()
