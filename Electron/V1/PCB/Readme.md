FETish On A Stick
=================

Triple FET on a Stick.

2 x large high current FETS
1 x low current (max 200mA) FET

All FET's PWM-able (see notes)



Notes:
------

V1.00 - Track missing from A4, needs A4 outer pad soldered to Socket

A4 and D3 share PWM channel. 
* Use digitalWrite with one and PWM with the other
* or digitalWrite with both
* Do not use PWM with both (or they will both have the same PWM value).


TODO: 
-----
* Connect A4 properly
* Perhaps have option of A4 OR WKP to allow for all 3 FETs to be used at once.
* Increase font size for Photon/Electron markers
