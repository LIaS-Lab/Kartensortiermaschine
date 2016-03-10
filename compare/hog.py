import cv2
import time
import numpy
from sys import argv

# Generate a HOG value array that describes the features inside an image
def compute_hog(image_path):
	hog = cv2.HOGDescriptor()
	large = cv2.imread(image_path)
	
	# Scale the image to 200x128 pixels so computation is faster
	image = cv2.resize(large, (200, 128))
	
	return hog.compute(image)

# Calculate the cumulative error between two arrays
def cumulative_error(h1, h2):
	c = 0
	
	for i in range(len(h1)):
		# Sum of differences
		diff = abs(h1[i] - h2[i])
		c += diff
	
	return c

# Calculate the HOG values of the two images specified as command line arguments
h1 = compute_hog(argv[1])
h2 = compute_hog(argv[2])

# Print the cumulative error
print('Cumulative error:', cumulative_error(h1, h2))