#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H
/**
 * \file DriveSubsystem.h
 * 
 * Implements various subsystems related to the drive.
 * 
 * \addtogroup subsystems
 * \{
 * \defgroup drive_subsystems Drive
 * \{
 */

#include <string>

#include "WPILib.h"

#include "../BaseSubsystem.h"
#include "../../Misc/Tools.h"

/**
 * \brief A base drive. All drives must be a subclass of this class.
 * 
 * \warning Note that Holonomic and Mechanum wheel drives are currently
 * not implemented by this interface. 
 * 
 * For the definitions of what these virtual methods are meant to
 * do, please see the WPILib API documentation on the 
 * RobotDrive class. The methods are identical.
 * 
 * Note that all drive systems are enabled upon instantiation.
 */
class BaseDrive : public BaseSubsystem {
public:
	BaseDrive(const char *name);
	virtual ~BaseDrive();
	
	virtual void Drive(float outputMagnitude, float curve) = 0;
	virtual void TankDrive(float leftValue, float rightValue) = 0;
	virtual void TankDrive(float leftValue, float rightValue, bool squaredInputs) = 0;
	virtual void ArcadeDrive(float moveValue, float rotateValue) = 0;
	virtual void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs) = 0;
	virtual void ResetDistanceAndRotation() = 0;
	virtual void TravelDistance(float distanceInInches) = 0;
	virtual void Rotate(float degrees) = 0;
	virtual void Disable() = 0;
	virtual void Enable() = 0;
	virtual void Brake() = 0;
};

/**
 * \brief An interface for any PID-based drive.
 */
class IPidDrive {
public:
	IPidDrive();
	virtual ~IPidDrive();
	virtual void UpdatePidValues() = 0;
	virtual void AdjustRatePid(float lp, float li, float ld, float rp, float ri, float rd) = 0;
	virtual void AdjustDistancePid(float lp, float li, float ld, float rp, float ri, float rd) = 0;
};

/**
 * \brief The absolute simplest drive possible. Contains
 * no PID loops or other forms of feedback systems.
 */
class SimpleDrive : public BaseDrive {
public:
	SimpleDrive(RobotDrive *robotDrive);
	~SimpleDrive();
	
	void Drive(float outputMagnitude, float curve);
	void TankDrive(float leftValue, float rightValue);
	void TankDrive(float leftValue, float rightValue, bool squaredInputs);
	void ArcadeDrive(float moveValue, float rotateValue);
	void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs);
	void ResetDistanceAndRotation();
	void TravelDistance(float distanceInInches);
	void Rotate(float degrees);
	void Disable();
	void Enable();
	void Brake();
	
private:
	RobotDrive *m_robotDrive;
};



/**
 * \brief A varient of an encoder which returns a running average 
 * of the past five values from PIDGet.
 * 
 * Specifically, it returns running average of size `maxSize`
 * when calling PIDGet(). The type (rate or distance) must
 * be specified beforehand by configuring the encoder.
 * 
 * I could have inherited from Encoder, but I wanted to
 * keep it simple. The various config stuff of the 
 * Encoder are exposed through GetEncoder().
 */
class SmoothEncoder : public PIDSource {
public:
	/**
	 * \param[in] encoder A pointer to the encoder
	 * \param[in] maxSize The length of the running average
	 */
	SmoothEncoder(
			Encoder *encoder, 
			unsigned int maxSize,
			Encoder::PIDSourceParameter pidSourceParameter,
			float distancePerPulse);
	virtual ~SmoothEncoder();
	
	/**
	 * \brief Completes the PIDSource interface.
	 * 
	 * Returns the rate or the distance, depending on what
	 * the encoder is set to.
	 */
	double PIDGet();
	/**
	 * \brief Returns a pointer to the internal encoder
	 */
	Encoder *GetEncoder();
	/**
	 * \brief Sets the size of the running average.
	 */
	void SetMaxSize(unsigned int maxSize);
	unsigned int GetMaxSize();
	
	void SetPIDSourceParameter(Encoder::PIDSourceParameter pidSourceParameter);
	Encoder::PIDSourceParameter GetPIDSourceParameter();
	
	void SetDistancePerPulse(float distancePerPulse);
	float GetDistancePerPulse();
	
	void Reset();
	
private:
	Encoder *m_encoder;
	std::deque<double> m_history;
	unsigned int m_maxSize;
	Encoder::PIDSourceParameter m_pidSourceParameter;
	float m_distancePerPulse;
};

/**
 * \brief Represents a single side of the robot drive
 * 
 * Forces the two wheels to spin at the same time.
 */
class Tread : public PIDOutput {
public:
	/**
	 * \brief Specifies the direction the motors should spin to move forwards
	 */
	enum Direction {
		kForward = 1,
		kReversed = -1
	};
	Tread(SpeedController *front, SpeedController *back, Direction direction);
	virtual ~Tread();
	/**
	 * \brief Sets the motor speed
	 */
	void PIDWrite(float output);

	/**
	 * \brief The motor speed
	 */
	float m_last;
private:
	SpeedController *m_front;
	SpeedController *m_back;
	Direction m_direction;
	//TreadPidMode m_currentMode;
};


/**
 * \brief A drive system using PID controllers.
 * 
 * Contains two sets of PID controllers -- one for rate, and another for distance.
 * 
 * \warning The PID loops are not yet well-calibrated, and are buggy.
 * 
 * \warning Not all methods have been implemented
 * 
 * \warning Only the rate PID loops have been calibrated
 */
class PidSimpleDrive : public BaseDrive, public IPidDrive {
public:
	PidSimpleDrive(
			SpeedController *leftFront, 
			SpeedController *leftBack, 
			SpeedController *rightFront,
			SpeedController *rightBack,
			Encoder *leftEncoder,
			Encoder *rightEncoder,
			float leftRateDPP,
			float rightRateDPP,
			float leftDistanceDPP,
			float rightDistanceDPP);
	~PidSimpleDrive();
	
	void Drive(float outputMagnitude, float curve);
	void TankDrive(float leftValue, float rightValue);
	void TankDrive(float leftValue, float rightValue, bool squaredInputs);
	void ArcadeDrive(float moveValue, float rotateValue);
	void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs);
	void ResetDistanceAndRotation();
	void TravelDistance(float distanceInInches);
	void Rotate(float degrees);
	void Disable();
	void Enable();
	void Brake();
	void UpdatePidValues();
	void AdjustRatePid(float lp, float li, float ld, float rp, float ri, float rd);
	void AdjustDistancePid(float lp, float li, float ld, float rp, float ri, float rd);
	
private:
	enum PidMode {
		Rate,
		Distance
	};
	void TryToggling(PidMode mode);
	
	SpeedController *m_leftFront; 
	SpeedController *m_leftBack;
	SpeedController *m_rightFront;
	SpeedController *m_rightBack;
	Encoder *m_leftEncoder;
	Encoder *m_rightEncoder;
	
	SmoothEncoder *m_smoothLeftEncoder;
	SmoothEncoder *m_smoothRightEncoder;
	Tread *m_leftTread;
	Tread *m_rightTread;
	
	PIDController *m_leftPidRate;
	PIDController *m_rightPidRate;
	PIDController *m_leftPidDistance;
	PIDController *m_rightPidDistance;
	
	PidMode m_currentMode;
	
	float m_leftRateDPP;
	float m_rightRateDPP;
	float m_leftDistanceDPP;
	float m_rightDistanceDPP;
};

/**
 * \}
 * \}
 */
#endif
