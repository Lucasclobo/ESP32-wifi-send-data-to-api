This program will generate a wifi network, after you connect to the network access the IP http://192.168.4.1/, it will list the WIFI networks, connect to one.

After being connected the AP mode is no longer active, it will only activate if you lose the connection.

With the connection active it starts sending data to the server.

Steps to configure:

1 - Configure the Arduino IDE to use ESP32

2 - Import the libraries into your computer's libraries folder (C:\Program Files (x86)\Arduino\libraries)

3 - In the AP-SEND-DATA.ino file, edit the SSID NAME and the password for the one of your choice.

4 - Add your URL that will receive the data.

5 - Just create a file on your server, which receives the data via post and save it in the database.