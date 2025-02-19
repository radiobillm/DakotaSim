# Piper Dakota Sim

February 2025

[dakota-sim-photo.jpg]

The sim was built to practice IFR flying using new avionics that match our real plane. It has also been a great opportunity to learn Arduino and explore my Onefinity CNC/Laser.

ChatGPT tells me that Piper has sold about 30,000 PA-28 series aircraft, compared to 45,000 Cessna 172/182 models. It’s surprising—and somewhat frustrating—for Piper pilots that most commercial flight sim products are Cessna-based. This project was built to create a sim that closely matches our plane..

The sim community is a gem.  After learning from so many projects and discussions, I felt guilty for never sharing my work.  This document includes the key components, build details, and lessons learned that I believe will be most helpful to others.

The current build would cost about $10,000. Below is a breakdown of prices.

[dakota-sim.jpg]


## Hardware Fabrication


### PA28 Throttle

[throttle.jpg]

I started by buying a real replacement throttle assembly trim and label, then designed and 3D printed the body.  

[throttle-inside.jpg]

To fit the closely spaced throttle, prop, and mixture levers, I used bellcranks to offset the potentiometers.

.

 

The M4 screws into 3mm PLA holes were not strong enough on their own and required glue for reinforcement. Threaded inserts would be a better solution, as the tight space makes soldering and adjustments difficult.

Label strips are glued to the top of the trim cover under a printed trim plate.

[throttle-proto.jpg]


### Bezels

Simple bezels are printed for the yoke, manifold, and tach gauge, carb heat and togo switch openings.  I may build a bezel for the JPI Engine monitor.


### Switch Panel

[switch-back.jpg]

The hard part for the switch panel was sourcing rocker switches that match a real PA28.  I ordered a few alternatives but never found half-width rockers that could be ganged together to match the real set, nor found suitable grey covers.  

As a future improvement, I plan to laser engrave labels onto the switch covers for a more authentic look.


### An Arduino Micro in the switch panel handles the switches, throttle, Carb Heat lever, and TOGO button. 


### Carb Heat

[carb-heat.jpg]

The Carb Heat lever is printed to sandwich the end of a metal toggle, the assembly also has a switch holder under the table.  A printed panel trim insert keeps the lever sliding vertically with a realistic feel.  MSFS offers Anti Ice On or Off, but no variable carb heat setting like a real PA28.


### Center Column

[center-column.jpg]

A bolted support box under the table houses:

✔ Parking Brake

✔ Fuel Selector Switch

✔ Rudder Trim

✔ Arduino Pro (which also controls the key switch)

Due to the limitations of my 255mm 3D printer bed, the column is built from two stacked boxes. The parking brake is mounted to the ceiling of the lower box.

However, the top box is too small to allow easy internal access. A better approach would be to side-mount the brake and leave an open column for easier maintenance.

The Arduino is floating with no mount, it also controls the key switch.


### Parking Brake 

Edited:

I ordered the SimWales Parking Brake (designed for a Cessna 172) from caspajack on eBay, and it works well.

However, Parking Brake On and Off controls do not function correctly in either the Cessna 172 or RV-10. As a workaround, I mapped the Off control to Parking Brake Toggle for reliable operation.

The brake main rod stop was removed to remove the faceplate.  Be careful when rotating the brake assembly to preserve normally in and brake-off horizontal, vs pull and rotate brake-on vertical.  The switch pin can be flipped to an alternate hole.


### Fuel Selector 

The Fuel Selector switch is simply a trim piece over a 5-selector switch.  

On a real Piper PA-28-235, the fuel selector is located on the center firewall and has five fuel positions:



1. Off
2. Left Tip
3. Left Main
4. Right Main
5. Right Tip

I was unable to find any published designs for the plastic trim piece, nor could I find an MSFS Dakota or any PA-28 with a four-tank configuration.

[real-fuel-flaps.jpg]


### Rudder Trim

The rudder trim uses a potentiometer identical to those used for the throttle levers. It is mounted with a custom-printed bracket for the center column.


### Key Switch

I ordered the SimWales Key Switch from caspajack on eBay. The spring mechanism is well-designed, and the build quality is excellent.

One challenge was the table height meant moving the switch a little lower than in real life, even after cutting off the top of the assembly. The switch was disabled and the faceplate removed.  When reassembling I first aligned the key position and then the pin so it hits the spring on start. 


### Trim and Flaps

[trim-flaps.jpg]

