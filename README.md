# kb_arduino_lib
##How To:
To use this file you will need to have an arduino uno compatible board, 2 wires, and the upload cable. <br />
<img src="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/images/IMG_0099.jpg" /><br />
To start off this tutorial you need to know a few things, they will be covered in this tutorial but if you know them ill 
indicate if you can skip this part :). You need to put you're arduino in DFU-mode and you need to know how to install a 
library in the arduino ide. Basicly this tutorial with cover those two parts and then it will explain the basic syntax.<br />

###How to install
To install and setup the arduino you need to install dfu-programmer:<br />
+=============================+=======================+<br />
| sudo apt-get install dfu-programmer | brew install dfu-programmer |<br />
+=============================+=======================+<br />
After installing the dfu-programmeryou need to setup youre arduino in DFU-mode. To do that on MY board you need to wire up
those pins as seen on the picture below, just make the black cable touch slightly the middle pin and remove the orange one.
<br />
<img src="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/images/dfumodeArduino.png" /> <br />
After that you need to flash
<a href="https://github.com/p4p1/kb_arduino_lib/blob/master/firmware/Arduino-usbserial-uno.hex">this firmware</a>.
You should get the output as bellow if you are on mac:<br />
<img src="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/images/dfu-programmer.png"> <br />
Note that you should use the dfu-prog script to flash a script on you're arduino
After flashing this firmware you can now upload a script to you're arduino. we will be using the scirpt given in the exemple
folder. To do this simply opne up you're ide and open the scirpt. From now on you have to install the library, get the .zip
file that is located in the master folder and in you're ide go to:<br />
+=================================+<br />
| Sketch > Include Library > Add .Zip Library |<br />
+=================================+<br />
After adding the library you can now code anything that you would like. After installing the library and uploading the sketch
we are not yet finished you need to change the firmware again on you're arduino to
<a href="">this one</a>
Note that changing the firmware will not remove the program uploaded to the arduino.

###How to code ;)
