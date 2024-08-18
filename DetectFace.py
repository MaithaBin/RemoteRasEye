import cv2

# MJPEG stream URL
stream_url = "http://127.0.0.0:8080/?action=stream"

# Loads the Haar cascade file for face detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Opens the video stream
cap = cv2.VideoCapture(stream_url)

# Checks if the stream is opened successfully
if not cap.isOpened():
    print("Cannot open the video stream.")
    exit(-1)

while True:
    # Reads a frame from the stream
    ret, frame = cap.read()
    
    # Continues to the next iteration if frame is not read properly 
    if not ret:
        continue

    # Converts the frame to grayscale for face detection
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detects faces in the frame
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=5, minSize=(100, 100))

    # Draws rectangles around detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # Displays the frame with detected faces
    cv2.imshow("MJPG Stream with Face Detection", frame)

    # Exits if the ESC key is pressed
    if cv2.waitKey(1) == 27:
        break

# Releases the video capture and close all OpenCV windows
cap.release()
cv2.destroyAllWindows()
