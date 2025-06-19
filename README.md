# ECRFV2-Dual-Jammer
Dual jammer for Evil Crow RF V2; commanded only by side buttons.

Jammer using both cc1101 modules of the ECRF-V2 to jam any frequency supported by the cc1101. 
All value are hardcoded and customizable for each module, so anytime you whant to change these settings, you must connect ECRF-V2 to a computer, Modify the values you whant in the .ino file then do again the installation process (without the installation of the library) to upload the new firmware with the new settings.
All is very stable, no bugs. you can start and stop as you wish without any crash, feeze, need reboot, etc... can work as long as your battery can :)

WARNING: Actual settings of the jammer are generals and will not give excellent results... you must find your right settings, depending on what you targeting and so, you must know your stuffs to make it work well.
Keep in mind that even with the perfect settings, the cc1101 is not very powerfull and you will need some amplification to have a decend reach grade radius and power.


Installation (Windows):

- Open Arduino IDE
- Install needed library: Smart-RC-CC101-driver-lib
- Plug ECRF-V2 into a USB hub of your computer
- Open .ino file with Arduino IDE
- Select Board >> ESP32 DEV Board >> COM port of ECRF-V2
- Upload code
- Done.

How to use?

- jammer is inactive when you plug the ERCF-V2 to energy.
- press button 1 (the closer one of the USB port) to start jamming on both frequency.
- press button 2 to stop all.

- 

Educationnal purposes only.

Buy me a kofee (BTC): bc1qa47k9qmpps0gnj4a0d2643ldvxatgg4r6ln4hy
