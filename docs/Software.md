# Dakota Sim Software

## RV-10
The RV-10 was early with G3X and TDS GTN support.  Its power and handling are similar to the low-wing Piper Dakota we fly.

## TDS GTNxi Pro

The GTN650 was an essential piece in my setup. My move from X-Plane to MSFS was largely driven by the need for a Garmin G3X that integrated properly with the GTN.  The current G3X from Asobo is very good and I’m grateful to TDS for integrating with it.

TDS builds a high quality instrument and their support has been superb, both for me and others on Discord.  They don’t over-promise and they take actual bugs seriously.

One downside is that each time you load MSFS you need to use TDS admin to set the nav source from the 750 to 650.  Another downside is that I’m still not able to maximize the window in the RSG screen without a title bar.  Either the bar shows and the window can be sized, or the bar is hidden and the app window is about 30% of the size needed. I simply pull the title bar outside the instrument.

I’ve used the PMS version which works not as well but mostly was not integrated with the G3X.  My first GTN was for X-Plane from RealityXP, it worked OK but their constant license renewal was annoying.

## MSFS Popup Panel Manager

Thanks to Stanley Kwok for creating and sharing his popout manager. This free tool makes it possible to use a touch display and also automates popout and placement when flying.  

It’s hard to understand how Microsoft continues to ignore touch instruments.

Unfortunately, I still need a mouse on standby because my G500 panel frequently ignores touch input on the left side of the display. This isn’t a hardware issue—other applications recognize touch input in the same area. Since the G3X is my primary instrument, this matters quite a bit and is one of the main reasons I moved from X-Plane to MSFS.

## MobiFlight

MobiFlight is an open source bridge between hardware and sims.  It’s essential for my GNC255 radio built by a MobiFlight expert. MobiFlight also controls the compass.  I don’t know the software yet but for better control options I am considering moving my own arduino instruments to it.

## RealSimGear MSFS Device Interface

Since my setup includes five RealSimGear instruments, I rely heavily on their MSFS device interface. I’m glad to see they’ve become more active on Discord and in support channels again, though their primary focus now appears to be commercial SR22 simulators.

My setup still includes a G500 panel that I originally purchased during my X-Plane era.

Through experimentation, I’ve remapped this hardware to function with G3X commands, using the command.ini file. To improve usability, I’ve labeled certain G500 buttons for G3X functions.

While this setup is a little janky, it works well enough that I don’t need to buy another $1,200 RealSimGear instrument or build a custom one from scratch.

The command.ini in the project also has GMA350 audio panel knobs, the default only maps critical buttons.

I suspect the RealSimGear device interface is responsible for the total loss of controls that occurs about 30 minutes into a flight session in MSFS.

Controls only return if I open the Controls menu and then exit back into the flight, which suggests an interface-related issue. Since this only happens when RSG is loaded, I’m considering switching to spad.next as an alternative.

## LittleNavMap

LittleNavMap is excellent for quickly creating flight plans, which I sometimes export to the GTN.

I also use it to monitor my flight progress and manage descent slopes efficiently.

## RealVNC

Spending hours in the cockpit chair with a keyboard tray and a sea of monitors can be tiring.  RealVNC has been great for some projects working upstairs in an office setting.  Real VNC also lets me find lost monitors and work when the screen is covered by panel.
