#ifndef FRISBEE_TURRET_H
#define FRISBEE_TURRET_H

#include "WPILib.h"

#include "BaseSubsystem.h"
#include "FrisbeeAimer.h"

/**
 * Base class for a frisbee turret. Responsible for aiming the 
 * shooter at a certain angle.
 * 
 * Note: this interface may change substantially over time.
 */
class BaseFrisbeeTurret : public BaseSubsystem {
public:
	BaseFrisbeeTurret(const char *name);
	virtual ~BaseFrisbeeTurret();
	
	virtual void TurnHorizontal(float degrees) = 0;
	virtual void TurnVertical(float degrees) = 0;
	virtual void TurnGivenOffset(Offset offset) = 0;
	virtual Offset ReportCurrentOffset() = 0;
};
/*
class SimpleFrisbeeTurret : public BaseFrisbeeTurret {
public:
	SimpleFrisbeeTurret(SpeedController *HorizontalMotor, SpeedController *LateralMotor);
	~SimpleFrisbeeTurret();
	
	void TurnHorizontal(float degrees);
	void TurnVertical(float degrees);
};
*/
/**
 * A class which controllers the shooter turret using
 * a PID loop. 
 * 
 * Assumes that the encoders will return 360 pulses
 * given a full rotation. The encoders must be 
 * calibrated before being passed into this class.
 */
/*class PidFrisbeeTurret : public BaseFrisbeeTurret {
public:
	PidFrisbeeTurret(
			SpeedController *horizontalMotor, 
			SpeedController *verticalMotor,
			Encoder *horizontalEncoder,
			Encoder *verticalEncoder);
	~PidFrisbeeTurret();
	
	void TurnHorizontal(float degrees);
	void TurnVertical(float degrees);
	void TurnGivenOffset(Offset offset);
	Offset ReportCurrentOffset();
	
private:
	Offset m_offset;
	SpeedController *m_horizontalMotor;
	SpeedController *m_verticalMotor;
	Encoder *m_verticalEncoder;
	Encoder *m_horizontalEncoder;
	
	PIDController *m_horizontalPid;
	PIDController *m_verticalPid;
};
*/

#endif
