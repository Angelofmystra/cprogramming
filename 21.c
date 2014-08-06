/*  
    Robot Tour Optimization
    Copyright (C) 2014  Bertrand Brompton 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/><stdio.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/* The official name of this program (e.g., no `g' prefix). */
#define PROGRAM_NAME "robot_tour_optimizer"

#define AUTHORS \
    proper_name ("Bertrand Brompton")

struct point {
    int x;
    int y;
};

struct closest_pair {
    struct point a;
    struct point b;
};

int
square(int x)
{
    return x*x;
}

int 
dist(struct point p1, struct point p2)
{
    return sqrt(square((p1.y-p2.y))-square((p1.x-p2.x))); // basic weak implementation
}

struct closest_pair
brute_force_algorithm(struct point A[], int n)
{
    int min_dist = 999;
    struct closest_pair c_p;
    for(int i = 1; i < n-1; i++)
    {
        for(int j = 1; i < n; i++)
        {
            struct point p = A[i], q = A[j];
            if (dist(p,q) < min_dist){
                min_dist = dist(p,q);
                c_p.a = p;
                c_p.b = q;
            }
        }
    }
    return c_p;
}

int 
main(int argc, char **argv)
{
    int size = 20;
    // TODO: populate the array of points 
    struct point points[size];
    struct closest_pair c_p = brute_force_algorithm(points, size);
    printf("Closest Pair: Point A (%d, %d) to Point B (%d, %d).\n", c_p.a.x, c_p.a.y, c_p.b.x, c_p.b.y);
    return 0;
}
