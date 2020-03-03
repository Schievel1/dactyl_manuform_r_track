This is a dactyl manuform with a tracing ball in the right thumbcluster.
If you want the final stl its the boolean/right.stl

For bearings and other parts see: https://github.com/ploopyco/mouse/wiki/Ploopy-Trackball-Kit-Assembly
The Motion sensor: https://github.com/ploopyco/mouse/wiki/Ploopy-Trackball-Kit-Assembly

The state of the project is work-in-progress

Project wise i started with the dactyl manuform code:
-removed the wire holder
-moved the buttons on the thumbcluster for space
-removed one button and reconnected everything
-removed the screws

FreeCAD:
-place hotswaps on all buttons
-make joystick place
-make joystick hole (negative)
-add skrews
-export positives to p2.stl and negative to m1.stl

OpenSCAD Boolean operations:
-add all from FreeCAD model (p2.stl)
-remove hole (m1.stl)
-export to stl

-> CUDA -> printed with Ender 3
