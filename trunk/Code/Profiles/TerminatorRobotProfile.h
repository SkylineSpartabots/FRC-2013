#ifndef TERMINATOR_ROBOT_PROFILE_H
#define TERMINATOR_ROBOT_PROFILE_H

#include "WPILib.h"

#include "../Misc/Ports.h"

#include "BaseRobotProfile.h"
#include "../OperatorInterfaces/TestEncoderOI.h"
#include "../OperatorInterfaces/Xbox.h"
#include "../Subsystems/Experimental.h"

/**
 * A profile for the Terminator robot.
 */
class TerminatorRobotProfile : public BaseRobotProfile {
private:
	// Basic Hardware Objects
	SpeedController *m_leftFrontMotor;
	SpeedController *m_leftBackMotor;
	SpeedController *m_rightFrontMotor;
	SpeedController *m_rightBackMotor;
	RobotDrive *m_robotDrive;
	XboxController *m_xbox;
	Encoder *m_leftEncoder;
	Encoder *m_rightEncoder;
	SpeedController *m_testSpeedController;
	
	// Subsystems
	BaseDrive *m_drive; 
	TestEncoder *m_leftTestEncoder;
	TestEncoder *m_rightTestEncoder;
	TestMotor *m_testMotor;
	
	// Operator Interfaces
	BaseOI *m_OI;
	
public:
	TerminatorRobotProfile();
	~TerminatorRobotProfile();
	
	void CreateBasicHardwareObjects();
	void CreateSubsystems();
	void CreateOI();
	
	void RobotInit();
	void AutonomousInit();
	void TeleopInit();
};

#endif
