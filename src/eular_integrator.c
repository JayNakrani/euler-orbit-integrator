#include <stdio.h>
#include <math.h>

#define DAY_TO_SEC(DT) (DT * 24 * 3600)
#define NORMALIZE_POS(A) (A/1E+08)

typedef struct struct_position_vector
{
	long double x,y,z;
}position_vector;

typedef struct struct_velocity_vector
{
	long double vx,vy,vz;
}velocity_vector;

inline void print_vectors(position_vector a,velocity_vector b,double t)
{
	printf("t:%06.2lf",t);
	printf("\tx:%01.12LE\ty:%01.12LE\tz:%01.12LE",a.x,a.y,a.z);
	printf("\t vx:%01.12LE\tvy:%01.12LE\tvz:%01.12LE\n",b.vx,b.vy,b.vz);
}

int main(void)
{
	position_vector cur_pv,next_pv; // position vectors
	velocity_vector cur_vv,next_vv; // velocity vectors
	long double cur_t = 0;	//current time
	long double finish_time = 30 * 365; // total number of days. 30 years multiplied by 365 days a year. Ignoring leap years for now..!!
	long double dt = 0.1;	// delta-t in number of days
	// constants
	const long double G = 6.67384E-17;
	const long double M_sun = 1.9891E+30;
	// misc
		long double divisor_tmp = 0;
	
	// initialize
		cur_pv.x = 5.096210785220794E+08;
		cur_pv.y = -5.625673003639891E+08;
		cur_pv.z = -9.109215289602894E+06;

		cur_vv.vx = 9.531092644846060E+00;
		cur_vv.vy = 9.401837023552590E+00;
		cur_vv.vz = -2.522073348918472E-01;

		cur_t = 0;	// initialize t to starting time


	// print initial situation
		print_vectors(cur_pv,cur_vv,cur_t);
	// simulation main loop
		// xTRA Code:{
			//finish_time = 10 * 365;
		//}
		while(cur_t < finish_time)
		{
			// increment time
				cur_t += dt;
			// compute position vector
				next_pv.x = cur_pv.x + (cur_vv.vx * DAY_TO_SEC(dt));
				next_pv.y = cur_pv.y + (cur_vv.vy * DAY_TO_SEC(dt));
				next_pv.z = cur_pv.z + (cur_vv.vz * DAY_TO_SEC(dt));
			// compute velocity vector 
				divisor_tmp = sqrtl(powl( (powl(NORMALIZE_POS(cur_pv.x),2)+powl(NORMALIZE_POS(cur_pv.y),2)+powl(NORMALIZE_POS(cur_pv.z),2)),3)) * 1E+04;	// Use of normalized values for powering.
				next_vv.vx = cur_vv.vx - (G * M_sun * cur_pv.x / divisor_tmp );
				next_vv.vy = cur_vv.vy - (G * M_sun * cur_pv.y / divisor_tmp );
				next_vv.vz = cur_vv.vz - (G * M_sun * cur_pv.z / divisor_tmp );

				// xTRA Code:{
					// char c;
					// printf("\n%01.12E\n",(G * M_sun * cur_pv.x / tmp ));
					//scanf("%c",&c);
				//}

			// assign them to next
				cur_pv = next_pv;
				cur_vv = next_vv;
			// print on the screen
				print_vectors(cur_pv,cur_vv,cur_t);
		}

	return 0;
}