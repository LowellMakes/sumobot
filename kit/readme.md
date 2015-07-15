Lowell Makes Sumo Bot Kit
=========================

## Parts

   The bill of materials is in Sumobot_Kit_BOM.xlsx in this directory

* Arduino Uno<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/ArduinoUno.jpg" width="150px"> X 1
* Sensor Shield<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Sensor_Shield.jpg" width="150px"> X 1
* Ultrasonic Range Finder<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/HC-SR04.jpg" width="150px"> x 1
* Battery Box<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/battery_box.jpg" width="150px"> x 1
* Jumper Wires<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/jumper_wires.jpg" width="150px"> x 1
* USB Cable<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/usb_cable.jpg" width="150px"> x 1
* IR Line Sensor<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/ir_line_sensor.jpg" width="150px"> x 2
* Servo Wheel<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/servo_wheel.jpg" width="150px"> x 2
* Modified Servo<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/servo.jpg" width="150px"> x 2
* O-rings<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/o-ring.jpg" width="150px"> x 4



## Assembly

* Step 1<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step1.jpg" width="300px">
* Step 2<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step2.jpg" width="300px">
* Step 3<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step3.jpg" width="300px">
* Step 4<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step4.jpg" width="300px">
* Step 5<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step5.jpg" width="300px">
* Step 6<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step6.jpg" width="300px">
* Step 7<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step7.jpg" width="300px">
* Step 8<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step8.jpg" width="300px">
* Step 9<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step9.jpg" width="300px">
* Step 10<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step10.jpg" width="300px">
* Step 11<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step11.jpg" width="300px">
* Step 12<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step12.jpg" width="300px">
* Step 13<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step13.jpg" width="300px">
* Step 14<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step14.jpg" width="300px">
* Step 15<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step15.jpg" width="300px">
* Step 16<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step16.jpg" width="300px">
* Step 17<img src="https://raw.githubusercontent.com/LowellMakes/sumobot/master/kit/images/Step17.jpg" width="300px">


## Programming Your Sumobot

In order to program your robot you will need the Arduino software.  You can find instructions on how to download and install the Arduino stoftware here: <a href="https://www.arduino.cc/en/Guide/HomePage"> Getting Started With Arduino </a>

Once you have the software installed, you will need to make sure you have the NewPing library that will help you control the Ultrasonic Range Finder.

There are a few ways to do this:

Easy way: If you have the latest Arduino software then open it and click Sketch > Import Library > Library Manager and type NewPing in the search.  Then select it and click install.


Harder ways:

If you have an older version of the Arduino software you will need to obtain the NewPing library and install it using the directions on this site: <a href="https://www.arduino.cc/en/guide/libraries"> Arduino Library Installation</a>

Two ways to get the library:

The NewPing library is included with the other files in this software repository.  Download this repository (if you haven't already) and copy the folder called NewPing into your libraries directory. <a href=https://github.com/LowellMakes/sumobot/archive/master.zip>Download All Sumobot Files</a>

You can also download the library from here: <a href="https://code.google.com/p/arduino-new-ping/downloads/detail?name=NewPing_v1.5.zip&can=2&q=">NewPing Library</a>

OK, now you should be ready to program your robot.  I recommend you unplug your servo motors (they should be plugged into A2 and A3).  This is for two reasons: Not everyone's USB port has the power to run two servo motors.  If you draw too much power from your USB port your computer will shut the port off.  It's probably also possible to damage the computer, though I've never seen it happen.

Also, once your robot is programmed it will spring to life, and you don't want it walking off the table while connected to your USB port.

So, plug it in and open the Arduino software.  Click the Tools menu and select Port.  You should see a port like this: Com 5 (Arduino Uno).  Your port number may be different but it should say Arduino Uno.

Select that port and then click Tools > Board and make sure Arduino Uno is selected.

Open the SumoBot code.  If you downloaded all the SumoBot files you will find the code in sumobot\code\sumobot\sumobot.ino.  You can also jump to it here: <a href="https://raw.githubusercontent.com/LowellMakes/sumobot/master/code/sumobot/sumobot.ino"> sumobot.ino </a>.  Right click that link and select "Save Link As...".

With your robot plugged into USB and the Sumobot code loaded in the Arduino software click the arrow in the upper left corner (next to the check mark) to "upload" your code.  Once it is programmed, diconnect the USB, reconnect your servo motors and turn on the switch on the battery box.  If all goes well you should be watching your Sumobot drive around in no time.