For a more realistic layout, I mounted an Elevator Trim box on the right side of the chair, where a pole mount normally holds the keyboard tray.  The box has a Trim Wheel, 4-position Flaps Paddle.  Inside the box an Arduino Micro is glued with the USB port facing down. 

The Trim Wheel, potentiometer, and switch were salvaged from a Desktop Aviator unit I purchased on eBay.

I may upgrade to a powered trim wheel with a geared position indicator in the future.  PA28 pilots will recognize that flaps are set with a long floor-mounted lever, the 172- flap lever is not realistic but at least it is centered near the floor.


### Compass-Dimmer

The whiskey-style Compass was purchased from SimWales (via caspajack on eBay), and it looks fantastic.

Mobiflight controls the compass, I had to adjust the suggested settings to use a Display Scale of 9000 and Transform $ * (-12.5).  The compass is powered with a USB 5V USB cable.

[dimmer.jpg]

A printed box with lid houses an Arduino Pro Micro and compass stepper motor driver plus a dimmer connected to the compass and under-glare shelf lighting.  A hydra end from the 12V power supply powers the dimmer.


### Headset

The headset speaker and microphone jacks are connected via a USB Aviation adapter.

Installation Details:



* The adapter’s casing was removed, allowing me to use the jack nuts directly on the panel.
* Since the panel is ¼” thick, a relief pocket is needed on the backside (not currently included in the model).
* The USB board is glued to the back of the panel, as it lacks a dedicated case.

A prior ACM panel grounded the mic so it became unusable with PilotEdge, which was solved by printing bushings to insulate the jacks.  This bushing is unnecessary with plywood.


### Arduinos


### Before this project, I had no prior experience with Arduino or circuit board assembly.  


### Initially, I soldered IDC ribbon cables directly to the Arduino pins, using a separate connector for each control. Later, for the two additional Arduino Pros, I switched to using connectors soldered on the Arduino.


### A detailed pinout is included in arduino-pins.csv.


### I experimented with different print designs for Arduino holders, none worked well and so they are glued or float.  A few soldered wire connections failed and next time I’ll learn to build a circuit board.


### GNC255 Radio

One of my favorite devices in this build is the GNC255 radio, designed and built by Tigerfly.. I have an early build and don’t know if it will be a product.  You can usually find Tigerfly helping others on the MobiFlight Discord.

The radio has realistic knobs and buttons, a bright white OLED display and photo sensor for dimming.  Like the real Garmin, Tigerfly’s software includes frequency database lookup.  

Tigerfly was especially helpful getting me started with MobiFlight and I hope he’ll extend the line with a matching transponder and/or share the design.


### Table

[table.jpg]

The support table is built using ½” plywood, with edge and side panels replacing the original chassis metal.

The side pieces are laser-cut from 5.2mm plywood at 7mm/sec.  To simplify assembly, I etched laser guide lines onto the table base, which made it easy to align and cut the rails, side panels, and blocks..

The panel and table are setup for a left side yoke to be centered on the chair. The left side metal yoke box and the right side metal power strip help keep the assembly rigid. 

To support the table, I removed the original chassis monitor stand and replaced it with:

A ¾” x 24” threaded water pipe (cut in half)

Flanges attached to each end for easy mounting

The water pipe fits perfectly into the chassis monitor tubes

The table and supports are painted flat black.  M6 bolts attach the table to the flange and front metal square tube, these holes are drilled after aligning and squaring the table but not in the.  A right-side leg supports the overhand and keeps the table stable.

Instead of threaded inserts I used a dab of glue behind M4 nuts which made is easier to attach and remove the panel and other components.

[table-back.jpg]

[power-hubs.jpg]

For aesthetics and easier troubleshooting I took time for the component layout above and under the table and designed and printed holders for power supplies, USB hubs, and HDMI adapters.


### Panel

[pane-laser.jpg]

The firm upgrading our avionics supplied a pdf which became the scaled panel layout (\panel\01l-panel-pdf).  I made a few compromises because my panel rides on the front of a support table and for the 14” right side monitor.

The panel is from two 3.2mm Sandee layers laser cut and glued together.  The back layer has larger openings that outline the switch and monitors.  Front layer cutouts for the monitors and switch panel are smaller for a recessed mount.  Before this two-layer build I had used the CNC to cut and recess openings.  But after finding build conflicts I moved to two layers, because I had the material and could quickly cut with the laser.

