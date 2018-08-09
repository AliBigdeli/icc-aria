#importing the module needed
import cv2
# reading the image with imread("image directory")
image = cv2.imread("Sample.jpg")
# Getting the dimesnions of the image
dim = image.shape
rotationAngle = -30
scaleFactor = 1
# Rotating the image by -30 degrees about the center
# dim[0] stores the no of rows and dim[1] no of columns
#Center: point about which rotation will occur
#rotationAngle: angle by which rotation is occurring
#Scale : an optional scaling factor
rotation = cv2.getRotationMatrix2D((dim[1]/2, dim[0]/2), rotationAngle, scaleFactor)
result = cv2.warpAffine(image, rotation, (dim[1],dim[0]))
#showing original image
cv2.imshow("image ",image )
#showing rotated image
cv2.imshow("image2 ",result )
#waiting for a key stroke to exit
cv2.waitKey(0)
cv2.destroyAllWindows()
