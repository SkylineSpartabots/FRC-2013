#ifndef COMPETITION_XBOX_OI_H
#define COMPETITION_XBOX_OI_H

#include "WPILib.h"

#include "Xbox.h"
#include "BaseOI.h"
#include "../Commands/DriveCommands.h"
#include "../Commands/ShooterCommands.h"
#include "../Subsystems/Drive/DriveSubsystem.h"
#include "../Subsystems/FrisbeeLoader.h"
#include "../Subsystems/FrisbeeTurret.h"
#include "../Subsystems/FrisbeeShooter.h"
#include "../Subsystems/FrisbeeAimer.h"

/**
 * A simple operator interface using the Xbox Controllers
 */
class CompetitionXboxOI : public BaseOI
{
public:
	CompetitionXboxOI(
			XboxController *xbox, 
			BaseDrive *drive,
			BaseFrisbeeLoader *loader,
			BaseFrisbeeAimer *aimer,
			BaseFrisbeeTurret *turret,
			BaseFrisbeeShooter *shooter);
	~CompetitionXboxOI();
	
	void SetupTeleop();
	TankValues GetTankValues();
	ArcadeValues GetArcadeValues();
	float GetAxis(int axis);
	
private:
	XboxController *m_xbox;
	BaseDrive *m_drive;
	BaseFrisbeeLoader *m_loader;
	BaseFrisbeeAimer *m_aimer;
	BaseFrisbeeTurret *m_turret;
	BaseFrisbeeShooter *m_shooter;
	
	JoystickButton *m_fireButton;
	Command *m_teleopCommand;
	Command *m_loadAndFireCommand;
};

#endif