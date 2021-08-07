import numpy as np
import cv2
import serial

arduinodata = serial.Serial('COM3',19200)

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

cap = cv2.VideoCapture(0)
print(cap.get(3))  #read width
print(cap.get(4))  #read height


while 1:
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    
    
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        mx = (x+w)/2
        my = (y+h)/2
        if((mx<=235)&(mx>=210)):
            arduinodata.write(b'm')
        elif(mx>235)&(mx<=255):
            arduinodata.write(b'l')
        elif(mx<205)&(mx>=185):
            arduinodata.write(b'r')
        elif(mx>255)&(mx<=275):
            arduinodata.write(b'L')
        elif(mx<185)&(mx>=165):
            arduinodata.write(b'R')
        elif(mx<165):
            arduinodata.write(b't')
        elif(mx>275):
            arduinodata.write(b'k')
        else:
            arduinodata.write(b'n')
        if((my<=150)&(my>=130)):
            arduinodata.write(b'c')
        elif(my>150)&(my<=170):
            arduinodata.write(b'u')
        elif(my<130)&(my>=110):
            arduinodata.write(b'd')
        elif(my>170)&(my<=200):
            arduinodata.write(b'U')
        elif(my<110)&(my>=80):
            arduinodata.write(b'D')
        elif(my<80):
            arduinodata.write(b's')
        elif(my>200):
            arduinodata.write(b'i')

        
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
        
    cv2.imshow('img',img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()

