/*
  Author:  Herb Yang, March 9, 2010.
  Updated: Oct. 2,  2010
  Updated: July 27, 2011
  Simple scene data parser.

  The file format for a scene is:
  <camera decl>
  <ambient light decl>
  <# of point lights>
  <point light decl>
  <point light decl>
  ...

  <sphere decl> // spheres, cylinder and triangles can appear in any order
  <sphere decl>
  <triangle decl>
  <cylinder decl>
  ...

  where:
   <camera decl> =
     UpX UpY UpZ GazeX GazeY GazeZ EyeX EyeY EyeZ ViewDist
     RightUpX RightUpY LeftLowerX LeftLowerY (These are the (bu,bv), and (au,av) discussed in class.)
	 Image resolution X Image resolution Y
   <ambient light decl> =
     Red Green Blue

   <point light decl> =
     Number of point lights
     PosX PosY PosZ ColorR ColorG ColorB

   <material decl> =
     AmbientRed AmbientGreen AmbientBlue
     DiffuseRed DiffuseGreen DiffuseBlue
     SpecularRed SpecularGreen SpecularBlue
     SpecularExponent
    s or S
   <sphere decl> =
     PosX PosY PosZ Radius <material decl>
    d or D
   <disk decl> =
     PosX PosY PosZ normalX normalY normalZ Radius <material decl>
   c or C
   <cylinder decl> =
     PosX1 PosY1 PosZ1 PosX2 PosY2 PosZ2 Radius solidFlag <material decl>
   p or P - Polygon
   <triangle decl>=
   Number of vertices
   vertex 1 // The vertices must be specified in clockwise direction
   vertex 2
   vertex 3
   ...
   <material decl>
   
*/

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "color.h"
#include "scene.h"
#include "camera.h"
#include "imageviewer.h"

// Parse the given file, and add the scene objects to the scene
// return 1 iff successful
// The routine bails of the first error
void parse_file(ifstream& file, Camera *theCamera, Scene *sceneData);

#endif

