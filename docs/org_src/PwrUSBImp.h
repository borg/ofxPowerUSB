
#ifndef PWRUSBIMP_H__
#define PWRUSBIMP_H__

#define HID_API_EXPORT /**< API export macro */
#define HID_API_CALL /**< API call macro */
#define HID_API_EXPORT_CALL HID_API_EXPORT HID_API_CALL /**< API export and call macro*/

#define POWER_USB_MAXNUM 4

#ifdef __cplusplus
extern "C" {
#endif
// Functions for Version 1 and 2 Firmware PowerUSB. Version 3HID_API_EXPORT_CALL  3 ports read and write
///////////////////////////////////////////////////////////
// Main Power Strip functions
HID_API_EXPORT_CALL int InitPowerUSB(int *model, char firmware[]);
HID_API_EXPORT_CALL int ClosePowerUSB();
HID_API_EXPORT_CALL int SetCurrentPowerUSB(int count); 
HID_API_EXPORT_CALL int CheckStatusPowerUSB();
HID_API_EXPORT_CALL int SetPortPowerUSB(int port1, int port2, int port3);
HID_API_EXPORT_CALL int SetDefaultStatePowerUSB(int state1, int state2, int port3);


// Functions for Version 2 and later Firmware PowerUSB
///////////////////////////////////////////////////////////
// these functions are available starting with Nov 2010 release of PowerUSB
HID_API_EXPORT_CALL int ReadPortStatePowerUSB(int *state1, int *state2, int *state3);	
HID_API_EXPORT_CALL int ReadDefaultPortStatePowerUSB(int *state1, int *state2, int *state3);	
HID_API_EXPORT_CALL int GetFirmwareVersionPowerUSB(char firmware[]);
HID_API_EXPORT_CALL int GetModelPowerUSB();

// Current sensing and Read Functions
////////////////////////////////////
HID_API_EXPORT_CALL int ReadCurrentPowerUSB(int *current);
HID_API_EXPORT_CALL int ReadCurrentCumPowerUSB(int *currentCum);
HID_API_EXPORT_CALL int ResetCurrentCounterPowerUSB();
HID_API_EXPORT_CALL int SetCurrentSensRatioPowerUSB(int currentRatio);
HID_API_EXPORT_CALL int SetOverloadPowerUSB(int overload);
HID_API_EXPORT_CALL int GetOverloadPowerUSB();
HID_API_EXPORT_CALL int ResetBoard();
HID_API_EXPORT_CALL int SetCurrentOffset();

// Digital IO functions. Available only when Digital IO model of PowerUSB is connected
////////////////////////////////////
HID_API_EXPORT_CALL int SetIODirectionPowerUSB(int direction[]);
HID_API_EXPORT_CALL int SetOutputStatePowerUSB(int output[]);
HID_API_EXPORT_CALL int GetInputStatePowerUSB(int input[]);
HID_API_EXPORT_CALL int GetInputStateBytePowerUSB(unsigned char *input);
HID_API_EXPORT_CALL int GenerateClockPowerUSB(int port, int onTime, int offTime);
HID_API_EXPORT_CALL int GetOutputStatePowerUSB(int output[]);
HID_API_EXPORT_CALL int SetInputTriggerPowerUSB(int input, int fallingSignal, int outlet, int output, int outTime, char cond, char mask);
HID_API_EXPORT_CALL int SetPLCPowerUSB(int state);
HID_API_EXPORT_CALL int GetPLCPowerUSB(int *state);
HID_API_EXPORT_CALL int ClearPLCPowerUSB();

// Watchdog related functions. Available only for Watchdog firmware version of the PowerUSB
//////////////////////////////////////////////////////////////////////////////////////////////
HID_API_EXPORT_CALL int StartWatchdogTimerPowerUSB(int HbTimeSec, int numHbMisses, int resetTimeSec);
HID_API_EXPORT_CALL int StopWatchdogTimerPowerUSB();
HID_API_EXPORT_CALL int GetWatchdogStatusPowerUSB();		// returns 0=IDLE(off), 1=Running, 2=Resetting
HID_API_EXPORT_CALL int SendHeartBeatPowerUSB();
HID_API_EXPORT_CALL int PowerCyclePowerUSB(int resetTimeSec);
HID_API_EXPORT_CALL int ShutdownOffOnPowerUSB(int offDelay, int onDelay);

// SMART Model related Functions
////////////////////////////////////////////////////////////////////////////////////////////////
HID_API_EXPORT_CALL int SetOnOffTimesPowerUSB(int port, int wkDayChunks[], int wkEndChunks[]);
HID_API_EXPORT_CALL int GetOnOffTimesPowerUSB(int port, int wkDayChunks[], int wkEndChunks[]);
HID_API_EXPORT_CALL int SetOnOffFrequencyPowerUSB(int port, int offset, int onTime, int offTime);
HID_API_EXPORT_CALL int SetOnOffModePowerUSB(int port, int mode);
HID_API_EXPORT_CALL int SetModePowerUSB(int mode);
HID_API_EXPORT_CALL int SetTVLimitPowerUSB(int wkDayLimit, int wkEndLimit);
HID_API_EXPORT_CALL int SetDateAndTimePowerUSB(unsigned char timeStr[]);
HID_API_EXPORT_CALL int DisplayTextPowerUSB(char text[]);
HID_API_EXPORT_CALL int SetPasswordPowerUSB(char pass[]);

#ifdef __cplusplus
}
#endif

#endif
