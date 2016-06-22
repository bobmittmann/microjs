//
// Generate the Fibonacci sequence up to the maximum 32 bits signed integer
//

var x0 = 0, x1 = 1;

try {
	var i = 1;
	var x = 0;
	while (1) {
		// Check whether the next sum will overflow or not
		if (0x7fffffff - x1 <= x0) {
			throw 1; // overflow
		}
		x = x1 + x0;
		x0 = x1;
		x1 = x;
		printf("%2d | %10u\n", i, x);
		i = i + 1;
	}
} catch (err) {
	printf(" - overflow error!\n");
}

