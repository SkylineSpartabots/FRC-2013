#ifndef TESTBED_ROBOT_2013_PROFILE_H
#define TESTBED_ROBOT_2013_PROFILE_H

#include "WPILib.h"

#include "../Misc/Ports.h"

#include "BaseRobotProfile.h"
#include "../OperatorInterfaces/XboxOI.h"
#include "../OperatorInterfaces/Xbox.h"
#include "../Subsystems/Drive/DriveSubsystem.h"
#include "../Subsystems/Drive/DriveTransmission.h"


class TestbedRobot2013Profile : public BaseRobotProfile {
private:
	// Basic Hardware Objects
	RobotDrive *m_robotDrive;
	XboxController *m_xbox;
	Compressor *m_compressor;
	
	// Subsystems
	BaseDrive *m_drive;
	
	// Operator Interfaces
	XboxOI *m_OI;
	
public:
	TestbedRobot2013Profile();
	~TestbedRobot2013Profile();
	
	void CreateBasicHardwareObjects();
	void CreateSubsystems();
	void CreateOI();
	
	void RobotInit();
	void AutonomousInit();
	void TeleopInit();
};

#endif
