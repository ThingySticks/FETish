Example code for Quad N-Channel FETs ThingyStick
################################################

Based on the Particle Photon. Should work for the Electron as well.

Assumes FET solder link select uses the Photon selectors (A3, A4, D2 and D3).
Change 

int outputs[] = {D2, A4, D3, A3};

to

int outputs[] = {B0, B1, B2, B3};

if using 


To use this example:

* Create a new App in build.particle.io
* Paste in the sample code.

The code creates 5 Particle functions that can be called over via the internet:

// Switch on and off a specific output channel (1 to 4).
SwitchOutputOn (String args);
SwitchOutputOff (String args);

// Switch on and off a named light (Red, Yellow, Green and Buzzer).
SwitchLightOn (String args);
SwitchLightOff (String args);

// Sequences the FETs.
ShowSequence (String args);