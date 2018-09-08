# fdf

In this project I discovered the basics of graphic programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint.
I also discovered the first graphic library: miniLibX. This library was developed internally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse. This project introduced me to “events” programming.
This project is about creating a simplified graphic “wireframe” (“fils de fer” in french, hence the name of the project) representation of a relief landscape linking various points (x, y, z) via segments. The coordinates of this landscape are stored in a file passed as a parameter to your program.

![alt text](https://github.com/petrechenko/fdf/blob/master/Screen%20Shot%202018-09-08%20at%2011.56.46%20AM.png)

Each number corresponds to a point in space:
• The horizontal position corresponds to its axis. 
• The vertical position corresponds to its ordinate. 
• The value corresponds to its altitude.

