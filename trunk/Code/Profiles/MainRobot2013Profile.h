#ifndef MAIN_ROBOT_2013_PROFILE_H
#define MAIN_ROBOT_2013_PROFILE_H

#include "WPILib.h"

#include "../Misc/Ports.h"

#include "BaseRobotProfile.h"

#include "../Subsystems/Drive/DriveSubsystem.h"
#include "../Subsystems/Components/DriveComponents.h"
#include "../Subsystems/Shooter/FrisbeeTurret.h"
#include "../Subsystems/Shooter/FrisbeeLoader.h"
#include "../Subsystems/Shooter/FrisbeeShooter.h"
#include "../Subsystems/Shooter/FrisbeeAimer.h"
#include "../Subsystems/Climber/ClimberJoints.h"


#include "../Commands/DriveCommands.h"
#include "../Commands/ShooterCommands.h"

#include "../Subsystems/Controllers/Axis.h"
#include "../Subsystems/Controllers/XboxController.h"

#include "../OperatorInterfaces/CompetitionOI.h"

/**
 * A profile for a generic robot that simply drives around.
 */
class MainRobot2013Profile : public BaseRobotProfile {
private:
	// Basic Hardware Objects
	SpeedController *m_leftMotor;
	SpeedController *m_rightMotor;
	Tread *m_leftTread;
	Tread *m_rightTread;
	Encoder *m_leftEncoder;
	Encoder *m_rightEncoder;
	
	SpeedController *m_turretHorizontal;
	SpeedController *m_turretVertical;
	Encoder *m_turretHorizontalEncoder;
	Encoder *m_turretVerticalEncoder;
	
	SpeedController *m_shooterFront;
	SpeedController *m_shooterMiddle;
	SpeedController *m_shooterLast;
	
	SpeedController *m_shoulder;
	
	// Subsystems
	BaseDrive *m_drive; 
	BaseFrisbeeLoader *m_loader;
	BaseFrisbeeAimer *m_aimer;
	BaseFrisbeeTurret *m_turret;
	BaseFrisbeeShooter *m_shooter;
	
	// OI
	XboxController *m_xbox;
	Joystick *m_leftStick;
	Joystick *m_rightStick;
	XboxTwoJoysticksOI *m_oi;
	
public:
	MainRobot2013Profile();
	~MainRobot2013Profile();
	
	void CreateBasicHardwareObjects();
	void CreateSubsystems();
	void CreateOI();
	
	void RobotInit();
	void AutonomousInit();
	void TeleopInit();
};

#endif
