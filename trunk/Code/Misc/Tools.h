#ifndef TOOLS_H
#define TOOLS_H

namespace Tools {
	enum Units {
		Inches,
		Feet,
		Meters,
		Centimeters
	};
	
	/**
	 * Converts number in the START unit to the TARGET unit.
	 */
	float ConvertUnits(float value, Units start, Units target);
	
	/**
	 * Makes sure that a number lies between the range 
	 * [lowLimit] and [highLimit]. If not, it forces it to 
	 * conform to that range.
	 */
	float Limit(float value, float lowLimit, float highLimit);
	
	/**
	 * Scales a value from the range [inputStart, inputEnd] to the range 
	 * [outputStart, outputEnd]
	 */
	float Scale(float value, float inputStart, float inputEnd, float outputStart, float outputEnd);
}

#endif