Each item on the panel has a group and layers to model in 3D.  Templates from RealSimGear I found did not work well on earlier sims, mine are from trial and error with cardboard test pieces.

My 44W laser cuts the 2.6mm plywood at 15 mm/second and 100% power.

To produce an file for cutting the panel requires showing the *-cut layer within each group. These layers should be tagged as “-cut”.  The switch and monitors are recessed with cut lines for each layer.

To fully embed LCD displays and have flush instruments my prior panel was from a ¼” plywood back, ½” thick cardboard center and ¼” ACM front.  It looked great, but was complicated and unrealistic because our real instruments are surface mounted.

The panel front is covered with **black matt auto wrap** which worked surprisingly well. My main lesson was to apply over a sanded clear poly.  Even after wiping twice, bare plywood held small flakes and every spec showed through the wrap. I used a heat gun to stretch slightly and cut openings after applying.  If building a second model I’d try to wrap the plywood before the laser cut.

The prior black ACM panel looked great.  But after ruining a $40 ACM panel on the CNC, I decided to not wait and buy another. The plywood + wrap can be cut with just a laser.

A low-mounted monitor under the table displays the Air Manager Manifold and Tach gauges. The monitor is secured with 3D-printed brackets, glued using construction adhesive. 

Initially, I experimented with different mounting designs—including tabs—but found that toggle brackets provided the most secure fit. These same brackets were also used to mount the right-side monitor and switch assembly.

[hold-down-bracket.jpg]

The model has an unused gauge cutout layer. I may build stepper motor versions for our oil, fuel, manifold and tach that match our real plane.


### Table

[table.jpg]

The support Table is ½” plywood with edge and side pieces to replace the chassis metal. 

The side pieces are laser cut from 5.2mm plywood at 7mm/sec.  Laser lines etched into the table base made it clear where to cut and align the rail, sides and blocks.

The panel and table are setup for a left side yoke to be centered on the chair. The left side metal yoke box and the right side metal power strip help keep the assembly rigid. 

For support I replaced the original chassis monitor stand.  A 3/4”x24” threaded water pipe was cut in half and flanges attached to each end.  Those fit perfectly into the chassis to support the table.  The table and supports are painted flat black.  M6 bolts attach the table to the flange and front metal square tube, these holes are drilled after aligning and squaring the table but not in the.  A right-side leg supports the overhand and keeps the table stable.

[power-hubs.jpg]

For aesthetics and easier troubleshooting I took time for the component layout above and under the table and designed and printed holders for power supplies, USB hubs, and HDMI adapters.


### Glare Shield

The glare shield has been the most time-consuming part of the build. My trepidation building one had me hacking the Volair panel for too long. But my first glare shield is only OK.

[glare-back-end.jpg]

The curved vertical back of the glare shield (glare-base layer) is built from two laminated ½” plywood pieces, cut on the CNC. 

[glare-back-end.jpg]

[glare-laminate.jpg]

For the horizontal face, I initially scored and steamed ⅛” plywood, attempting to bend it around the PA-28’s tight end curves.  This was slow and the material kept splitting. The process was slow, and the material kept splitting.  So I abandoned the approach instead printing end pieces for the steep curve (end-right/left). These are notched for the wood layers and glued with construction adhesive, it worked well.  

The plywood and 3D-printed end assembly created a strong base for laminating two layers of 2.6mm plywood, which I formed and clamped to the curved back and end sections.

A second ¼” plywood curve was added to reinforce the structure and create a pocket for the panel. A thin ¼” plywood trim was also added to house the LED rope and provide a termination point for the foam covering. The LED rope doubles as a piping cord, securing the vinyl cover material in place.

The entire assembly was painted flat black before applying the foam padding and vinyl cover.

Long M4 screws were installed through the back to secure the vinyl trim and attach the glare shelf to the panel. Although I forgot to include screw inserts, the friction fit is strong enough to hold it in place.

When wrapping the ¼” neoprene foam, I made the mistake of applying strong adhesive to the front edge first. I realized the foam wouldn't stretch or compress well around sharp curves. Attempting to soften it with a heat gun only caused it to break down. I had to cut V-gaps to fit the shape, but those gaps are still visible through the thin vinyl cover.

The assembly is then covered with a flexible leather-like adhesive-backed furniture patch material.  This also looks home-made because the curves and corners don’t tuck.  Next time I would either persuade my wife, learn or buy a sewn leather wrap formed for the surface.

