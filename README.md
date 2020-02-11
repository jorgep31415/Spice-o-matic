# Spice-o-matic
The Arduino code behind our hardware hack for the 6th Annual IdeaHacks, taking place at UCLA.

Pertaining to the theme of college lifestyle, we created an automatic spice shaker to tackle the challenge of food automation.

The shaker uses a Raspberry Pi as the main controller for three components:
- Plate Control: To communicate with an Arduino Nano (code in dc_motor folder) wired to a battery that rotate our plate around with a motor driver.
- Shaker Control: To communicate with an Arduino Nano wired to a battery that shakes the shakers up top back and forth with motor drivers.
- Display Modules: To communicate with an Arduino Nano (code in display folder) wired to a battery to display START, STOP, SALT and PEPPER when appropriate, on the top-right alphanumeric display. It also lights up some LEDs inside the box.

Our current design uses a box that represents a microwave mechanism as the idea is to multitask when working on your meals. It also only uses two shakers (for salt and pepper), but for scalability one can add more shakers to the design. 

Pictures of the design's front (front-end.jpg) and back (back-end.jpg) are included.

We reached the final round (top 6 out of ~45-55 teams) with this hack.
