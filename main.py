import base64
import struct

# Define the base64-encoded data
base64_data = "NT1fT8KVO8OvaA=="

# Decode the base64 string into a bytes object
binary_data = base64.b64decode(base64_data)

# Unpack the binary data into battery, latitude, longitude, and altitude values
latitude = (struct.unpack('>i', bytes([0]) + binary_data[0:3])[0]) / 10000000
longitude = (struct.unpack('>i', bytes([0]) + binary_data[4:7])[0]) / 10000000

# Print the battery, latitude, longitude, and altitude
print("Latitude: ", latitude)
print("Longitude: ", longitude)