[glare-right.jpg]

Because the vinyl ends peel off, I then designed and printed relatively complex end caps.  

The back vinyl is covered with a trim cap.  The trim cap is from about 6 pieces printed and glued.  Another material laser or CNC cut would be cleaner and faster.

Finally, the panel is lit with LED rope which does double duty by tucking in the vinyl.  The LED strip glows nicely and can be cut at about 2” intervals.  Leads are soldered and run behind the panel and are terminated with a 2-pin connector for the dimmer box.


## Hardware Products


### Chassis

[volair-chasis.jpg]

Volair’s Sim Chassis is sturdy and adjustable, the seat is comfortable.   The optional keyboard tray and armrests are nice.  I’ve not used any of the multiple plate mount attachments included.  

Their monitor support would be good for even a heavy single center monitor, but not for three.  I’ve replaced the monitor poles with rear table supports and built a floating shelf for the iTX computer case.

[computer-shelf.jpg]

Not discussed elsewhere I originally purchased with the Volair G1000 panel.  The panel has a heavy-duty metal structure, back and table.  Before this version I cut away most of the panel inset to replace with my custom instrument panel.  The project has the original sketchup model with their panel carefully measured.


### Computer

Built from the parts list below including an i9 and 4080, performance is good enough to use mostly max settings with three monitors plus five in the panel.  The system was originally purchased for under my office desk, otherwise the small case is not worth the careful work squeezing components together.


### Monitors

[main-monitors.jpg]

Since I was already happy with a previous model, I upgraded to Samsung’s 49” Ultrawide Odyssey G9 as my center monitor, paired with two Samsung 27” side monitors.  

[monitor-stand.jpg]

The SimFab Triple Mount monitor stand is beefy and good without angled front but without side stands. Vertically aligning side monitors took all the adjustment available and then some to match the ultrawide center screen.

All three monitors use HDMI on the monitor connected to one HDMI and two DP ports with adapters on the 4080 card.  For some reason, the ultrawide monitor’s DisplayPort connection was not recognized, and after spending too much time troubleshooting, I gave up and used HDMI instead.  Also, I goofed by buying an Intel i9 processor without graphics.  

The panel includes six monitors, all powered through a USB-to-HDMI adapter:



* RealSimGear G500, GTN, and G5
* A low-mounted display for Manifold and Tach gauges
* A right-side monitor for the JPI Engine Monitor and Transponder

This setup mostly works well, but occasionally Windows 10 forgets the display arrangement or loses touchscreen functionality.  

In an earlier setup, I had nine total displays, but Windows 10 frequently dropped them from the configuration. To fix this, I added a dedicated mini PC to handle Air Manager instruments. Now that I’ve reduced the number of displays, the mini PC is no longer necessary.


### Flitesim Force Yoke

[yoke.jpg]

The Flightsim Force Yoke works well and brings a fun realistic dimension flying the sim.  The yoke box is much bigger than a Honeycomb which became the final straw forcing me to build a fully custom table, panel, and glare shield.


### Thrustmaster TPR Pedals

[pedals.jpg]

Thrustmaster TPR pedals have worked well so far as a nice upgrade from the Logitech set.  The Volair chassis has a framed well area and the pedals are designed for a flat floor.  I solved it by cutting a ¾” spacer that matched the Thrustmaster base.  The spacer has threaded inserts that align with the top Volair slots and an extra hole drilled below, then inserts for the four Thrusmaster base bolts.  This approach has worked well so far even while the right pedal almost hits my center box.


### RealSimGear

The setup includes these instruments:



* G5 works well with the air manager instrument with buttons mapped
* G500 is from an earlier sim and for my G3X, I don’t love it
* GTN650 works well except the home button is fake
* GFC500 AutoPilot is very good, except their vertical trim knob is flimsy
* GMA350 Audio works, I don’t see on their website anymore 

[gfc500-back.jpg]

Sketchup models are organized to use for 3d planning or just keeping the faceplate-cut to export for laser or cnc.


## Software


### RV-10

The RV-10 was early with G3X and TDS GTN support.  Its power and handling are similar to the low-wing Piper Dakota we fly.


### Arduino Joystick


### Three Arduinos cover all input-only controls using the Joystick library.  The project includes code for each:



* Arduino Pro Throttle, Switch, TOGA, Carb Heat
* Arduino Micro Pro Trim and Flaps
* Arduino Micro Pro Parking Brake, Key/Start, Fuel Selector, and Rudder Trim


