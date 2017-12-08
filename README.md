# PA-9-Game-Fractal

To run the program you must have all the required .dll files present in the debug folder. (which have been provided)
You must have sfml library and must change VC++ configuration properties.

Open the properties page of your project
Select All Configurations under Configuration.
Switch to VC++ Directies to make the changes to the include directories and library directories

In addition to this to run the program you must have
additional dependencies in your linker input under "debug" configurations:-
sfml-main-d.lib
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
sfml-network-d.lib

and

following dependencies in your linker input under "release" configurations:-
sfml-graphics.lib
sfml-window.lib
sfml-system.lib
kernel32.lib
user32.lib
gdi32.lib
winspool.lib
comdlg32.lib
advapi32.lib
shell32.lib
ole32.lib
oleaut32.lib
uuid.lib
odbc32.lib
odbccp32.lib

Lastly, you can find Mandelbrot ouput in the output file named as output_image with extension .ppm

Hope you like the program!!
