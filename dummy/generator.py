import numpy as np
import cv2

# Define dimensions for a perfect square image
size = 256  # 256x256 pixels

# Generate completely random RGB pixel data (values from 0 to 255)
random_pixel_data = np.random.randint(0, 256, (size, size, 3), dtype=np.uint8)

# Save the matrix directly as a standard square .bmp file
cv2.imwrite('random_square.bmp', random_pixel_data)

print(f"Success! Generated a random square BMP image ({size}x{size} pixels).")