### One goal was to reduce software stacks which is why the input-only controls are HID and configured in MSFS.  ChatGPT wrote those three software, it’s a marvelous tool for handling details and learning.

With FS2024 I may use MobiFlight or spad.next to better map and maintain.


### Air Manager

I purchased a copy of Air Manager two years ago for my first desktop sim and it’s the only component still used from that era, it's been reliable and a fun tool.  My current panel also has a knobster, unused now but available later.

The $25 Air Manager G5 was the best I found, more realistic than Asobo and without the pop-out hassles.  I use a JPI from the community [lookup source].  SIM Innovations makes Air Manager and has good instructions for using the RealSimGear bezel controls.

From an earlier sim build I created my own GNC255 radio and a GTX345 Transponder.  The radio has been replaced with a much better hardware version.  I still use my Manifold and Tach gauges though neither are finished.  

In this github project you will also find my custom Oil Pressure, Oil Temperature and 4-tank Fuel instruments that match the PA28 panel. I'm no longer using them and they probably have problems.


### TDS GTNxi Pro

The GTN650 was an essential piece in my setup. My move from X-Plane to MSFS was largely driven by the need for a Garmin G3X that integrated properly with the GTN.  The current G3X from Asobo is very good and I’m grateful to TDS for integrating with it.

TDS builds a high quality instrument and their support has been superb, both for me and others on Discord.  They don’t over-promise and they take actual bugs seriously.

One downside is that each time you load MSFS you need to use TDS admin to set the nav source from the 750 to 650.  Another downside is that I’m still not able to maximize the window in the RSG screen without a title bar.  Either the bar shows and the window can be sized, or the bar is hidden and the app window is about 30% of the size needed. I simply pull the title bar outside the instrument.

I’ve used the PMS version which works not as well but mostly was not integrated with the G3X.  My first GTN was for X-Plane from RealityXP, it worked OK but their constant license renewal was annoying.


### MSFS Popup Panel Manager

Thanks to Stanley Kwok for creating and sharing his popout manager. This free tool makes it possible to use a touch display and also automates popout and placement when flying.  

It’s hard to understand how Microsoft continues to ignore touch instruments.


### Unfortunately, I still need a mouse on standby because my G500 panel frequently ignores touch input on the left side of the display. This isn’t a hardware issue—other applications recognize touch input in the same area. Since the G3X is my primary instrument, this matters quite a bit and is one of the main reasons I moved from X-Plane to MSFS.


### MobiFlight

MobiFlight is an open source bridge between hardware and sims.  It’s essential for my GNC255 radio built by a MobiFlight expert. MobiFlight also controls the compass.  I don’t know the software yet but for better control options I am considering moving my own arduino instruments to it.


### RealSimGear MSFS Device Interface

Since my setup includes five RealSimGear instruments, I rely heavily on their MSFS device interface. I’m glad to see they’ve become more active on Discord and in support channels again, though their primary focus now appears to be commercial SR22 simulators.

My setup still includes a G500 panel that I originally purchased during my X-Plane era.

Through experimentation, I’ve remapped this hardware to function with G3X commands, using the command.ini file. To improve usability, I’ve labeled certain G500 buttons for G3X functions.

While this setup is a little janky, it works well enough that I don’t need to buy another $1,200 RealSimGear instrument or build a custom one from scratch.

The command.ini in the project also has GMA350 audio panel knobs, the default only maps critical buttons.

I suspect the RealSimGear device interface is responsible for the total loss of controls that occurs about 30 minutes into a flight session in MSFS.

Controls only return if I open the Controls menu and then exit back into the flight, which suggests an interface-related issue. Since this only happens when RSG is loaded, I’m considering switching to spad.next as an alternative.


### LittleNavMap

LittleNavMap is excellent for quickly creating flight plans, which I sometimes export to the GTN.

I also use it to monitor my flight progress and manage descent slopes efficiently.


### RealVNC

Spending hours in the cockpit chair with a keyboard tray and a sea of monitors can be tiring.  RealVNC has been great for some projects working upstairs in an office setting.  Real VNC also lets me find lost monitors and work when the screen is covered by panel.
---

## Components & Pricing

[Parts and Pricing List Available Here](parts.md)

---

## 📷 Images & SketchUp Models

- All **3D models are available in SketchUp**.
- Files include **faceplate designs for CNC/laser cutting**.

---

