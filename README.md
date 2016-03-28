# FractalTree
This project uses C++ and the graphics library SFML to draw a fractal tree

I implemented the fractal tree in C++ using SFML as the graphics library. I declared constants at the top for the initial length, angle
of rotation, x and value, and rad (pi/180), base (minimum branch length), and thetaPlus and thetaMin (angles of rotation). Besides
main(), I made a recursive drawing function (drawTree). For SFML, I had to declare a window variable and then have a loop in main that
displays content while the window is open. In my recursive draw function (drawTree), I first tested the base case if the length was less
than base. If this condition was true, I returned, which would execute the other recursive call. I then found my new x and y points by
multiplying the scalar and length by cos or sin theta. I then made a vector that holds the passed in x and y points and the newly
calculated x and y points. I drew the line. I then had two recursive calls, the first executing one side of the tree and the other
filling on the other side. 
