# ArduinoCar_BluetoothControl
---
This is a car made on Arduino Uno, called "*F1*".
---
### Car's Components:
- Arduino Uno
- Driver L293D
- 2 x DC Motors
- HC-05 Bluetooth Module
- Logic Level Converter 3.3V 5V TTL
- Breadboard
- Battery holder 8xAA - 12 V ( I use only 9V, because with 12V the car is too fast)
- 2 x Leds (one red and one blue)
- 3 x Resistors : *100 Ω (for buzzer), 2 x 220 Ω (for Led)*
- Wires
- Buzzer

---
### *Here's the Fritzing Scheme*
![](Matrix_Game_Fritzing.jpg)

The main idea of the game is that on the matrix are generated randomly a number of points, which the player has to remember and then 
find their place on the matrix. Initially, user has to choose the complexity type, number or time. Number complexity suppose to increase the number of points that user has to remember each level, while time complexity suppose to reduce the printing time of the points each level. When the player choose an option, the game is starting with a special sound provided by buzzer and the first level is loading.From here, every event occuring in the game has his own sound emited by the buzzer, which make a nice gaming atmosphere. 
The user has 5 lives for every level, so that, if he misses the point, he lose a live-point and if he guessed it, he will increase he's score. The game is finishing either he passed the level 10 (he passes the game) or he loses all his lives (game over). After the game is finishing, the game checks if the player has set a new record and then is asked to play again. If he decides to play again the game restarts, otherwise apears a scrolling text to the right which is simulation of the power off. In order to power on the game user has to press the button for a while (this is mentioned on the scrolling text).

#### Take a look: https://drive.google.com/file/d/1djT2WqwJmLTHDjm_n4rEjbH16PFHNK-5/view
