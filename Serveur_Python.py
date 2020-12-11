#   Sarah Yakoubi & Leonard Lesage
#   Twitter Bot - Code du serveur Python
#
#   Ce code creer un serveur Python qui recoit les donnees du ESP32
#   puis envoi un tweet quand la bonne donnee est recu.

import socket
import tweepy
c = 1

#Connection a Twitter
CONSUMER_KEY =      'Consummer key goes here'
CONSUMER_SECRET =   'Consumer secret key goes here'
ACCESS_KEY =        'Access key goes here'
ACCESS_SECRET =     'Access secret key goes here'

#Authentification de la connection
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)
api = tweepy.API(auth)

#Connexion ESP32 featherboard
sock = socket.socket()
host = "Adresse IP"     #ESP32 IP in local network
port = 80               #ESP32 Server Port    
sock.connect((host, port))
  
while(1):
    data = sock.recv(4096)

    #Verifier la donnee recu
    if data == b'f':
        print(data)
        api.update_status("le bouton a été appuyé" ,c)
        c = c + 1
    data = " "
