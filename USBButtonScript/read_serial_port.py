import serial
import time
import pygame
import requests

arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)

print("starting_script...")
def read(): 
    data = arduino.readline()
    x = b'play_sound\n'
    if x == data:
        print("Hello there!")
        #play sound
        pygame.mixer.init()
        pygame.mixer.music.load("message.mp3")
        pygame.mixer.music.play()
        requests.post(url='http://localhost:3000/change_state')
    return data

while True:
    value = read()
    print(value)