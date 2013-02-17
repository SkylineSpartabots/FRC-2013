#ifndef SHOOTER_COMMANDS_H
#define SHOOTER_COMMANDS_H

#include "WPILib.h"
#include "../Misc/Tools.h"
#include "BaseCommand.h"

#include "../Subsystems/Shooter/FrisbeeAimer.h"
#include "../Subsystems/Shooter/FrisbeeLoader.h"
#include "../Subsystems/Shooter/FrisbeeShooter.h"
#include "../Subsystems/Shooter/FrisbeeTurret.h"

#include "../Subsystems/Controllers/Axis.h"

/**
 * \brief Command for loading frisbees.
 */
class LoadFrisbeeCommand : public Command {
public:
	LoadFrisbeeCommand(BaseFrisbeeLoader *loader);
	~LoadFrisbeeCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	BaseFrisbeeLoader *m_loader;
	bool m_isFinished;
};

/**
 * \brief Aims the turret at the given target
 * 
 * Protip: If you set this to the default turret command, using
 * 
 * 	   Tracking::ClosestOffset
 * 	   
 * ...as the desiredTarget param, the turret will automatically
 * lock on and track the target it's pointing at.
 * 
 * You can manually adjust the target to point at a different target,
 * or issue a command to point it at the appropriate target and let
 * this take over once that command is finished.
 */
class AimTurretCommand : public Command {
public:
	AimTurretCommand(
			BaseFrisbeeAimer *aimer, 
			BaseFrisbeeTurret *turret, 
			Tracking::TargetType desiredTarget, 
			float allowedRange);
	~AimTurretCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	BaseFrisbeeAimer *m_aimer;
	BaseFrisbeeTurret *m_turret;
	bool m_isFinished;
	Tracking::TargetType m_desiredTarget;
	float m_allowedRange;
};

/**
 * \brief Fires the frisbee at a default distance or a set distance.
 */
class FireFrisbeeCommand : public Command {
public:
	FireFrisbeeCommand(BaseFrisbeeShooter *shooter);
	~FireFrisbeeCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
		
private:
	BaseFrisbeeShooter *m_shooter;
};

/**
 * \brief Lightly ejects frisbee.
 */
class EjectFrisbeeCommand : public SimpleCommand {
public:
	EjectFrisbeeCommand(BaseFrisbeeShooter *shooter);
	~EjectFrisbeeCommand();
	void Execute();
		
private:
	BaseFrisbeeShooter *m_shooter;
};

/**
 * \brief Loads a frisbee, aims the turret, and fires it.
 */
class LoadAndFireCommand : public CommandGroup {
public:
	LoadAndFireCommand(
		BaseFrisbeeLoader *loader, 
		BaseFrisbeeAimer *aimer, 
		BaseFrisbeeTurret *turret, 
		BaseFrisbeeShooter *shooter);
	~LoadAndFireCommand();
};

/**
 * \brief Manually adjusts where the turret is pointing using two joystick axis
 */
class AdjustTurretCommand : public Command {
public:
	AdjustTurretCommand(
			BaseFrisbeeTurret *turret,
			double rotateOffset,
			double verticalOffset, 
			float allowedRange);
	~AdjustTurretCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	BaseFrisbeeTurret *m_turret;
	double m_rotateOffset;
	double m_verticalOffset;
	float m_allowedRange;
	bool m_isFinished;
};


class ManuallyControlTurretCommand : public SimpleCommand {
public:
	ManuallyControlTurretCommand(BaseFrisbeeTurret *turret, Axis *verticalAxis, Axis *rotateAxis);
	~ManuallyControlTurretCommand();
	void Execute();
	
private:
	BaseFrisbeeTurret *m_turret;
	Axis *m_verticalAxis;
	Axis *m_rotateAxis;
};

#endif
