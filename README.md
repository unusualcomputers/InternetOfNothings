

Internet of Nothings is a standalone Wi-Fi network to which you can connect from any internet enabled device. It will then accept any non encrypted* website address and redirect the browser to nothing.
 

It is exactly as useful and innovative as Internet of Things, as long as you don’t consider the ability of corporations to collect your data a useful innovation**.

 
![internet of nothings stages](https://github.com/unusualcomputers/InternetOfNothings/blob/master/IoNs.png)
 
![using internet of nothings](https://github.com/unusualcomputers/InternetOfNothings/blob/master/IoN.jpg)
 

You can see it in action [here](https://m.youtube.com/watch?v=dsmHkF9JIvI){:target="_blank"}

Our implementation is made using a minor adaption of code written by [Ray Burnette](https://www.hackster.io/rayburne/esp8266-captive-portal-5798ff) running on a Wemos esp8266 board wrapped into some home-made silicone dough and a power cable. To use it, plug it into any powered USB port and look for InternetOfNothings network.


 
*Internet of Nothings will not work with addresses starting with https. Note that some browsers automatically redirect some addresses to their https version, for example facebook.com, but facebook.co.uk will work in most browsers.


**Internet of Nothings prevents harvesting and unauthorised use of your data by not being connected to anything else.
