$sphereObj
==============

$sphereObj is designed to solve the following problem: Given a 3-d vector, and assuming it's end lies on the surface of a sphere centered at the origin I want to :
Be able to easily ask for
 * distance 
 * area
 * volume
 * vector in spherical co-ordinates
 * volume based on bounds
 * The circumference based on a given plane of intersection
 * The mass given a density, or even given a density function? This would require tripple integration though
 * Maybe a cross-sectional graph? This would be a cool exercise in visual representation that you could use external GUI's for
 * Gravitational attraction / kg based on distance? (This requires mass)
 * You could do something cool like a simulation of it as projectile using a basketball net or something. This would be kind of whacky in fact it's a completely different problem
 

 $Features
 ============

-Asks for the coeficients of a three dimensional cartesian vector {test1.exe}
-Prints them to the screen {test1.exe} verified as working
-Determines the spherical cords of the vector and prints them to the screen
-If only inputs are 0's the user is told it can't be resolved and the program finishes

 $TODOs
 =============
Have the program reprompt them when they enter only zeros
Have the program exit if the values are NULL
Have it determine the cross sectional area (at a given intersection plane determined by an input)
Have it determine the volume
