#if 0

//#include <Servo.h>
#include <stdio.h>
#include <math.h>
//Servo my;
#define g 7
#define f 4
#define e 7.5
#define hz 6
#define d 6
//double x = 1;
//double y = 1;
#define SERVO_PIN 8
double nx, ny, nz, mid_num;
// void setup1() {
// 	// put your setup code here, to run once:
// 	//Serial.begin(115200);
// 	//my.attach(SERVO_PIN);
// 	double num;
// 	nx = -x;
// 	ny = -y;
// 	mid_num = sqrt(hz * hz - sqrt(x * x + y * y));
// 	nz = mid_num * mid_num / hz;
// 	num = sqrt(nx * nx + ny * ny + nz * nz);
// 	nx = nx / num;
// 	ny = ny / num;
// 	nz = nz / num;
// }



double compute(double nx1, double ny1, double nz1, double nx2, double ny2, double nz2) {
	//printf("%f\t%f\t%f\t%f\t%f\t%f", nx1, ny1, nz1, nx2, ny2, nz2);
	double E, D;
	E = sqrt(nx1 * nx1 + ny1 * ny1 + nz1 * nz1);
	D = sqrt(nx2 * nx2 + ny2 * ny2 + nz2 * nz2);
	double cor1,cor2,cor;
	double a = (E * E + f * f - g * g) / (2 * E * f);
	cor1 = acos((E * E + f * f - g * g) / (2 * E * f));
	cor2 = acos((E * E + d * d - D * D) / (2 * E * d));
	printf("%f", cor1);
	cor1 = cor1 * 180 / 3.14;
	cor2 = cor2 * 180 / 3.14;
	cor = cor1 + cor2;
	return cor;
}
double corA, corB, corC;
void vector(double x,double y) {
  double num;
	nx = -x;
	ny = -y;
	mid_num = sqrt(hz * hz - sqrt(x * x + y * y));
	nz = mid_num * mid_num / hz;
	num = sqrt(nx * nx + ny * ny + nz * nz);
	nx = nx / num;
	ny = ny / num;
	nz = nz / num;

	corA = compute(0, 
		(e / 2) * (1 - ((nx * nx + 3 * nz * nz + 3 * nz) / (nz + 1 - nx * nx)) + (nx * nx * nx * nx - 3 * nx * nx * ny * ny) / ((nz + 1) * (nz + 1 - nx * nx))) + d, 
		hz + e * ny, 
		0, 
		(e / 2) * (1 - ((nx * nx + 3 * nz * nz + 3 * nz) / (nz + 1 - nx * nx)) + (nx * nx * nx * nx - 3 * nx * nx * ny * ny) / ((nz + 1) * (nz + 1 - nx * nx))), 
		hz + e * ny);
	printf("%f", corA);
	corB = compute((sqrt(3) / 2) * (e * (1 - (nx * nx + sqrt(3) * nx * ny) / (nz + 1)) - d), (e * (1 - (nx * nx + sqrt(3) * nx * ny) / (nz + 1)) - d) / 2, hz - (e / 2) * (sqrt(3) * nx + ny), (sqrt(3) / 2) * (e * (1 - (nx * nx + sqrt(3) * nx * ny) / (nz + 1))), (e * (1 - (nx * nx + sqrt(3) * nx * ny) / (nz + 1))) / 2, hz - (e / 2) * (sqrt(3) * nx + ny));
	corC = compute((sqrt(3) / 2) * (d - e * (1 - (nx * nx - sqrt(3) * nx * ny) / (nz + 1))), -1 * (d - e * (1 - (nx * nx - sqrt(3) * nx * ny) / (nz + 1))) / 2, hz - (e / 2) * (-sqrt(3) * nx + ny), (sqrt(3) / 2) * (-e * (1 - (nx * nx - sqrt(3) * nx * ny) / (nz + 1))), (-1 * (d - e * (1 - (nx * nx - sqrt(3) * nx * ny) / (nz + 1))) / 2) + d / 2, hz - (e / 2) * (-sqrt(3) * nx + ny));

}
//  void loop() {
// // 	static int angle = 0;
// // 	static int dir = 10;
// // 	put your main code here, to run repeatedly:
// // 	vector();
// // 	printf("%f",corA);
// // 	Serial.println(corA);
// // 	my.write(corA);
// // 	angle += dir;
// // 	if(angle>=180 || angle <=0) {
// // 	  dir = -dir;
// // 	}
// // 	delay(1000);
// // }
// int main() {
// 	setup();
// 	loop();
// }

#endif