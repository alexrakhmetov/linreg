#ifndef LINREG_H
#define LINREG_H

/* 
 * Outputs m and b in the formula y = mx + b
 * n is the number of data points.
 * Caller responsible for freeing.
 */
float* linreg(float* xarr, float* yarr, int n)
{
	float* res = malloc(sizeof(float) * 2);
	float xmean = 0;
	for (int i = 0; i < n; i++) {
		xmean += xarr[i];
	}
	xmean /= n;

	float ymean = 0;
	for (int i = 0; i < n; i++) {
		ymean += yarr[i];
	}
	ymean /= n;

	/*
	 * sum1 is the sum of ((x - xmean) * (y - ymean)) for all values 
	 * of x and y. sum2 is the sum of (x - xmean)^2 for 
	 * all values of x.
	 */
	float sum1 = 0;
	float sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += ((xarr[i] - xmean) * (yarr[i] - ymean));
		sum2 += ((xarr[i] - xmean) * (xarr[i] - xmean));
	}
	res[0] = (sum1 / sum2);
	res[1] = (ymean - (xmean * res[0]));
	return res;
}
#endif
